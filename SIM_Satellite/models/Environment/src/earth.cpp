/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <iostream>
#include <math.h>
#include "../headers/earth.h"


void Earth::setEarthVariables(double rad, double mass, double grav) {


    earthRadius = rad;
    earthMass =mass;
    gravitationalConstant =grav;



}
