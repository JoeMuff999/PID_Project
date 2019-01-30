/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/
#include <stdio.h>
#include <math.h>

void Scorer::setCross(double startingError)
{
	if(startingError >0)
	{
		startPos = true;
	}
	else
	{
		startPos = false;
	}
	alreadyRanOvershoot = false;
currentE= previousE ; //fix so that currentE isnt zero


}
double Scorer::getScore(double currentErr, double previousErr)
{
	currentE = currentErr;
	previousE = previousErr; //u know why, bad code but whatever
	if(startPos) //if error is positive, crossed becomes true when currentE is negative
	{
		if(currentE < 0)
			{
				crossed = true;
			}
	}
	else
	{
		if(currentE > 0)
			{
				crossed = true;
			}
	}
	if(crossed && !alreadyRanOvershoot)
	{
		if(abs(previousE) > abs(currentE) && previousE/currentE >0) //ensure they are the same sign
		{
			printf("(previous,current): %.9f, %.9f", previousE, currentE);
			maxOvershoot = previousE;
			alreadyRanOvershoot = true;
		}
	}
	return maxOvershoot;



}
