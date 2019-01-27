%module m0240f8c64b71b1bf95173790bd2bf86c

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/home/joey/PID_Project/SIM_Satellite/models/Environment/headers/earth.h"
%}

%trick_swig_class_typemap(Earth, Earth)



#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


class Earth { 
public:
    

    double earthRadius ;    

    double earthMass ;    
 
    double gravitationalConstant; 
 

    void setEarthVariables();

	
   

};
#define TRICK_SWIG_DEFINED_Earth 



#endif

#ifdef TRICK_SWIG_DEFINED_Earth
%trick_cast_as(Earth, Earth)
#endif
