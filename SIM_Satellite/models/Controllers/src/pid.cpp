/*****************************************************************************
PURPOSE:    (yes )
*****************************************************************************/
#include <stdio.h>
#include <math.h>

double PID::getShifter(double actual, double desired, double previousError) {
	
	double timeInterval = .01;
	
	double shifter = 0;
	double kP = .1;
	double kD = 1;
	double kI =.01;

	error = desired - actual;

	double derivative = (error - previousError)/timeInterval;
	double integral = integral + (error*timeInterval);

    

	shifter = (kP * error) + (kD* derivative) + (kI*integral);
	

	previousError = desired - actual;

	return shifter;


}
double PID::getError(double actual, double desired)
{
	error = desired - actual;
	return error; 
}
