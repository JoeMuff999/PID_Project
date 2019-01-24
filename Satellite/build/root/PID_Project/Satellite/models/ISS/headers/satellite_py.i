%module mfdff56e8d3eba163ff89f67962c185fe

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/root/PID_Project/Satellite/models/ISS/headers/satellite.h"
%}

%trick_swig_class_typemap(SATELLITE, SATELLITE)



#ifndef SATELLITE_H
#define SATELLITE_H

typedef struct {
	
	
	
    double standardVelocity ;    

    double desiredRadius ;    
   


	double actualAcceleration; 

    double actualVelocity ;     

    double actualRadius ;     


    double time;        

	int counter;

   

} SATELLITE ;

#ifdef __cplusplus
extern "C" {
#endif
    int satellite_default_data(SATELLITE*) ;
    int satellite_init(SATELLITE*) ;
    int satellite_shutdown(SATELLITE*) ;
#ifdef __cplusplus
}
#endif

#endif

#ifdef TRICK_SWIG_DEFINED_SATELLITE
%trick_cast_as(SATELLITE, SATELLITE)
#endif
