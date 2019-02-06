/*
PURPOSE: (record satellite settling time and max percent overshoot for scoring)
*/

#include "../models/ISS/headers/satellite.h"
#include "../headers/montecarlo.h"
#include "sim_services/MonteCarlo/include/montecarlo_c_intf.h"

int monte::satellite_slave_post(Satellite* S)
{
   mc_write((char*) S, sizeof(Satellite));
  return 0;
}

int monte::satellite_master_post(Satellite* S)
{
  Satellite run_satellite;
  mc_read((char*) &run_satellite, sizeof(Satellite));
  static double totalSettlingTime=0;
  totalSettlingTime+= run_satellite.finalSettlingTime;

  printf("settling time : %.9f", totalSettlingTime);

  return 0;
}
