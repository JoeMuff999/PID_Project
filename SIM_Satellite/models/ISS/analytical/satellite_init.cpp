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


  standardVelocity = 0; //change this
  time = 0.0 ;
	counter = 0;
  mass = 2000;
  scorer.setTwoPercent(200);


	return 0;

}

/* initialization job */
int Satellite::satellite_init() {

    /*randomNumber = random.getRandomNumber(0,700);

    while(abs(randomNumber) < 950 || abs(randomNumber) >1000 )
    {
      randomNumber = random.getRandomNumber(0,700);
    }*/
    randomNumber = 1000;

 //giving the initial error to the scorer so it knows if it crossed or not
  scorer.setCross(randomNumber);
  r[0] = 0.0;
  r[1] = 5.0;
  r[2] = 408773 + 6371393;//randomNumber+ 408773 + 6371393;

  v[0] = 7664.832; //m/s
  v[1] = 0;
  v[2] = 0;

  rtarget[0] = 0.0;
  rtarget[1] = 500;
  rtarget[2] = 0.0;

	//previousError= desiredRadius - actualRadius;//using for derivative comparisons

	return 0;
}
