/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <math.h>
#include "../headers/satellite.h"
#include "../models/Environment/headers/earth.h"
#include "../models/Environment/src/earth.cpp"
#include "../models/STDRandomGenerator/headers/stdrandom.h"
#include "../models/STDRandomGenerator/src/stdrandom.cpp"
#include "../models/Controllers/headers/pid.h"
#include "../models/Controllers/src/pid.cpp"
#include "../models/optimization/include/scoring.h"
#include "../models/optimization/src/scoring.cpp"
#include "../models/Math/headers/Vector.cpp"

/* default data job */
int Satellite::satellite_default_data() {

  pid.setTimeInterval(&interval);
  standardVelocity = 0; //change this
  time = 0.0 ;
	counter = 0;
  mass = 2000;
  scorer.setTwoPercent(200);


	return 0;

}

/* initialization job */
int Satellite::satellite_init() {

  for(int i = 0; i < 6; i++)
  {
		randomNumber[i]= random.getRandomNumber(975.0,5.0);
    }
    //giving the initial error to the scorer so it knows if it crossed or not
  //scorer.setCross(randomNumber);
  error[0] = randomNumber[0];
  error[1] = randomNumber[1];
  error[2] = randomNumber[2];

  double error_mag = 0;
  for(int i = 0; i < 3; i++)
  {
		error_mag += error[i]*error[i];
    }
  pid.previousError = sqrt(error_mag);

  rtarget[0] = 0.0;
  rtarget[1] = 0.0;
  rtarget[2] = 408773 + 6371393;

  vtarget[0] = 7664.832; //m/s
  vtarget[1] = 0;
  vtarget[2] = 0;

  r[0] = rtarget[0] + error[0];
  r[1] = rtarget[1] + error[1];
  r[2] = rtarget[2] + error[2];//randomNumber+ 408773 + 6371393;

  v[0] = 7664.832; //m/s
  v[1] = 0;
  v[2] = 0;

//angular dynamics intialization
double r_mag = 0;
  for(int i = 0; i < 3; i++)
  {
r_mag += r[i]*r[i];
  }
  r_mag = sqrt(r_mag);


  sToEVector[0] = r[0]/r_mag;
  sToEVector[1] = r[1]/r_mag;
  sToEVector[2] = -r[2]/r_mag;



  pyrerror[0];
  pyrerror[1];
  pyrerror[2];

  double pyrerror_mag = 0;
  for(int i = 0; i < 3; i++)
  {
		pyrerror_mag += pyrerror[i]*pyrerror[i];
  }
  pyrpid.previousError = sqrt(pyrerror_mag);

  pyrtarget[0] = 0.0;
  pyrtarget[1] = 0.0;
  pyrtarget[2] = 0.0;

  vpyrtarget[0] = 0; //m/s
  vpyrtarget[1] = 0;
  vpyrtarget[2] = 0;
  //desired - state :) reverse of the position stuff but who cares
  pyr[0] = pyrtarget[0] ;//- pyrerror[3];
  pyr[1] = pyrtarget[1] ;//- error[4];
  pyr[2] = pyrtarget[2] ;//- error[5];

  vpyr[0] = 0; //m/s
  vpyr[1] = 0;
  vpyr[2] = 0;

  for(int i = 0; i < 3; i++)
  {
    previouspyr[i] = pyr[i];
    previousSToEVector[i] = sToEVector[i];
  }

  return 0;
}
