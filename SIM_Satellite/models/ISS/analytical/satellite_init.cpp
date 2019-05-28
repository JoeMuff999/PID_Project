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
int Satellite::satellite_default_data( Satellite* S ) {


  S->standardVelocity = 0; //change this
  S->desiredRadius = 408773 + 6371393;
  S->time = 0.0 ;
	S->counter = 0;
  mass = 2000;
  //pid.setKValues(789.568,1,2513.274,1);
  pid.setKValues(7.89,1,251.332,1);
  //pid.setKValues(1,1,1,1);
	env.setEarthVariables();
	//pid.setKValues();

  scorer.setTwoPercent(200);


	return 0;

}

/* initialization job */
int Satellite::satellite_init( Satellite* S) {

    randomNumber = random.getRandomNumber(950,10);
/*
    while(abs(randomNumber) < 950 || abs(randomNumber) >1000 )
    {
      randomNumber = random.getRandomNumber(0,700);
    }*/
    //randomNumber = 1000;

 //giving the initial error to the scorer so it knows if it crossed or not
  scorer.setCross(randomNumber);
	S->actualRadius = randomNumber+ 408773 + 6371393;

  S->actualVelocity = 0;
	S->previousError= S->desiredRadius - S->actualRadius;//using for derivative comparisons

	return 0;
}
