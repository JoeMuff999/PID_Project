/*
PURPOSE: (record ssdfd max percent overshoot for sdcoring)
Library dependency:
	((score.o))
*/
#ifndef SCORE_H
#define SCORE_H
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
	int runNumber;

  double settlingTimeRank;
  double percentOvershootRank;
  double overallRank;

  void setGainValues(double,double,double,int);
  void setScoreParameters(double,double);
  void printScore();
};
#endif
