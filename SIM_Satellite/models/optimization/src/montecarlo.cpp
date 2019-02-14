/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/

#include "../models/ISS/headers/satellite.h"
#include "../headers/montecarlo.h"
#include "../models/optimization/src/score.cpp"

#include "sim_services/MonteCarlo/include/montecarlo_c_intf.h"
#include <math.h>
int monte::satellite_slave_post(Satellite* S)
{

   mc_write((char*) S, sizeof(Satellite));
  return 0;
}
int monte::satellite_master_init(Satellite* S)
{
  //change run number based on what u put in ur monte.py input file, this is essential!!!
  timeToSwitchGain = false;

  //satelliteArray [20]; //20 is the amount of runs.
  int counter;
  runsPerGainValueSet = 5;
  S->pid.setKValues(1,1,1);
  for(double p = 4.5;p <= 5; p+=.5)
  {

    for(double d = .5; d<= 5; d+=.5)
    {

      for(double i = .1; i <= 1; i+=.1)
      {
        placeholderForPIDVector.setKValues(p,i,d);
        storage.push_back(placeholderForPIDVector);
        //storage[counter].setKValues(p,i,d); //each storage[x] will be a new set of gain values.
        //counter++;

      }
    }
  }

  return 0;
}
int monte::satellite_master_post(Satellite* S)
{

  Satellite run_satellite;
  mc_read((char*) &run_satellite, sizeof(Satellite));
  static double settlingTimePerGainValueSet; //for averaging each gain value set
  static double totalSettlingTime; //for getting averaging all runs for future scoring
  settlingTimePerGainValueSet += run_satellite.finalSettlingTime;
  totalSettlingTime+= run_satellite.finalSettlingTime;

  static double percentOvershootPerGainValueSet;
  static double totalPercentOvershoot;

  percentOvershootPerGainValueSet += run_satellite.finalPercentOvershoot;
  totalPercentOvershoot += run_satellite.finalPercentOvershoot;
  //printf("settling time : %.9f", totalSettlingTime);

  static double runCounter;
  satelliteArray.push_back(run_satellite) ;
  runCounter+=1;
  if(fmod(runCounter,runsPerGainValueSet) == 0)
  {
//Setting score vector place holders then adding to vector
  placeholderForScoreVector.setScoreParameters(settlingTimePerGainValueSet/runsPerGainValueSet, percentOvershootPerGainValueSet/runsPerGainValueSet);
 placeholderForScoreVector.setGainValues(S->pid.kP,S->pid.kI,S->pid.kD);

  scoreArray.push_back(placeholderForScoreVector);
   timeToSwitchGain = true;
   settlingTimePerGainValueSet = 0;//reset for next gain value set
   percentOvershootPerGainValueSet = 0;
   }

  return 0;
}

int monte::satellite_master_pre(Satellite* S)
{

  static int counter;
  if(timeToSwitchGain)
  {
    S->pid.setKValues(storage[counter].kP,storage[counter].kI,storage[counter].kD );

    //printf("(P,I,D): %.9f,%.9f,%.9f",storage[counter].kP,storage[counter].kI,storage[counter].kD);
    counter+=1;
    timeToSwitchGain = false;
  }


  return 0;

}

int monte::satellite_master_shutdown(Satellite* S)
{
  for(Satellite p :satelliteArray)
  {
    Satellite* f = &p;
    p.satellite_printState(f);
  }
  for(Score s : scoreArray)
  {
    s.printScore();
  }
}
