/************************************************************************
PURPOSE: (Print the final satellite state.)
*************************************************************************/
#include <stdio.h>
#include "../headers/satellite.h"
#include "trick/exec_proto.h"
void Satellite::satellite_checkShutdown()
{
  bool reachedTarget = true;
	for(int i = 0; i < 3; i++)
	{
		if(error[i]>= 20)
		{reachedTarget=false;
		}
	}
	if(reachedTarget)
	{
	std::string error = "sim succesful";
	exec_terminate_with_return(-1, __FILE__,__LINE__, error.c_str());
	}
}
int Satellite::satellite_shutdown() {
    double t = exec_get_sim_time();

    printf( "\n========================================\n");
    printf( "      Satellite State at Shutdown     \n");
    printf( "t = %g\n", t);
    printf( "Position (x,y,z) = (%.5f,%.5f,%.5f), Velocity (vx,vy,vz) = (%.5f,%.5f,%.5f)", r[0],r[1],r[2], v[0],v[1],v[2]);
    printf( "final settling time = [%.9f]\n", finalSettlingTime);
    printf( "========================================\n");
    return 0 ;
}
