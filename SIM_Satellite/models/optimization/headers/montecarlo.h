/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/
#ifndef MONTE_H
#define MONTE_H

#include "../models/ISS/headers/satellite.h"

class monte {
public:
  Satellite satelliteArray[20];
  int satellite_slave_post(Satellite*);
  int satellite_master_post(Satellite*);
  int satellite_master_pre(Satellite*);
  int satellite_master_init(Satellite*);
  int satellite_master_shutdown(Satellite*);
};
#endif
