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
int monte::satellite_master_init(Satellite* S)
{
  //change run number based on what u put in ur monte.py input file, this is essential!!!

  //satelliteArray [20]; //20 is the amount of runs.

  return 0;
}
int monte::satellite_master_post(Satellite* S)
{
  Satellite run_satellite;
  mc_read((char*) &run_satellite, sizeof(Satellite));
  static double totalSettlingTime;
  totalSettlingTime+= run_satellite.finalSettlingTime;




  printf("settling time : %.9f", totalSettlingTime);
  //once counter hits x number of runs, change the k variable.
  static int runCounter;
  satelliteArray [runCounter] = run_satellite;
  runCounter+=1;

  return 0;
}

int monte::satellite_master_pre(Satellite* S)
{
  return 0;

}

int monte::satellite_master_shutdown(Satellite* S)
{
  for(Satellite p :satelliteArray)
  {
    Satellite* f = &p;
    p.satellite_printState(f);
  }
}
