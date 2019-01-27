/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <iostream>
#include <math.h>
#include "../headers/earth.h"


void Earth::setEarthVariables() {

    
    earthRadius = 6371393;  
	earthMass =5.972*pow(10,24);
	
    gravitationalConstant =6.67*pow(10,-11);

   
   
}
