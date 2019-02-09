/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/

#include "../models/ISS/headers/satellite.h"
#include "../headers/montecarlo.h"
#include "sim_services/MonteCarlo/include/montecarlo_c_intf.h"

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
  S->pid.setKValues(0,0,0);
  for(double p = 4.5;p <= 5; p+=.5)
  {

    for(double d = .5; d<= 5; d+=.5)
    {

      for(double i = .5; i <= 5; i+=.5)
      {

        storage[counter].setKValues(p,i,d); //each storage[x] will be a new set of gain values.
        counter++;

      }
    }
  }

  return 0;
}
int monte::satellite_master_post(Satellite* S)
{

  Satellite run_satellite;
  mc_read((char*) &run_satellite, sizeof(Satellite));

  static double totalSettlingTime;
  totalSettlingTime+= run_satellite.finalSettlingTime;
  //printf("settling time : %.9f", totalSettlingTime);

  static int runCounter;
  satelliteArray [runCounter] = run_satellite;
  runCounter+=1;
  if(runCounter%runsPerGainValueSet == 0)
  {
   timeToSwitchGain = true;
   totalSettlingTime = 0;


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
}
