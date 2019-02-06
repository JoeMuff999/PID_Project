/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a satellite)
**************************************************************************/
#ifndef SATELLITE_H
#define SATELLITE_H
#include <iostream>

#include "../models/STDRandomGenerator/headers/stdrandom.h"
#include "../models/Environment/headers/earth.h"
#include "../models/Controllers/headers/pid.h"
#include "../models/optimization/headers/scoring.h"



class Satellite { //sat class
	//only need to calculate radius from earth ...
	//these are u(t)?
public:
    double standardVelocity ;    /* *i m Constant factual velocity of satellite */
    double desiredRadius ;    /* *i m Desired radius of satellite from "Earth" */


	double previousError;
	double randomNumber;






	double actualAcceleration; /* m/s2 r-acceleration  */
    double actualVelocity ;     /* m/s r-velocity */
    double actualRadius ;     /* m r-position */


	double time;        /* s Model time */
	int counter;

//montecarlo stuff, using these to have a variable to point to for montecarlo
  double finalSettlingTime;
  double finalPercentOvershoot;






	int satellite_default_data(Satellite*) ;
   	int satellite_init(Satellite*) ;
   	int satellite_shutdown(Satellite*) ;
    //int satellite_analytic(Satellite*); numerical uncomment if want to use basic

    int satellite_Dynamics(Satellite*);
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
