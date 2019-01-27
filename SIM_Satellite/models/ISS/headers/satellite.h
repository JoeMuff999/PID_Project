/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a satellite)
**************************************************************************/
#include <iostream>
#ifndef SATELLITE_H
#define SATELLITE_H
#include "../models/Environment/headers/earth.h"

class Satellite { //sat class
	//only need to calculate radius from earth ...
	//these are u(t)?
public:
    double standardVelocity ;    /* *i m Constant factual velocity of satellite */
    double desiredRadius ;    /* *i m Desired radius of satellite from "Earth" */ 
	



	double actualAcceleration; /* m/s2 r-acceleration  */
    double actualVelocity ;     /* m/s r-velocity */
    double actualRadius ;     /* m r-position */

    double time;        /* s Model time */
	int counter;
int satellite_default_data(Satellite*) ;
    int satellite_init(Satellite*) ;
    int satellite_shutdown(Satellite*) ;
    //int satellite_analytic(Satellite*); numerical uncomment if want to use basic
    int satellite_PID(Satellite*);
    Earth env;

   

}  ; //can use sat now as a name for this object

#ifdef __cplusplus
extern "C" {
#endif
    

#ifdef __cplusplus
}
#endif

#endif
