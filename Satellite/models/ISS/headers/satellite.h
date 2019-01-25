/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a satellite)
**************************************************************************/
#ifndef SATELLITE_H
#define SATELLITE_H

typedef struct {
	//only need to calculate radius from earth ...
	//these are u(t)?
	
    double standardVelocity ;    /* *i m Constant factual velocity of satellite */
    double desiredRadius ;    /* *i m Desired radius of satellite from "Earth" */ 
	
	double gravitational; 


	double actualAcceleration; /* m/s2 r-acceleration  */
    double actualVelocity ;     /* m/s r-velocity */
    double actualRadius ;     /* m r-position */

    double time;        /* s Model time */
	int counter;

   

} SATELLITE ;

#ifdef __cplusplus
extern "C" {
#endif
    int satellite_default_data(SATELLITE*) ;
    int satellite_init(SATELLITE*) ;
    int satellite_shutdown(SATELLITE*) ;
#ifdef __cplusplus
}
#endif

#endif
