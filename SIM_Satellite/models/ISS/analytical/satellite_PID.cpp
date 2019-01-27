/*****************************************************************************
PURPOSE:    ( PID Satellite )
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/satellite.h"

int Satellite::satellite_PID( Satellite* S ) {
	
	double timeInterval = .01;
	
	double shifter = 0;
	double kP = -.1;
	int kD = 1;

	double derivative = ((S->previousError) - (S->error))/timeInterval;

    

	shifter = (kP * (S->error)) +(kD* derivative);
	S->previousError = S->actualRadius - S->desiredRadius;



    S->actualAcceleration = -1*(env.earthMass * env.gravitationalConstant)/(pow((S->actualRadius + env.earthRadius),2)) + shifter;
	S->actualVelocity = S->actualVelocity + (S->actualAcceleration*timeInterval);
	S->actualRadius = S->actualRadius + (S->actualVelocity*timeInterval);
	if(S->counter == 100 || S->counter ==0)
	{
		printf("\n Satellite state: aRadius = %.9f, aVelocity = %.9f, aAcceleration = %.9f, error = %.9f, shifter = %.9f, random = %.9f", S->actualRadius, S->actualVelocity, S->actualAcceleration, S->error,shifter,S->randomNumber);
		S->counter = 0;
	}
    S->time += 0.01 ;
	S->counter+=1;
	S->error = S->actualRadius - S->desiredRadius;

    return 0 ;


}
