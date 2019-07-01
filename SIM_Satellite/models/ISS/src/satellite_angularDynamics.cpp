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

  double r_mag = 0;
  for(int i = 0; i < 3; i++)
  {
    r_mag += r[i]*r[i];
  }
  r_mag = sqrt(r_mag);
  negatex =1;
  negatey=1;
  negatez =1;

  if(r[2] <0)
  {
    negatez = -1;
  }
  else
  {
    negatez =1;
  }
  if(r[1] < 0)
  {
    negatey =-1;
  }
  else
  {
    negatey = 1;
  }
  if(r[0] < 0)
  {
    negatex =-1;
  }
  else
  {
    negatex = 1;
  }
  //pyr[1] = pi/2;

  sToEVector[0] = (negatex*-1*r[0]/r_mag *cos(pyr[2])*cos(pyr[1])) + negatey*r[1]/r_mag*((cos(pyr[2])*sin(pyr[1])*sin(pyr[0]))+(sin(pyr[2])*cos(pyr[0]))) +
  (negatez*r[2]/r_mag*(-1*cos(pyr[2])*sin(pyr[1])*cos(pyr[0])+(sin(pyr[2])*sin(pyr[0]))));
  sToEVector[1] = (negatex*-1 *r[0]/r_mag * -1*sin(pyr[2])*cos(pyr[1])) + (negatey*r[1]/r_mag*((-1*sin(pyr[2])*sin(pyr[1])*sin(pyr[0]))+(cos(pyr[2])*cos(pyr[0]))))+
  (negatez*r[2]/r_mag*(sin(pyr[2])*sin(pyr[1])*cos(pyr[0])+(cos(pyr[2])*sin(pyr[0]))));
  sToEVector[2] = (negatex*-1*r[0]/r_mag*sin(pyr[1])) + (negatey*-1*r[1]/r_mag*cos(pyr[1])*sin(pyr[0])) + (negatez*r[2]/r_mag*cos(pyr[1])*cos(pyr[0]));

//determine target

  pyrerror[0] = -1*atan(sToEVector[1]/sToEVector[2]);
  pyrerror[1] = atan(sToEVector[0]/sToEVector[2]);

  //pyrtarget[2] = atan(sToEVector[0]/sToEVector[1])*pi;

  double pyrerror_mag = 0.0;

	for(int i = 0; i < 3; i++)
	{
		pyrerror_mag += pyrerror[i]*pyrerror[i];
  }
  pyrerror_mag = sqrt(pyrerror_mag);

  double pyrshifter = pyrpid.getAngularShifter(&pyrerror_mag);

  for(int i = 0; i < 3; i++)
  {

      pyrthrust[i] = 10*(pyrshifter)*pyrerror[i]/pyrerror_mag;
      pyrsumForces[i] = pyrthrust[i];
      apyr[i] = pyrsumForces[i]/mass;

      vpyr[i] = vpyr[i] + (apyr[i]*interval);
      pyr[i] = pyr[i] + vpyr[i]*interval;

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
