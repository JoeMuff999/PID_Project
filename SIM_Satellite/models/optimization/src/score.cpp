/*
PURPOSE: (record satelliteasdfpercent overshoot for sdcoring)

Library dependency:
	((score.o))
*/
#include <iostream>
#include "../models/optimization/include/score.h"

void Score::setGainValues(double p,double i, double d)
{

  kP = p;
  kI = i;
  kD = d;
}

void Score::setScoreParameters(double thyme, double overshoot)
{
  meanSettlingTime = thyme;
  meanPercentOvershoot = overshoot;
}
void Score::printScore()
{
  printf("\nSatellite Score:: <kP, kI, kD>, <Mean Ts98, Mean Overshoot> :: <%.9f,%.9f,%.9f> , <%.9f,%.9f> ", kP,kI,kD,meanSettlingTime,meanPercentOvershoot);
}
