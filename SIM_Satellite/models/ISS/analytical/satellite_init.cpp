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
#include "../models/optimization/headers/scoring.h"
#include "../models/optimization/src/scoring.cpp"

/* default data job */
int Satellite::satellite_default_data( Satellite* S ) {

    S->standardVelocity = 0; //change this
    S->desiredRadius = 408773 + 6371393;





    S->time = 0.0 ;
	S->counter = 0;
	env.setEarthVariables();
	pid.setKValues();


	return 0;

}

/* initialization job */
int Satellite::satellite_init( Satellite* S) {

    randomNumber = random.getRandomNumber(0,1000);



	S->actualRadius = randomNumber+ 408773 + 6371393;
	S->actualAcceleration = (5.972 * pow(10,24) * 6.67*pow(10,-11))/(S->actualRadius);
    S->actualVelocity = 0;

	//S->error = S->actualRadius - S->desiredRadius; // if error is positive, U(t) must be negative (its too big), other way if error negative
	S->previousError= S->desiredRadius - S->actualRadius;//using for derivative comparisons
	scorer.setCross((S->desiredRadius - S->actualRadius)); //giving the initial error to the scorer so it knows if it crossed or not
	return 0;
}
