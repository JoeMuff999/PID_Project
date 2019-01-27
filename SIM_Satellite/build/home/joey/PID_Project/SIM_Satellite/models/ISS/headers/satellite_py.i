%module m265e504be5526dee989c51ec4f5b15e7

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/home/joey/PID_Project/SIM_Satellite/models/ISS/headers/satellite.h"
%}

%trick_swig_class_typemap(Satellite, Satellite)



#ifndef SATELLITE_H
#define SATELLITE_H
%import "build/home/joey/PID_Project/SIM_Satellite/models/STDRandomGenerator/headers/stdrandom_py.i"
%import "build/home/joey/PID_Project/SIM_Satellite/models/Environment/headers/earth_py.i"



class Satellite { 
	
	
public:
    double standardVelocity ;    

    double desiredRadius ;    
 

	double error;
	double previousError;
double randomNumber;

	



	double actualAcceleration; 

    double actualVelocity ;     

    double actualRadius ;     


    double time;        

	int counter;
int satellite_default_data(Satellite*) ;
    int satellite_init(Satellite*) ;
    int satellite_shutdown(Satellite*) ;
    
    
    int satellite_PID(Satellite*);
    Earth env;
STDRandom random;

   

};
#define TRICK_SWIG_DEFINED_Satellite 

#ifdef __cplusplus
extern "C" {
#endif
    

#ifdef __cplusplus
}
#endif

#endif

#ifdef TRICK_SWIG_DEFINED_Satellite
%trick_cast_as(Satellite, Satellite)
#endif
