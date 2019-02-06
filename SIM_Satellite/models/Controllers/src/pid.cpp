/*****************************************************************************
PURPOSE:    (yes )
*****************************************************************************/
#include <stdio.h>
#include <math.h>

void PID::setKValues()
{
	 kP = 1;  //.1,1,.01
	 kD = 1;
	 kI = .1;
	printf("kvalues: %.9f, %.9f", kP, kD);

}

double PID::getShifter(double actual, double desired, double previousError) {
	
	 timeInterval = .01;
	
	 shifter = 0;
	
	error = desired - actual;

	double derivative = (error - previousError)/timeInterval;
	 integral = integral + (error*timeInterval);
	//printf("\nprop, derv, integral: %.9f, %.9f,%.9f", error, derivative, integral);
    

	shifter = (kP * error) + (kD* derivative) + (kI*integral);
	

	previousError = desired - actual;
	
	return shifter;


}
double PID::getError(double actual, double desired)
{
	error = desired - actual;
	return error; 
}
