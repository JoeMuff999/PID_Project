/*****************************************************************************
PURPOSE:    (Satellite Angular Control)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string>
#include "../headers/satellite.h"
#include "../../Math/headers/Algebra.hh"
#include "trick/exec_proto.h"

int Satellite::satellite_angularDynamics()
{
  //satellite starts with dish pointing towards earth, only do control if the two vectors are not 180
  //determine satellite vector with pyr based on axes
  //angle vector, theta, phi, psi, rotation about forward (pitch), rotation about cross (yaw), rotation about down (roll)
  double pi = M_PI;
  double pos_Mag = 0;
  for(int i = 0; i < 3; i++)
  {
    pos_Mag += r[i]*r[i];
  }
  pos_Mag = sqrt(pos_Mag);

  for(int i = 0; i <3; i++)
  {
    angleVector[i] = pyr[i];
  }
  sToEVector[0] = -r[0]; //Forward, Cross, Down, (down is the same, FC are both negative)
  sToEVector[1] = -r[1];
  sToEVector[2] = r[2];



  double* crossP = vector.crossProduct(sToEVector,angleVector);
  double dotP = Math::Vector::dotProduct(sToEVector,angleVector);

  /*double pyrerror_mag = 0.0;

	for(int i = 0; i < 3; i++)
	{
		pyrerror[i] = pyr[i] - pyrtarget[i];
		pyrerror_mag += pyrerror[i]*pyrerror[i];
  }
  pyrerror_mag = sqrt(pyrerror_mag);

	double pyrshifter = pyrpid.getAngularShifter(&pyrerror_mag);

	//satellite_checkShutdown();
    // ACCELERATIONS
	for(int i = 0; i < 3; i++)
	{
			//multiply by neg because state-target gives opposite of what we want
			pyrthrust[i] = -10*(pyrshifter)*pyrerror[i]/pyrerror_mag;
			pyrsumForces[i] = pyrthrust[i];
			apyr[i] = pyrsumForces[i]/mass;

      vpyr[i] = vpyr[i] + (apyr[i]*interval);
			pyr[i] = pyr[i] + vpyr[i]*interval;

			apyrtarget[i] = 0;
			vpyrtarget[i] = vpyrtarget[i] + (apyrtarget[i]*interval);
			pyrtarget[i] = pyrtarget[i] + vpyrtarget[i]*interval;

	}

	time += interval;
	finalSettlingTime = scorer.settlingTime;
	finalPercentOvershoot = scorer.maxPercentOvershoot;    //i want to put this in shutdown but idk why monte ignores shutdowns very dumb :(*/

	return 0 ;

}
