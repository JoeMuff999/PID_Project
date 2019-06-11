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
  double deltapyr[3];
  double pos_Mag = 0;
  double r_mag = 0;
  for(int i = 0; i < 3; i++)
  {
    pos_Mag += r[i]*r[i];
    r_mag += r[i]*r[i];
    deltapyr[i] = pyr[i] - previouspyr[i];
  }
  pos_Mag = sqrt(pos_Mag);
  r_mag = sqrt(r_mag);

  downVector[0] = 0;
  downVector[1] = 0;
  downVector[2] = 1;



  /*sToEVector[0] = (r[0]/r_mag * cos(pyr[2])*cos(pyr[1])) + (r[1]/r_mag * sin(pyr[2])*cos(pyr[1])) + (-1*r[2]/r_mag*-1*sin(pyr[1]));
  sToEVector[1] = (r[0]/r_mag* (cos(pyr[2])*sin(pyr[1])*sin(pyr[0])-sin(pyr[2])*cos(pyr[0])))
  + (r[1]/r_mag*(sin(pyr[2])*sin(pyr[1])*sin(pyr[0])+cos(pyr[2])*cos(pyr[0])))+ (-1*r[2]/r_mag*cos(pyr[1])*sin(pyr[0]));
  sToEVector[2] = (r[0]/r_mag*(cos(pyr[2])*sin(pyr[1])*cos(pyr[0])+sin(pyr[2])*sin(pyr[0])))
  + (r[1]/r_mag*(sin(pyr[2])*sin(pyr[1])*cos(pyr[0])-cos(pyr[2])*sin(pyr[0])))+(-1*r[2]/r_mag*cos(pyr[1])*cos(pyr[0]));*/


  negate = 1;
  if(r[2] < 0)
  {
    //negate =-1;
  }
  else
  {
    //negate =1;
  }

  pyrtarget[0] = -1*atan(-1*r[1]/r[2]);
  //pyrtarget[0] = -1*atan(sToEVector[1]/sToEVector[2]);
  //pyrtarget[1] = atan(sToEVector[0]/sToEVector[2]);
  pyrtarget[1] = atan(-1*r[0]/r[2]);
  //pyrtarget[2] = atan(sToEVector[0]/sToEVector[1])*pi;

  //pyr[0] = pyrtarget[0];
  pyr[1] = pyrtarget[1];
  //printf("%.9f, %.9f", pyr[0], pyr[1]);
  //pyr[2] = pyrtarget[2];

  sToEVector[0] = (-1*r[0]/r_mag *cos(pyr[2])*cos(pyr[1])) + r[1]/r_mag*((cos(pyr[2])*sin(pyr[1])*sin(pyr[0]))+(sin(pyr[2])*cos(pyr[0]))) +
  (negate*r[2]/r_mag*(-1*cos(pyr[2])*sin(pyr[1])*cos(pyr[0])+(sin(pyr[2])*sin(pyr[0]))));
  sToEVector[1] = (-1 *r[0]/r_mag * -1*sin(pyr[2])*cos(pyr[1])) + (r[1]/r_mag*((-1*sin(pyr[2])*sin(pyr[1])*sin(pyr[0]))+(cos(pyr[2])*cos(pyr[0]))))+
  (negate*r[2]/r_mag*(sin(pyr[2])*sin(pyr[1])*cos(pyr[0])+(cos(pyr[2])*sin(pyr[0]))));
  sToEVector[2] = (-1*r[0]/r_mag*sin(pyr[1])) + (-1*r[1]/r_mag*cos(pyr[1])*sin(pyr[0])) + (negate*r[2]/r_mag*cos(pyr[1])*cos(pyr[0]));
  double* crossP = vector.crossProduct(sToEVector,downVector);

  //printf("\nCrossProduct (%.9f, %.9f, %.9f)", crossP[0], crossP[1], crossP[2]);
  //double dotP = Math::Vector::dotProduct(sToEVector,downVector);

  //set for next
  for(int i = 0; i <3; i++)
  {
    previousSToEVector[i] = sToEVector[i];
    previouspyr[i] = pyr[i];
  }

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
