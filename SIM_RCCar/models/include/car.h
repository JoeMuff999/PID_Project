/*************************************************************************
PURPOSE: (Represent the state and initial conditions of an RC Car)
**************************************************************************/
#ifndef RC_H
#define RC_H
#include <iostream>
#include <string>

class Car {
public:
    double init_pos; /* *i m initial position */ //for convenience
    double mass; /*kg *i mass of car */

    double force; /* N x forces (thrust) */

    double pos[]; /* m pos */
    double vel[]; /* m/s xy-velocity  */
    double acc[];  /* m/s2 xy-acceleration  */

    S



    double time; /* timeKeeper :) */

    double angularAcceleration[]; //for later

	  int car_default_data() ;
   	int car_init() ;
   	int car_shutdown() ;
    int car_dynamics(); // for numerical integration
}  ;


#endif
