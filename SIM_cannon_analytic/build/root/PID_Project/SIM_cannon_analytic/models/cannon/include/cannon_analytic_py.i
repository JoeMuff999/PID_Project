%module m8c15403d0f0788188a0cd132ec8cd2e3

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon_analytic.h"
%}




#ifndef CANNON_ANALYTIC_H
#define CANNON_ANALYTIC_H
%import "build/root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon_py.i"
#ifdef __cplusplus
extern "C" {
#endif
int cannon_analytic(CANNON*) ;
#ifdef __cplusplus
}
#endif
#endif
