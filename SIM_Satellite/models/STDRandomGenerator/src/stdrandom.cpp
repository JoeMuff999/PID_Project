/*************************************************************************
PURPOSE: (Get random number based on STD/Normal Distribution)
**************************************************************************/
#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "../models/STDRandomGenerator/headers/stdrandom.h"
double STDRandom::getRandomNumber(int mean, int stddev)
{
	double randomNumber;
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mean,stddev);
	//i dont understand why this doesn't just get a new number everytime...
	srand(time(NULL));

	double terribleCode = (rand () % 1000);


	for(int x =0; x<terribleCode; x++)
	{
	randomNumber = distribution(generator);
	}

	
	return randomNumber;
}

