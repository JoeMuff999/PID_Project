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
  double percentageToKeep = .2; //how many runs I want to keep for each generation
  int setsToRun = 1800; //currently 3600 is all
  timeToSwitchGain = false;
  runsPerGainValueSet = 1;
  int numRuns = setsToRun *runsPerGainValueSet;
  mc_set_num_runs(numRuns);
  //mc_add_slave("joey-VirtualBox")

  if(generation ==0)
  {
    int counter=0;

    for(double p = 5.527;p < 10.265; p+=.07896)// p (double p = 631.655;p < 947.496; p+=7.896)
    {

      for(double d = 175.932; d< 326.7316; d+=2.5133) //+-20%, 1% increments d = (double d = 2010.619; d< 3015.940; d+=25.133)
    {

      //  for(double i = .1; i <= 1; i+=.1)
      //  {
          double i = 1;
          counter++;
          placeholderForPIDVector.setKValues(p,i,d, counter);
          storage.push_back(placeholderForPIDVector);
          placeholderForScoreVector.setGainValues(p,i,d,counter);
          scoreArray.push_back(placeholderForScoreVector);

          if(counter ==1)
          {//fix for 0,0,0 k values :)
            S->pid.setKValues(storage[0].kP,storage[0].kI,storage[0].kD, storage[0].runneth);

          }
          //double break because c++ doesnt break nested for loops
          if(counter*runsPerGainValueSet == numRuns)
          {
            std::cout << "counter, numRuns"<< counter << "   "<< numRuns;
            break;
          }



      }
      if(counter*runsPerGainValueSet == numRuns)
      {
        std::cout << "counter, numRuns"<< counter << "   "<< numRuns;
        break;
      }
    }

  }
  else {
    int counter=0;
    double runsInFile=0; //this counter will find how many runs are in the text file, which i will use to determine top percent runs
    float kp,ki,kd,rank;
    std::string filename;
    filename = "Modified_Data/gen" + std::to_string(generation-1) + ".csv";
    fp = fopen(filename.c_str(),"r");
    while(fscanf(fp, "%*d %f %f %f %*f %*f %f ",&kp,&ki,&kd,&rank) !=EOF)
    {

      runsInFile++;
    }
    int counterForOptimizing = 0;
    double keepAmount = runsInFile*percentageToKeep; //calculate how many runs to keep;
    std::cout << keepAmount;
    rewind(fp);
    while(fscanf(fp, "%*d %f %f %f %*f %*f %f ",&kp,&ki,&kd,&rank) !=EOF && (counterForOptimizing < keepAmount) )
    {
      for(int x = 0; x < runsInFile/(int)keepAmount; x++)
      {

        counter++;
        placeholderForPIDVector.setKValues(kp+(x/2),ki+(x/10),kd+(x/2),counter);
        storage.push_back(placeholderForPIDVector);

        placeholderForScoreVector.setGainValues(kp+(x/2),ki+(x/10),kd+(x/2),counter);
        scoreArray.push_back(placeholderForScoreVector);
        if(counter ==1)
        {//fix for 0,0,0 k values :)
          S->pid.setKValues(storage[0].kP,storage[0].kI,storage[0].kD, storage[0].runneth);
        }
      }
      counterForOptimizing++;
    }
  }
  //change run number based on what u put in ur monte.py input file, this is essential!!!
  //satelliteArray [20]; //20 is the amount of runs.
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
//printf("%15.5d", generation);
runCounter = mc_get_current_run()+1;
  if(fmod(runCounter-1,runsPerGainValueSet) ==0 && (runCounter-1) !=0)
  {
    S->pid.setKValues(storage[runCounter/runsPerGainValueSet].kP,storage[runCounter/runsPerGainValueSet].kI,storage[runCounter/runsPerGainValueSet].kD,storage[runCounter/runsPerGainValueSet].runneth );
    }

//  printf("%5i\n",runCounter);


  return 0;

}


int monte::satellite_master_shutdown(Satellite* S)
{
  for(int x = 0; x < scoreArray.size(); x++)
  {
    //printf("%15.5f, %15.5f ", scoreArray[x].meanSettlingTime, scoreArray[x].meanPercentOvershoot );
   scoreArray[x].setScoreParameters();
  }
//sort by ts98
  for(int i = 0; i < scoreArray.size(); i++)
  {
    if(scoreArray[i].meanPercentOvershoot <0){
      std::cout << "this array will be deleted right?"<< i;
    scoreArray.erase(scoreArray.begin() + i -1);
    scoreArray[i].meanPercentOvershoot = 10000000000;}
  }
  for(int i = 0; i < scoreArray.size(); i++)
  {
    Score s = scoreArray[i];
    //printf("AHHHHHHHHHHHHHHH%15d %15.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.overallRank);
  }
  std::sort(scoreArray.begin(),scoreArray.end(),comparerSettlingTime());
//give rank for ts98
  for(int i = 0; i < scoreArray.size(); i++)
  {
    if(scoreArray[i].meanPercentOvershoot >0)
    {
    scoreArray[i].settlingTimeRank = i;
    }

  }
  //print settling time independently
  std::string tsfile;
  tsfile = "Modified_Data/settlingtime.csv";
	fp = fopen(tsfile.c_str(), "w");
  for(Score s : scoreArray)
  {
    if(s.meanSettlingTime >0)
    {
    s.printScore();
  fprintf(fp, "%15d %15.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.settlingTimeRank);
}
  }

  std::sort(scoreArray.begin(),scoreArray.end(),comparerPercentOvershoot());
  for(int i = 0; i < scoreArray.size(); i++)
  {
    scoreArray[i].percentOvershootRank = i;
    scoreArray[i].overallRank = (scoreArray[i].percentOvershootRank +  scoreArray[i].settlingTimeRank)/2;
  }
  std::sort(scoreArray.begin(),scoreArray.end(),comparerOverallRank());
//making file
  std::string filename;
  filename = "Modified_Data/gen" + std::to_string(generation) + ".csv";

	//double totalMeanSettlingTime = totalSettlingTime/(scoreArray.size()*runsPerGainValueSet); for scoring, this is the average.
	fp = fopen(filename.c_str(), "w");
  for(Satellite p :satelliteArray)
  {
    Satellite* f = &p;
    p.satellite_printState();
  }
  //some printing stuff..
  for(Score s : scoreArray)
  {
    if(s.meanPercentOvershoot >0)
    {
    //s.printScore();
	fprintf(fp, "%15d %15.5f %15.5f %15.5f %15.5f %15.5f %15.5f\n", s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.overallRank);
}
  }




}
