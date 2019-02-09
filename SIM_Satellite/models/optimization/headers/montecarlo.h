/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/
#ifndef MONTE_H
#define MONTE_H

#include "../models/ISS/headers/satellite.h"
#include "../models/Controllers/headers/pid.h"

class monte {
public:
  Satellite satelliteArray[5000];
  int runsPerGainValueSet;
  PID storage[1000];
  bool timeToSwitchGain;
  int satellite_slave_post(Satellite*);
  int satellite_master_post(Satellite*);
  int satellite_master_pre(Satellite*);
  int satellite_master_init(Satellite*);
  int satellite_master_shutdown(Satellite*);
};
#endif
