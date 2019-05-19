/*****************************************************************************
PURPOSE:    (Satellite Angular Control)
*****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string>
#include "../headers/satellite.h"
#include "trick/exec_proto.h"

int Satellite::satellite_angularDynamics()
{
  double pyrerror_mag = 0.0;
	double vpyrerror_mag = 0.0;
	for(int i = 0; i < 3; i++)
	{
		pyrerror[i] = pyr[i] - pyrtarget[i];
		pyrerror_mag += pyrerror[i]*pyrerror[i];

		vpyrerror[i] = vpyr[i] - vpyrtarget[i];
		vpyrerror_mag += vpyrerror[i]*vpyrerror[i];
    }
  pyrerror_mag = sqrt(pyrerror_mag);
	vpyrerror_mag = sqrt(vpyrerror_mag);

	double pyrshifter = pyrpid.getShifter(&pyrerror_mag,0);
	double vpyrshifter = pyrpid.getShifter(&vpyrerror_mag,1);

	//satellite_checkShutdown();
    // ACCELERATIONS
	for(int i = 0; i < 3; i++)
	{
			//multiply by neg because state-target gives opposite of what we want
			pyrthrust[i] = -10*(pyrshifter+vpyrshifter)*pyrerror[i]/pyrerror_mag;
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
	finalPercentOvershoot = scorer.maxPercentOvershoot;    //i want to put this in shutdown but idk why monte ignores shutdowns very dumb :(

	return 0 ;

}
