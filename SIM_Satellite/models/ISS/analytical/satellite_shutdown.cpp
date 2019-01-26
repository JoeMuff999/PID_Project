/************************************************************************
PURPOSE: (Print the final satellite state.)
*************************************************************************/
#include <stdio.h>
#include "../headers/satellite.h"
#include "trick/exec_proto.h"

int Satellite::satellite_shutdown( Satellite* S) {
    double t = exec_get_sim_time();
    printf( "========================================\n");
    printf( "      Satellite State at Shutdown     \n");
    printf( "t = %g\n", t);
    printf( "radius and velocity = [%.9f, %.9f]\n", S->actualRadius, S->actualVelocity);
    printf( "========================================\n");
    return 0 ;
}
