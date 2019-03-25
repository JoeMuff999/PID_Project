/*****************************************************************************
PURPOSE:    (Satellite Eulers)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string>
#include "../headers/satellite.h"

int Satellite::satellite_Dynamics( Satellite* S ) {

	double interval = .1;
  //to prevent previous error from being 0 and making derivative controller very large
	double error = S->pid.getError(S->actualRadius, S->desiredRadius);
	if(counter == 0)
	{
		previousError = error;
	}
	double shifter = S->pid.getShifter(S->actualRadius, S->desiredRadius, S->previousError);

	//set settling time and maxOverShoot
	scorer.setSettlingTime(error, S->previousError, S->time);
	scorer.setPercentOvershoot(error, S->previousError);
	double optimizationScore = scorer.getScore();

	 //for printing purposes and for graphing as well

	S->previousError =  S->desiredRadius-S->actualRadius;

	thrust = -1*(env.earthMass * env.gravitationalConstant *mass)/(pow((S->actualRadius),2)) + shifter*mass;
	S->actualAcceleration = actualAcceleration + (thrust/mass)*interval; //actualAcceleration + -1*((env.earthMass * env.gravitationalConstant)/(pow((S->actualRadius),2))*interval) + shifter;////
	S->actualVelocity = S->actualVelocity + (S->actualAcceleration*interval);
	S->actualRadius = S->actualRadius + (S->actualVelocity*interval);

if(S->counter == 100 || S->counter ==0)
	{
		printf("\n Satellite state: aRadius = %.9f, aVelocity = %.9f, aAcceleration = %.9f, error = %.9f, shifter = %.9f, maxOverShoot = %.9f", S->actualRadius, S->actualVelocity, S->actualAcceleration, error,shifter, optimizationScore);
		S->counter = 0;
	}

    S->time += interval;
	S->counter+=1;
	S->finalSettlingTime = scorer.settlingTime;
	S->finalPercentOvershoot = scorer.maxPercentOvershoot;    //i want to put this in shutdown but idk why monte ignores shutdowns very dumb :(

    return 0 ;


}
void Satellite::satellite_printState(Satellite* S)
{
	if(S->randomNumber!=0)
	{
	printf("\n Satellite state... Settling Time = %.9f, Percent Overshoot = %.9f, Random = %.9f, kP = %.9f, kD = %.9f, kI = %.9f ",S->finalSettlingTime, S->finalPercentOvershoot, S->randomNumber, S->pid.kP, S->pid.kD, S->pid.kI);
}
}
