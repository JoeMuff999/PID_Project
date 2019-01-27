/*************************************************************************
PURPOSE: (Represent the state and initial conditions of the Earth)
**************************************************************************/
#include <iostream>
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


class Earth { 
public:
    

    double earthRadius ;    /* *i m radius of the Earth */
    double earthMass ;    /* *i m mass of the Earth */ 
    double gravitationalConstant; /* *i m gravitational constant of Earth */ 

    void setEarthVariables();

	
   

}  ; 



#endif
