/*****************************************************************************
PURPOSE:    (Satellite Eulers)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../headers/satellite.h"

int Satellite::satellite_Dynamics( Satellite* S ) {

	double interval = .01;



	double shifter = pid.getShifter(S->actualRadius, S->desiredRadius, S->previousError);
	double error = pid.getError(S->actualRadius, S->desiredRadius);
	//set settling time and maxOverShoot
	scorer.setSettlingTime(error, S->previousError, S->time);
	scorer.setPercentOvershoot(error, S->previousError);
	double optimizationScore = scorer.getScore();

	 //for printing purposes and for graphing as well

	S->previousError =  S->desiredRadius-S->actualRadius;


	S->actualAcceleration = -1*(env.earthMass * env.gravitationalConstant)/(pow((S->actualRadius),2)) + shifter;
	S->actualVelocity = S->actualVelocity + (S->actualAcceleration*interval);
	S->actualRadius = S->actualRadius + (S->actualVelocity*interval);

if(S->counter == 100 || S->counter ==0)
	{
		printf("\n Satellite state: aRadius = %.9f, aVelocity = %.9f, aAcceleration = %.9f, error = %.9f, shifter = %.9f, maxOverShoot = %.9f", S->actualRadius, S->actualVelocity, S->actualAcceleration, error,shifter, optimizationScore);
		S->counter = 0;
	}

    S->time += 0.01 ;
	S->counter+=1;
	S->finalSettlingTime = scorer.settlingTime;
	S->finalPercentOvershoot = scorer.maxPercentOvershoot;    //i want to put this in shutdown but idk why monte ignores shutdowns very dumb :(

    return 0 ;


}
