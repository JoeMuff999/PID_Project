/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a satellite)
**************************************************************************/
#ifndef SATELLITE_H
#define SATELLITE_H
#include <iostream>
#include <string>

#include "../models/STDRandomGenerator/headers/stdrandom.h"
#include "../models/Environment/headers/earth.h"
#include "../models/Controllers/headers/pid.h"
#include "../models/optimization/include/scoring.h"
#include "../models/Math/headers/Vector.hh"




class Satellite { //sat class
	//only need to calculate radius from earth ...
	//these are u(t)?
public:
  double mass;
  double standardVelocity ;    /* *i m Constant factual velocity of satellite */
	double randomNumber[6];

  double sumForces[3];
  double thrust[3]; /*N r-force */
	double a[3]; /* m/s2 r-acceleration  */
  double v[3] ;     /* m/s r-velocity */
  double r[3];     /* m r-position */

  double atarget[3]; /* m/s2 r-acceleration  */
  double vtarget[3]; /* m/s r-velocity */
  double rtarget[3]; /* m r-position */
  double error[3];  /* m position error */
  double verror[3]; /* m/s velocity error */

  double pyrsumForces[3];
  double pyrthrust[3];
  double apyr[3];  /* radians/s2 PYR */
  double vpyr [3]; /*radians/s PYR*/
  double pyr[3]; /* radians PYR */

  double pyrtarget[3];  /* radians PYR */
  double vpyrtarget[3]; /* radians/s PYR */
  double apyrtarget[3]; /* radians/s2 PYR */
  double pyrerror[3];  /* radians PYR */
  double vpyrerror[3]; /* radians/s PYR */

  double angleVector[3]; /*radians*/
  double sToEVector[3]; /*radians*/
  double previousSToEVector[3];
  double previouspyr[3];

  double interval;
	double time;        /* s Model time */
	int counter;
  int runtime; // seconds to run this baby set in input file

//montecarlo stuff, using these to have a variable to point to for montecarlo
  double finalSettlingTime;
  double finalPercentOvershoot;






	int satellite_default_data() ;
  int satellite_init() ;
  int satellite_shutdown() ;
  void satellite_checkShutdown();
  //int satellite_analytic(Satellite*); numerical uncomment if want to use basic

  int satellite_Dynamics();
  int satellite_angularDynamics();

  void satellite_printState(bool);

  Earth env;
	STDRandom random;
	PID pid;
  PID pyrpid;
	Scorer scorer;
  Math::Vector vector;




}  ; //can use sat now as a name for this object

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif
