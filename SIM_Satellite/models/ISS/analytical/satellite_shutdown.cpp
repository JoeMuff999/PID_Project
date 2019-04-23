/************************************************************************
PURPOSE: (Print the final satellite state.)
*************************************************************************/
#include <stdio.h>
#include "../headers/satellite.h"
#include "trick/exec_proto.h"

int Satellite::satellite_shutdown( Satellite* S) {
    double t = exec_get_sim_time();

    printf( "\n========================================\n");
    printf( "      Satellite State at Shutdown     \n");
    printf( "t = %g\n", t);
    printf( "Position (x,y,z) = (%.5f,%.5f,%.5f), Velocity (vx,vy,vz) = (%.5f,%.5f,%.5f)", r[0],r[1],r[2], v[0],v[1],v[2]);
    printf( "final settling time = [%.9f]\n", finalSettlingTime);
    printf( "========================================\n");
    return 0 ;
}
