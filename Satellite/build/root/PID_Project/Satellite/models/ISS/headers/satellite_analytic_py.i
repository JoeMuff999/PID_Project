%module mf35f39864a9115e02690bd9f80f33b23

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/root/PID_Project/Satellite/models/ISS/headers/satellite_analytic.h"
%}




#ifndef SATELLITE_ANALYTIC_H
#define SATELLITE_ANALYTIC_H
%import "build/root/PID_Project/Satellite/models/ISS/headers/satellite_py.i"
#ifdef __cplusplus
extern "C" {
#endif
int satellite_analytic(SATELLITE*) ;
#ifdef __cplusplus
}
#endif
#endif
