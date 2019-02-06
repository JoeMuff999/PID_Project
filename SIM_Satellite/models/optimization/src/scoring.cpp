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
	alreadyFoundTime = false;
	currentE= previousE ; //fix so that currentE isnt zero
	twoPercent = 100;//get within 100 meters, really isnt that hard so, 2 percent is wayyy too big, most will start in that range so


}
double Scorer::getScore()
{
	//settlingTime and maxOvershoot are your two variables

	return maxPercentOvershoot;
}

void Scorer::setSettlingTime(double currentErr, double previousErr,double elapsedTimeR)
{
	elapsedTime = elapsedTimeR;//same as below for this situation, dunno how it works in c++ but yeah
	/*if(abs(currentErr) < twoPercent)
	{
		elapsedTimeInRange+=0.01;
		//printf("current error, and two percent: %.9f, %.9f", currentErr, twoPercent);
	}
	else{
		elapsedTimeInRange = 0;
		if(alreadyFoundTime)
		{
		alreadyFoundTime = false; // hasn't settled yet and needs to go through again, ask mitch about this because idk how long i should put for settlingtime
		}
	}
	if(elapsedTimeInRange >5 && !alreadyFoundTime)
	{

	 settlingTime = elapsedTime -5;
	 printf("\n settlingTime: %.9f", settlingTime);
	 alreadyFoundTime = true;
	}*/
	if((abs(currentErr) < twoPercent) && !alreadyFoundTime)
	{
		settlingTime = elapsedTime;
printf("\n settlingTime: %.9f", settlingTime);
		alreadyFoundTime = true;
	}
	if(alreadyFoundTime && (abs(currentErr) > twoPercent))
	{
		alreadyFoundTime = false; 
	}
	

}

void Scorer::setPercentOvershoot(double currentErr, double previousErr)
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
			maxPercentOvershoot = (abs(previousE)/408773) *100; //biggestError/(desiredRadius - earth radius) to get percentage thats also positive
			alreadyRanOvershoot = true;
		}
	}

}
