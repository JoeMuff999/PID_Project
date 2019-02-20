/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/
#ifndef MONTEIMPROVED_H
#define MONTEIMPROVED_H
#include <cstdio>
#include <vector>
#include "../models/ISS/headers/satellite.h"
#include "../models/Controllers/headers/pid.h"
#include "../models/optimization/include/score.h"
#include "score.h"


class monte {
public:
  std::vector<Score> scoreArray;
  std::vector<Satellite> satelliteArray;
  std::vector<PID> storage;

  Score placeholderForScoreVector;
  PID placeholderForPIDVector;

  double runsPerGainValueSet;
  bool timeToSwitchGain;
  int runCounter;

	//static double totalSettlingTime;
	//static double totalPercentOvershoot;

	FILE* fp;


  int satellite_slave_post(Satellite*);
  int satellite_master_post(Satellite*);
  int satellite_master_pre(Satellite*);
  int satellite_master_init(Satellite*);
  int satellite_master_shutdown(Satellite*);
  int satellite_slave_pre(Satellite*);
};
#endif
