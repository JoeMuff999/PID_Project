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

double PID::getShifter(double *e, int vOrNot){//, int direction) {
	//direction is for keeping integral separate, to implement again, just add direction to previous error and integral
	//vOrNot = use d controller or use p controller
		shifter = 0;
		double error;
		error = *e;

		if(vOrNot == 0) //positional error
		{
			shifter = (kP * error);
		}
		else
		{
			shifter = (kD* error);
		}

		return shifter;


}
