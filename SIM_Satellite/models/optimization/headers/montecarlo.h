/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/
#ifndef MONTE_H
#define MONTE_H

#include "../models/ISS/headers/satellite.h"

class monte {
public:
  int satellite_slave_post(Satellite*);
  int satellite_master_post(Satellite*);
};
#endif
