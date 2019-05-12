/*****************************************************************************
PURPOSE:    (Periodically print state)
*****************************************************************************/


#include "../headers/satellite.h"




  void Satellite::satellite_printState(bool autoOrAsk)
  {
    //if bool true, print first, bool false, second... for grouping
    if(counter == runtime/10 || counter ==0 && autoOrAsk)
  	{
  		printf("\n Satellite state: Position (x,y,z) = (%.5f,%.5f,%.5f), Velocity (vx,vy,vz) = (%.5f,%.5f,%.5f), Acceleration (ax,ay,az) = (%.5f,%.5f,%.5f)", r[0],r[1],r[2], v[0],v[1],v[2], a[0],a[1],a[2]);
  		counter = 0;
  	}
  	if(randomNumber!=0 && !autoOrAsk)
  	{
  	printf("\n Satellite state... Settling Time = %.9f, Percent Overshoot = %.9f, Random = %.9f, kP = %.9f, kD = %.9f, kI = %.9f ",finalSettlingTime, finalPercentOvershoot, randomNumber, pid.kP, pid.kD, pid.kI);
    }
    counter+=1;
  }
