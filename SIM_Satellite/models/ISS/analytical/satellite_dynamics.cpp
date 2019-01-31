/*****************************************************************************
PURPOSE:    (Satellite Eulers)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/satellite.h"

int Satellite::satellite_Dynamics( Satellite* S ) {
	
	double timeInterval = .01;

	
	
	double shifter = S->pid.getShifter(S->actualRadius, S->desiredRadius, S->previousError);
	double error = S->pid.getError(S->actualRadius, S->desiredRadius); //for printing purposes and for graphing as well
	S->previousError =  S->desiredRadius-S->actualRadius;


	S->actualAcceleration = -1*(env.earthMass * env.gravitationalConstant)/(pow((S->actualRadius + env.earthRadius),2)) + shifter;
	S->actualVelocity = S->actualVelocity + (S->actualAcceleration*timeInterval);
	S->actualRadius = S->actualRadius + (S->actualVelocity*timeInterval);
	if(S->counter == 100 || S->counter ==0)
	{
		printf("\n Satellite state: aRadius = %.9f, aVelocity = %.9f, aAcceleration = %.9f, error = %.9f, shifter = %.9f, random = %.9f", S->actualRadius, S->actualVelocity, S->actualAcceleration, error,shifter,S->randomNumber);
		S->counter = 0;
	}
    S->time += 0.01 ;
	S->counter+=1;


    return 0 ;


}
