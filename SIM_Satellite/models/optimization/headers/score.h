/*
PURPOSE: (record satellite settling time and max percent overshoot for sdcoring)
*/
#ifndef SCORES_H
#define SCORES_H
#include <cstdio>
#include <vector>
#include <iostream>

class Score {
public:
 double kP;
  double kI;
 double kD;
  double meanSettlingTime;
  double meanPercentOvershoot;

  void setGainValues(double,double,double);

  void printScore();
    void setScoreParameters(double,double);//time then overshoot :)
};
#endif
