/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <iostream>
#include <math.h>
#include "../headers/earth.h"


void Earth::setEarthVariables() {

    
    earthRadius = 6371393;  
	earthMass =5.972e+24;
	
    gravitationalConstant =6.67e-11;

   
   
}
