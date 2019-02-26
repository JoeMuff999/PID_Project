/*************************************************************************
PURPOSE: (Get random number based on STD/Normal Distribution)
**************************************************************************/
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <sys/time.h>

#include "../models/STDRandomGenerator/headers/stdrandom.h"
double STDRandom::getRandomNumber(int mean, int stddev)
{
	double randomNumber;
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mean,stddev);
	//i dont understand why this doesn't just get a new number everytime...
		//srand((unsigned) time(NULL) * getpt());
		timeval t1;
		 gettimeofday(&t1, NULL);
		srand(t1.tv_usec * t1.tv_sec);

	double terribleCode = (rand () % 10000);


	for(int x =0; x<terribleCode; x++)
	{
	randomNumber = distribution(generator);

	}


	return randomNumber;
}
