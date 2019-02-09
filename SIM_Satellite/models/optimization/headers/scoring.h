/*************************************************************************
PURPOSE: (Function for finding optimization score)
**************************************************************************/
#ifndef SCORING_H
#define SCORING_H
#include <iostream>

class Scorer{

public:

//vars for percent overshoot
	bool startPos;
	bool crossed;
	bool alreadyRanOvershoot;
	double maxPercentOvershoot;

//vars for settling time

	bool withinTwoPercent;
	double twoPercent;
	double elapsedTime;
	double elapsedTimeInRange;
	double settlingTime;
	bool alreadyFoundTime;


	double currentE;
	double previousE; //for dre recording :(

	double score;

	void setCross(double);
	void setTwoPercent(double);
	double getScore();
	void setPercentOvershoot(double,double);
	void setSettlingTime(double,double,double);



};
#endif
