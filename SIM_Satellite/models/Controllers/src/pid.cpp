/*****************************************************************************
PURPOSE:    (yes )
*****************************************************************************/
#include <stdio.h>
#include <math.h>

void PID::setKValues(double p, double i, double d,int x)
{
	 kP = p;  //.1,1,.01
	 kD = d;
	 kI = i;
	 runneth = x;
//	printf("kvalues: %.9f, %.9f", kP, kD);

}

double PID::getShifter() {
	 double derivative = (error - previousError)/timeInterval;
	 integral[direction] = integral[direction]  + (error*timeInterval);

	shifter = (kP * error) + (kD* derivative) + (kI*integral[direction]);
//	std::cout << " thrust == " << shifter;


    previousError = error;
    return shifter;


}
double PID::getError(double actual, double desired)
{
	// error = state - target
    error =  actual - desired;

	return error;
}
