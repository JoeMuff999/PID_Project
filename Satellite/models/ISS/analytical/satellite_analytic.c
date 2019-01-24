/*****************************************************************************
PURPOSE:    ( Analytical Satellite )
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/satellite_analytic.h"

int satellite_analytic( SATELLITE* S ) {
	
	double timeInterval = .01;
	

    S->actualAcceleration = (5.972 * pow(10,24) * 6.67*pow(10,-11))/(pow((S->actualRadius + 6371393),2)); 
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