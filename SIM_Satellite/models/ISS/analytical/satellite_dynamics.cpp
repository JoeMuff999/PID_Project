/*****************************************************************************
PURPOSE:    (Satellite Eulers)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string>
#include "../headers/satellite.h"
#include "../../Math/headers/Vector.hh"
#include "../../Math/headers/Algebra.hh"

int Satellite::satellite_Dynamics( ) {



    // ACCELERATIONS
	for(int i = 0; i < 3; i++)
	{
		// FIXME do not add one time jobs inside of derivative loop
        if(counter == 0)
		{
			previousError[i] = error[i];
		}

			thrust[i] = pid.getShifter(r[i], rtarget[i], previousError[i], i);
			previousError[i] = rtarget[i] - r[i];

			sumForces[i] = thrust[i] + -1*(env.earthMass * env.gravitationalConstant *mass)/( Math::Algebra::pow_int( Math::Vector::Vmag(r) , 3 ) ) * r[i];
			a[i] = sumForces[i]/mass;

      v[i] = v[i] + (a[i]*interval);
			r[i] = r[i] + v[i]*interval;


			atarget[i] = (-1*(env.earthMass * env.gravitationalConstant *mass)/( Math::Algebra::pow_int( Math::Vector::Vmag(rtarget) , 3 ) ) * rtarget[i])/mass;

			vtarget[i] = vtarget[i] + (atarget[i]*interval);
			rtarget[i] = rtarget[i] + vtarget[i]*interval;

	}

    return 0;
}
	/*
  //to prevent previous error from being 0 and making derivative controller very large
	double error = pid.getError(actualRadius, desiredRadius);
	if(counter == 0)
	{
		previousError = error;
	}
	double shifter = pid.getShifter(actualRadius, desiredRadius, previousError);

	//set settling time and maxOverShoot
	scorer.setSettlingTime(error, previousError, time);
	scorer.setPercentOvershoot(error, previousError);
	double optimizationScore = scorer.getScore();

	 //for printing purposes and for graphing as well

	previousError =  desiredRadius-actualRadius;


	thrust = shifter*2;
	sumForces = thrust +  -1*(env.earthMass * env.gravitationalConstant *mass)/(pow((actualRadius),2));
	actualAcceleration = (sumForces/mass); //actualAcceleration + -1*((env.earthMass * env.gravitationalConstant)/(pow((actualRadius),2))*interval) + shifter;////

	actualRadius = actualRadius + (actualVelocity*interval);
	actualVelocity = actualVelocity + (actualAcceleration*interval); //move below because eulers !*/

void satellite_print() {
		printf("\n Satellite state: Position (x,y,z) = (%.5f,%.5f,%.5f), Velocity (vx,vy,vz) = (%.5f,%.5f,%.5f), Acceleration (ax,ay,az) = (%.5f,%.5f,%.5f)", r[0],r[1],r[2], v[0],v[1],v[2], a[0],a[1],a[2]);


  time += interval;
	counter+=1;
	finalSettlingTime = scorer.settlingTime;
	finalPercentOvershoot = scorer.maxPercentOvershoot;    //i want to put this in shutdown but idk why monte ignores shutdowns very dumb :(

    return 0 ;


}
void Satellite::satellite_printState()
{
	if(randomNumber!=0)
	{
	printf("\n Satellite state... Settling Time = %.9f, Percent Overshoot = %.9f, Random = %.9f, kP = %.9f, kD = %.9f, kI = %.9f ",finalSettlingTime, finalPercentOvershoot, randomNumber, pid.kP, pid.kD, pid.kI);
}
}
