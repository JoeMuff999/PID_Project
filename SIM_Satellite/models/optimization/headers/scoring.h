/*************************************************************************
PURPOSE: (Function for finding optimization score)
**************************************************************************/
#ifndef SCORING_H
#define SCORING_H
#include <iostream>

class Scorer{

public:
	
	bool startPos;
	bool crossed;
	double maxOvershoot;
	bool alreadyRanOvershoot;

	double currentE;
	double previousE; //for dre recording :(
	
	void setCross(double);
	double getScore(double,double);



};
#endif
