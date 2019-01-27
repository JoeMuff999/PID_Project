%module m7efb6ea2066a027908bd2887043d1b94

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/home/joey/PID_Project/SIM_Satellite/models/STDRandomGenerator/headers/stdrandom.h"
%}

%trick_swig_class_typemap(STDRandom, STDRandom)



#ifndef STDRandom_H
#define STDRandom_H


class STDRandom{

public:
double getRandomNumber(int,int);
};
#define TRICK_SWIG_DEFINED_STDRandom
#endif

#ifdef TRICK_SWIG_DEFINED_STDRandom
%trick_cast_as(STDRandom, STDRandom)
#endif
