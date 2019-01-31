/*****************************************************************************
PURPOSE:    ( PID Satellite )
*****************************************************************************/
#ifndef PID_H
#define PID_H
#include <stdio.h>
#include <math.h>


class PID{

public:
	double kP;
	double kI;
	double kD;
	
	double shifter;

	double error;

	double timeInterval;
	
	double getShifter(double,double, double);
	double getError(double,double);
	

};
#endif
