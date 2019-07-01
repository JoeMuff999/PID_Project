/*****************************************************************************
PURPOSE:    (Satellite Eulers)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string>
#include "../headers/satellite.h"
#include "../../Math/headers/Algebra.hh"
#include "trick/exec_proto.h"

int Satellite::satellite_Dynamics( ) {

	double error_mag = 0.0;
	double verror_mag = 0.0;
	for(int i = 0; i < 3; i++)
	{
		error[i] = rtarget[i]-r[i];
		error_mag += error[i]*error[i];

		verror[i] = vtarget[i]-v[i] ;
		verror_mag += verror[i]*verror[i];
    }
  error_mag = sqrt(error_mag);
	verror_mag = sqrt(verror_mag);

	//double shifter = pid.getShifter(&error_mag,&verror_mag);
	double shifter = pid.getVariableShifter(&error_mag);
	/*double gainConstant = 20;


	double dDummy = gainConstant/(gainRatio+1);
	double kDummy = (1-dDummy);
	pid.setKValues(kDummy, 1, dDummy,1);*/

	//satellite_checkShutdown();
    // ACCELERATIONS
	for(int i = 0; i < 3; i++)
	{
			//multiply by neg because state-target gives opposite of what we want
			thrust[i] = 100*(shifter)*error[i]/error_mag;

			sumForces[i] = thrust[i] + -1*(env.earthMass * env.gravitationalConstant *mass)/( Math::Algebra::pow_int( Math::Vector::Vmag(r) , 3 ) ) * r[i];

			a[i] = sumForces[i]/mass;

      v[i] = v[i] + (a[i]*interval);
			r[i] = r[i] + v[i]*interval;

			atarget[i] = (-1*(env.earthMass * env.gravitationalConstant)/( Math::Algebra::pow_int( Math::Vector::Vmag(rtarget) , 3 ) ) * rtarget[i]);
			vtarget[i] = vtarget[i] + (atarget[i]*interval);
			rtarget[i] = rtarget[i] + vtarget[i]*interval;

	}
	//gainRatio = error[1]*a[1]/(v[1]*v[1]*mass);
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
