/*****************************************************************************
PURPOSE:    (yes )
*****************************************************************************/
#include <stdio.h>
#include <math.h>

void PID::setTimeInterval(double *x)
{
	timeInterval = x;
}

void PID::setKValues(double p, double i, double d,int x)
{
	 kP = p;  //.1,1,.01
	 kD = d;
	 kI = i;
	 runneth = x;
//	printf("kvalues: %.9f, %.9f", kP, kD);

}

double PID::getShifter(double actual, double desired, double previousError, int direction) {
	//direction is for keeping integral separate
	 shifter = 0;
	  error = actual - desired;

	 double derivative = (error - previousError)/(*timeInterval);
	 integral[direction] = integral[direction]  + (error**timeInterval);

	shifter = (kP * error) + (kD* derivative) + (kI*integral[direction]);
//	std::cout << " thrust == " << shifter;

	return shifter;


}
double PID::getError(double actual, double desired)
{

		error = actual-desired;


	return error;
}
