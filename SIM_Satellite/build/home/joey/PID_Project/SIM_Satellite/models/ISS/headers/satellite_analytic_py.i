%module m76246220acd347c59854f67074103061

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/home/joey/PID_Project/SIM_Satellite/models/ISS/headers/satellite_analytic.h"
%}




#ifndef SATELLITE_ANALYTIC_H
#define SATELLITE_ANALYTIC_H
%import "build/home/joey/PID_Project/SIM_Satellite/models/ISS/headers/satellite_py.i"
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif

