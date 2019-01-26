/*****************************************************************************
PURPOSE:    ( Analytical Satellite )
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/satellite.h"

int Satellite::satellite_analytic( Satellite* S ) {
	
	double timeInterval = .01;
	

    S->actualAcceleration = (5.972 * pow(10,24) * S->gravitational)/(pow((S->actualRadius + 6371393),2)); //+ u(t)
	S->actualVelocity = S->actualVelocity + (S->actualAcceleration*timeInterval);
	S->actualRadius = S->actualRadius + (S->actualVelocity*timeInterval);
	if(S->counter == 50)
	{
		printf("\n Satellite state: aRadius = %.9f, aVelocity = %.9f, aAcceleration = %.9f", S->actualRadius, S->actualVelocity, S->actualAcceleration);
		S->counter = 0;
	}
    S->time += 0.01 ;
	S->counter+=1;
    return 0 ;
}
