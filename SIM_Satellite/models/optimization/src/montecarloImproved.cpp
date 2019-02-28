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

  runsPerGainValueSet = 100;
  //mc_add_slave("joey-VirtualBox");
  // maybe do different input files? for different generations?
  //structure of text file is : (runNumber, kp,ki,kd)
  //fprintf(fp, "%15d %15.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.overallRank);
  /*std::string filename;
  if(generation >0)
  {

    filename = "Modified_Data/gen" + std::to_string(generation) + ".csv";
  }
  fp = fopen(filename.c_str(),"r");
  //declare variables, all are throwaway except k's and rank

  float kp,ki,kd,rank;
  while(fscanf(fp, "%*d %f %f %f %*d %*d %f",&kp,&ki,&kd,&rank) != EOF)
  {
    printf ("%15f %15.5f %15.5f %15.5f", kp,ki,kd,rank);
  }*/








  //change run number based on what u put in ur monte.py input file, this is essential!!!
  timeToSwitchGain = false;

  //satelliteArray [20]; //20 is the amount of runs.




  int counter;
  mc_set_num_runs(1000);
  for(double p = 4.5;p <= 5; p+=.5)
  {

    for(double d = .5; d<= 5; d+=.5)
    {

      for(double i = .1; i <= 1; i+=.1)
      {
        counter++;
        placeholderForPIDVector.setKValues(p,i,d,counter);
        storage.push_back(placeholderForPIDVector);
        placeholderForScoreVector.setGainValues(p,i,d,counter);
        scoreArray.push_back(placeholderForScoreVector);
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

  for(PID p: storage)
  {

  //  if(p.kP == run_satellite.pid.kP&&p.kI == run_satellite.pid.kI&&p.kD == run_satellite.pid.kD) //run through storage to find the right run
  if(p.runneth == run_satellite.pid.runneth)
    {
    if(p.runneth>10)//optimize runtime by making it only look near relevant runs
    {
      for(int x = (p.runneth-5); x < scoreArray.size(); x++)
      {
        if(scoreArray[x].runNumber == p.runneth)//run through scoreArray to find the right score to add final stuff to.
        {
         scoreArray[x].addTimeAndPO(run_satellite.finalSettlingTime,run_satellite.finalPercentOvershoot);
         //printf("RUN NUMBER:: %15i, SETTLING:: %15.5f, PO:: %15.5f \n", scoreArray[x].runNumber, run_satellite.finalSettlingTime,run_satellite.finalPercentOvershoot);
        //printf("\n(kp,ki,kd):: (%5.5f,%5.5f,%5.5f) || (kp,ki,kd):: (%5.5f,%5.5f,%5.5f)\n", scoreArray[x].kP,scoreArray[x].kI,scoreArray[x].kD, p.kP,p.kI,p.kD);

        }
      }
    }
    else
    {
      for(int x = 0; x < scoreArray.size(); x++)
      {
        if(scoreArray[x].runNumber == p.runneth)//run through scoreArray to find the right score to add final stuff to.
        {
         scoreArray[x].addTimeAndPO(run_satellite.finalSettlingTime,run_satellite.finalPercentOvershoot);
         //printf("RUN NUMBER:: %15i, SETTLING:: %15.5f, PO:: %15.5f \n", scoreArray[x].runNumber, run_satellite.finalSettlingTime,run_satellite.finalPercentOvershoot);
        //printf("\n(kp,ki,kd):: (%5.5f,%5.5f,%5.5f) || (kp,ki,kd):: (%5.5f,%5.5f,%5.5f)\n", scoreArray[x].kP,scoreArray[x].kI,scoreArray[x].kD, p.kP,p.kI,p.kD);

        }
    }
  }


    }
  }
  satelliteArray.push_back(run_satellite) ;



  return 0;
}
int monte::satellite_slave_pre(Satellite*S)
{

  return 0;
}

int monte::satellite_master_pre(Satellite* S)
{
printf("15.5%d", generation);
runCounter = mc_get_current_run()+1;
  if(fmod(runCounter-1,runsPerGainValueSet) ==0 && (runCounter-1) !=0)
  {
    S->pid.setKValues(storage[runCounter/runsPerGainValueSet].kP,storage[runCounter/runsPerGainValueSet].kI,storage[runCounter/runsPerGainValueSet].kD,storage[runCounter/runsPerGainValueSet].runneth );
    }

  printf("%5i\n",runCounter);


  return 0;

}


int monte::satellite_master_shutdown(Satellite* S)
{
  for(int x = 0; x < scoreArray.size(); x++)
  {
    printf("%15.5f, %15.5f ", scoreArray[x].meanSettlingTime, scoreArray[x].meanPercentOvershoot );
   scoreArray[x].setScoreParameters();
  }
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
	fp = fopen("Modified_Data/gen1.csv", "w");
  for(Satellite p :satelliteArray)
  {
    Satellite* f = &p;
    p.satellite_printState(f);
  }
  //some printing stuff..
  for(Score s : scoreArray)
  {
    if(s.meanPercentOvershoot >0)
    {
    s.printScore();
	fprintf(fp, "%15d %15.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.overallRank);
}
  }




}
