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
    void setEarthVariables(double,double,double);

    Earth()
    {
      earthRadius = 6371393;
      earthMass =5.972e+24;
      gravitationalConstant =6.67e-11;
    }



}  ;



#endif
