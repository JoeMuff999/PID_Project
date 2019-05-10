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
	double integral[3];

	double* error; // TODO
    double previousError; // TODO

	double timeInterval;

	int runneth; //used for run number for verifying which gain value set you are adding values to.

	void setKValues(double,double,double,int);
	double getShifter(double,double, double,int);
	double getError(double,double);


};
#endif
