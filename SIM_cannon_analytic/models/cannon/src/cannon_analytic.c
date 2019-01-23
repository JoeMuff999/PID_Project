/*****************************************************************************
PURPOSE:    ( Analytical Cannon )
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../include/cannon_analytic.h"

int cannon_analytic(CANNON* C) {

	C->acc[0] = 0.00;
	C->acc[1] = -9.81;
	//non numerical once more, just keeping it consistent
	C->vel0[0] = C->vel0[0] + C->acc[0] * C->time;
	//C->vel0[1] = C->vel0[1] + C->acc[1] * C->time;
	//non numerical integration, big cheat code boys
	C->pos0[0] =  (C->vel0[0] + (0.5) * C->acc[0] * C->time) * C->time;
	C->pos0[1] =  (C->vel0[1] + (0.5) * C->acc[1] * C->time) * C->time;
	
	
	//numerical int below
	
	C->vel[0] = C->vel[0] + C->acc[0]*.01;//.01 is the time interval here
	C->vel[1] = C->vel[1] + C->acc[1]*.01;

	C->pos[0] = C->pos[0] + C->vel[0]*.01;
	C->pos[1] = C->pos[1] + C->vel[1]*.01;
	
	
	
	if (C->pos[1] < 0.0) {
		//C->impactTime = (-C->vel0[1] - sqrt(C->vel0[1] * C->vel0[1] - 2 * C->pos0[1])) / C->acc[1];
		//C->pos[0] = C->impactTime * C->vel0[0];
		//C->pos[1] = 0.0;
		//C->vel[0] = 0.0;
		//C->vel[1] = 0.0;
		
		//C->impact = 1;
		C->impact = 1;
		fprintf(stderr, "\n\nNonnumerical positions: x = %.9f, y = %.9f\n\n", C->pos0[0], C->pos0[1]);
		fprintf(stderr, "\n\nNumerical positions: x = %.9f, y = %.9f\n\n", C->pos[0], C->pos[1]);
		
	}
	/*
	* Increment time by the time delta associated with this job
	* Note that the 0.01 matches the frequency of this job
	* as specified in the S_define.
	*/
	C->time += 0.01;
	return 0;
}