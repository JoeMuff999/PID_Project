/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <math.h>
#include "../headers/satellite.h"

/* default data job */
int satellite_default_data( SATELLITE* S ) {

    S->standardVelocity = 0; //change this
    S->desiredRadius = 408773 + 6371393;  

    S->time = 0.0 ;
	S->counter = 0;

   

    return 0 ;
}

/* initialization job */
int satellite_init( SATELLITE* S) {
    S->actualRadius = 407164 + 6371393;    
S->actualAcceleration = (5.972 * pow(10,24) * 6.67*pow(10,-11))/(S->actualRadius + 6371393); 
    S->actualVelocity = 0;     


    return 0 ; 
}