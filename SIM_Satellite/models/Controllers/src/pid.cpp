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

double PID::getShifter(double *e, int direction) {
	//direction is for keeping integral separate
		shifter = 0;

		double error;
		error = *e;

		double derivative = (error - previousError[direction])/(*timeInterval);
 		integral[direction] = integral[direction]  + (error**timeInterval);

		shifter = (kP * error) + (kD* derivative) + (kI*integral[direction]);
		previousError[direction] = error;
		return shifter;


}
