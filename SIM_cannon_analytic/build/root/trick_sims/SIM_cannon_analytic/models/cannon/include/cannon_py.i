%module mfb2f13cf4c836a1d9e5e5e4080d10a5e

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/root/trick_sims/SIM_cannon_analytic/models/cannon/include/cannon.h"
%}

%trick_swig_class_typemap(CANNON, CANNON)



#ifndef CANNON_H
#define CANNON_H

typedef struct {

	double vel0[2];    

	double pos0[2];    

	double init_speed; 

	double init_angle; 


	double acc[2];     

	double vel[2];     

	double pos[2];     


	double time;        


	int impact;        

	double impactTime;  


} CANNON;

#ifdef __cplusplus
extern "C" {
#endif
	int cannon_default_data(CANNON*);
	int cannon_init(CANNON*);
	int cannon_shutdown(CANNON*);
#ifdef __cplusplus
}
#endif

#endif
#ifdef TRICK_SWIG_DEFINED_CANNON
%trick_cast_as(CANNON, CANNON)
#endif
