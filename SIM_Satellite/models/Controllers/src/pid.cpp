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

void PID::setGainRatio(double x)
{
	gainRatio = x;
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

double PID::getVariableShifter(double *e){

		shifter = 0;
		double error;
		error = *e;


		double derivative = (error-previousError)/ (*timeInterval);
		double integral = integral + error**timeInterval;
		shifter = (kP * error)+(kD * derivative)+(kI*integral);

		double previousError = *e;

		return shifter;

}

double PID::getAngularShifter(double *e){

		shifter = 0;
		double error;
		error = *e;

		double derivative = (error-previousError)/ (*timeInterval);

		shifter = (kP * error)+(kD * derivative);

		double previousError = *e;

		return shifter;

}
