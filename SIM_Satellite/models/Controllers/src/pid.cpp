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

double PID::getShifter(double *e, double *ve){//, int direction) {
	//direction is for keeping integral separate, to implement again, just add direction to previous error and integral

		shifter = 0;
		double error;
		double verror;

		error = *e;
		verror = *e;

		shifter = (kP * error)+(kD* verror);

		return shifter;

}

double PID::getAngularShifter(double *e){//, int direction) {
	//direction is for keeping integral separate, to implement again, just add direction to previous error and integral

		shifter = 0;
		double error;
		error = *e;

		integral+=error;

		shifter = (kP * error)+(kD* (error-previousError)/timeInterval)+(kI*error*timeInterval);
		double previousError = *e;
		return shifter;

}
