/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a satellite)
**************************************************************************/
#ifndef SATELLITE_H
#define SATELLITE_H
#include <iostream>
#include <string>

#include "../models/STDRandomGenerator/headers/stdrandom.h"
#include "../models/Environment/headers/earth.h"
#include "../models/Controllers/headers/pid.h"
#include "../models/optimization/include/scoring.h"



class Satellite { //sat class
	//only need to calculate radius from earth ...
	//these are u(t)?
public:
  double mass;
  double standardVelocity ;    /* *i m Constant factual velocity of satellite */
	double previousError[3];
	double randomNumber;

  double sumForces[3];
  double thrust[3]; /*N r-force */
	double a[3]; /* m/s2 r-acceleration  */
  double v[3] ;     /* m/s r-velocity */
  double r[3];     /* m r-position */

  double atarget[3]; /* m/s2 r-acceleration  */
  double rtarget[3]; /* m r-position */
  double vtarget[3]; /* m/s r-velocity */
  double error[3];   /* m distance from desired position */
  double error_mag;



  double interval;
	double time;        /* s Model time */
	int counter;
  int runtime; // seconds to run this baby set in input file

//montecarlo stuff, using these to have a variable to point to for montecarlo
  double finalSettlingTime;
  double finalPercentOvershoot;






	int satellite_default_data() ;
  int satellite_init() ;
  int satellite_shutdown() ;
  //int satellite_analytic(Satellite*); numerical uncomment if want to use basic

  int satellite_Dynamics();
  void satellite_printState();

  Earth env;
	STDRandom random;
	PID pid;
	Scorer scorer;




}  ; //can use sat now as a name for this object

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif
