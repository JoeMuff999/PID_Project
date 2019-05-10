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

  randomNumber = random.getRandomNumber(975.0,5.0);

  while(abs(randomNumber) < 950 || abs(randomNumber) >1000 )
  {
    randomNumber = random.getRandomNumber(0,700);
  }
 //giving the initial error to the scorer so it knows if it crossed or not
  scorer.setCross(randomNumber);



  error[0] = 0;
  error[1] = randomNumber;
  error[2] = 0;

  for(int i = 0; i < 3; i++)
  {
    previousError[i] = error[i];
  }

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



	return 0;
}
