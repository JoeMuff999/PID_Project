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

/* default data job */
int Satellite::satellite_default_data( Satellite* S ) {
	
    S->standardVelocity = 0; //change this
    S->desiredRadius = 408773 + 6371393;  



	

    S->time = 0.0 ;
	S->counter = 0;
	S->env.setEarthVariables();

   
	return 0;
   
}

/* initialization job */
int Satellite::satellite_init( Satellite* S) {

    S->randomNumber = S->random.getRandomNumber(0,10000);
	

	S->actualRadius = S->randomNumber+ 408773 + 6371393;   
	S->actualAcceleration = (5.972 * pow(10,24) * 6.67*pow(10,-11))/(S->actualRadius + 6371393); 
    S->actualVelocity = 0;     
	//S->error = S->actualRadius - S->desiredRadius; // if error is positive, U(t) must be negative (its too big), other way if error negative
	S->previousError = 0; //using for derivative comparisons

	return 0;
}
