/*****************************************************************************
PURPOSE:    (Satellite Eulers)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string>
#include "../headers/satellite.h"
#include "../../Math/headers/Vector.hh"
#include "../../Math/headers/Algebra.hh"
#include "trick/exec_proto.h"

int Satellite::satellite_Dynamics( ) {

	for(int i = 0; i < 3; i++)
	{
		error[i] = r[i] - rtarget[i];
	}
	satellite_checkShutdown();
    // ACCELERATIONS
	for(int i = 0; i < 3; i++)
	{
			//send over values as pointer?
			thrust[i] = pid.getShifter(&error[i],	 i);

			sumForces[i] = thrust[i] + -1*(env.earthMass * env.gravitationalConstant *mass)/( Math::Algebra::pow_int( Math::Vector::Vmag(r) , 3 ) ) * r[i];
			a[i] = sumForces[i]/mass;

      v[i] = v[i] + (a[i]*interval);
			r[i] = r[i] + v[i]*interval;


			atarget[i] = (-1*(env.earthMass * env.gravitationalConstant *mass)/( Math::Algebra::pow_int( Math::Vector::Vmag(rtarget) , 3 ) ) * rtarget[i])/mass;

			vtarget[i] = vtarget[i] + (atarget[i]*interval);
			rtarget[i] = rtarget[i] + vtarget[i]*interval;

	}

	time += interval;
	finalSettlingTime = scorer.settlingTime;
	finalPercentOvershoot = scorer.maxPercentOvershoot;    //i want to put this in shutdown but idk why monte ignores shutdowns very dumb :(

		return 0 ;

/*
	//set settling time and maxOverShoot
	scorer.setSettlingTime(error, previousError, time);
	scorer.setPercentOvershoot(error, previousError);
	double optimizationScore = scorer.getScore();
*/

}
