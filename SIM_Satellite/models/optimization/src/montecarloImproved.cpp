/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)


*/

#include "../models/ISS/headers/satellite.h"
#include "../include/montecarloImproved.h"
#include "../include/score.h"
#include "../include/settlingTimeComparer.h"
#include "../include/percentOvershootComparer.h"
#include "../include/overallRankComparer.h"
#include "sim_services/MonteCarlo/include/montecarlo_c_intf.h"
#include <math.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int monte::satellite_slave_post(Satellite* S)
{

   mc_write((char*) S, sizeof(Satellite));
  return 0;
}
int monte::satellite_master_init(Satellite* S)
{

  //mc_add_slave("joey-VirtualBox");


  //change run number based on what u put in ur monte.py input file, this is essential!!!
  timeToSwitchGain = false;

  //satelliteArray [20]; //20 is the amount of runs.
  int counter;
  mc_set_num_runs(100);
  runsPerGainValueSet = 10;
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

  static double totalSettlingTime;
	static double totalPercentOvershoot;

  static double settlingTimePerGainValueSet; //for averaging each gain value set

  settlingTimePerGainValueSet += run_satellite.finalSettlingTime;
  totalSettlingTime+= run_satellite.finalSettlingTime;//for getting averaging all runs for future scoring

  static double percentOvershootPerGainValueSet;


  percentOvershootPerGainValueSet += run_satellite.finalPercentOvershoot;
  totalPercentOvershoot += run_satellite.finalPercentOvershoot;
  //printf("settling time : %.9f", totalSettlingTime);

  static double runCounterForPost;
  satelliteArray.push_back(run_satellite) ;
  runCounterForPost+=1;
  if(fmod(runCounter,runsPerGainValueSet) == 0)
  {
//Setting score vector place holders then adding to vector
  placeholderForScoreVector.setScoreParameters(settlingTimePerGainValueSet/runsPerGainValueSet, percentOvershootPerGainValueSet/runsPerGainValueSet);
 placeholderForScoreVector.setGainValues( S->pid.kP,S->pid.kI,S->pid.kD, runCounterForPost/runsPerGainValueSet);

  scoreArray.push_back(placeholderForScoreVector);
   timeToSwitchGain = true;

   settlingTimePerGainValueSet = 0;//reset for next gain value set
   percentOvershootPerGainValueSet = 0;
   }

  return 0;
}
int monte::satellite_slave_pre(Satellite*S)
{

  static int counter;
  int f = getRuns();
  if(f&runsPerGainValueSet ==0)
  {

    S->pid.setKValues(storage[counter].kP,storage[counter].kI,storage[counter].kD );

    //printf("(P,I,D): %.9f,%.9f,%.9f",storage[counter].kP,storage[counter].kI,storage[counter].kD);
    counter+=1;
    std::cout << "YO THIS SHIT IS TRUE";
    timeToSwitchGain = false;
  }

  std::cout << "YO THIS IS THE NUMBER OF RUNS" << f; //prints to stdout
  return 0;
}

int monte::satellite_master_pre(Satellite* S)
{

  runCounter++;
  setRuns(runCounter);
  printf("%5i\n LOOOOL",runCounter);


  return 0;

}
void monte::setRuns(int x)
{
  runCounter = x;
}
int monte::getRuns()
{
  return runCounter ;
}

int monte::satellite_master_shutdown(Satellite* S)
{
//sort by ts98
  std::sort(scoreArray.begin(),scoreArray.end(),comparerSettlingTime());
//give rank for ts98
  for(int i = 0; i < scoreArray.size(); i++)
  {
    scoreArray[i].settlingTimeRank = i;
  }
  std::sort(scoreArray.begin(),scoreArray.end(),comparerPercentOvershoot());
  for(int i = 0; i < scoreArray.size(); i++)
  {
    scoreArray[i].percentOvershootRank = i;
    scoreArray[i].overallRank = (scoreArray[i].percentOvershootRank +  scoreArray[i].settlingTimeRank)/2;
  }
  std::sort(scoreArray.begin(),scoreArray.end(),comparerOverallRank());

	//double totalMeanSettlingTime = totalSettlingTime/(scoreArray.size()*runsPerGainValueSet); for scoring, this is the average.
	fp = fopen("Modified_Data/hmm.csv", "w");
  for(Satellite p :satelliteArray)
  {
    Satellite* f = &p;
    p.satellite_printState(f);
  }
  //some printing stuff..
  for(Score s : scoreArray)
  {
    s.printScore();
	fprintf(fp, "%15d %15.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.overallRank);
  }




}
