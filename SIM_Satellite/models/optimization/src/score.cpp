/*
PURPOSE: (record satelliteasdfpercent overshoot for sdcoring)

Library dependency:
	((score.o))
*/
#include <iostream>
#include "../models/optimization/include/score.h"

void Score::setGainValues(double p,double i, double d, int run)
{

  kP = p;
  kI = i;
  kD = d;
	runNumber = run;
}

void Score::setScoreParameters()
{
  meanSettlingTime= meanSettlingTime/runsPGVS;
  meanPercentOvershoot = meanPercentOvershoot/runsPGVS;
}
void Score::addTimeAndPO(double thyme, double overshoot)
{
  if(thyme == 0){}
  else{
    runsPGVS++; // dont include 0 as a valid run
  }

  meanSettlingTime+=thyme;
  meanPercentOvershoot+=overshoot;
}
void Score::printScore()
{
  printf("\nSatellite Score:: <kP, kI, kD>, <Mean Ts98, Mean Overshoot> :: <%.9f,%.9f,%.9f> , <%.9f,%.9f> ", kP,kI,kD,meanSettlingTime,meanPercentOvershoot);
}
