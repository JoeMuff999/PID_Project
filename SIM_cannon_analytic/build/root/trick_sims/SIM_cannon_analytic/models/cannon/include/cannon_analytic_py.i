%module m60f1d3e08103c5273af3d18ae4885fce

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/root/trick_sims/SIM_cannon_analytic/models/cannon/include/cannon_analytic.h"
%}




#ifndef CANNON_ANALYTIC_H
#define CANNON_ANALYTIC_H
%import "build/root/trick_sims/SIM_cannon_analytic/models/cannon/include/cannon_py.i"
#ifdef __cplusplus
extern "C" {
#endif
int cannon_analytic(CANNON*) ;
#ifdef __cplusplus
}
#endif
#endif
