#include <Python.h>
#if PY_VERSION_HEX >= 0x03000000
extern "C" {

PyObject * PyInit__m98f2329096201d54121e64f938fb3d34(void) ; /* /home/joey/PID_Project/SIM_Satellite/S_source.hh */
PyObject * PyInit__m0240f8c64b71b1bf95173790bd2bf86c(void) ; /* /home/joey/PID_Project/SIM_Satellite/models/Environment/headers/earth.h */
PyObject * PyInit__m265e504be5526dee989c51ec4f5b15e7(void) ; /* /home/joey/PID_Project/SIM_Satellite/models/ISS/headers/satellite.h */
PyObject * PyInit__m7efb6ea2066a027908bd2887043d1b94(void) ; /* /home/joey/PID_Project/SIM_Satellite/models/STDRandomGenerator/headers/stdrandom.h */
PyObject * PyInit__sim_services(void) ;
PyObject * PyInit__top(void) ;
PyObject * PyInit__swig_double(void) ;
PyObject * PyInit__swig_int(void) ;
PyObject * PyInit__swig_ref(void) ;

void init_swig_modules(void) {

    PyImport_AppendInittab("_m0240f8c64b71b1bf95173790bd2bf86c", PyInit__m0240f8c64b71b1bf95173790bd2bf86c) ;
    PyImport_AppendInittab("_m265e504be5526dee989c51ec4f5b15e7", PyInit__m265e504be5526dee989c51ec4f5b15e7) ;
    PyImport_AppendInittab("_m7efb6ea2066a027908bd2887043d1b94", PyInit__m7efb6ea2066a027908bd2887043d1b94) ;
    PyImport_AppendInittab("_m98f2329096201d54121e64f938fb3d34", PyInit__m98f2329096201d54121e64f938fb3d34) ;
    PyImport_AppendInittab("_sim_services", PyInit__sim_services) ;
    PyImport_AppendInittab("_top", PyInit__top) ;
    PyImport_AppendInittab("_swig_double", PyInit__swig_double) ;
    PyImport_AppendInittab("_swig_int", PyInit__swig_int) ;
    PyImport_AppendInittab("_swig_ref", PyInit__swig_ref) ;
    return ;
}

}
#else
extern "C" {

void init_m98f2329096201d54121e64f938fb3d34(void) ; /* /home/joey/PID_Project/SIM_Satellite/S_source.hh */
void init_m0240f8c64b71b1bf95173790bd2bf86c(void) ; /* /home/joey/PID_Project/SIM_Satellite/models/Environment/headers/earth.h */
void init_m265e504be5526dee989c51ec4f5b15e7(void) ; /* /home/joey/PID_Project/SIM_Satellite/models/ISS/headers/satellite.h */
void init_m7efb6ea2066a027908bd2887043d1b94(void) ; /* /home/joey/PID_Project/SIM_Satellite/models/STDRandomGenerator/headers/stdrandom.h */
void init_sim_services(void) ;
void init_top(void) ;
void init_swig_double(void) ;
void init_swig_int(void) ;
void init_swig_ref(void) ;

void init_swig_modules(void) {

    init_m0240f8c64b71b1bf95173790bd2bf86c() ;
    init_m265e504be5526dee989c51ec4f5b15e7() ;
    init_m7efb6ea2066a027908bd2887043d1b94() ;
    init_m98f2329096201d54121e64f938fb3d34() ;
    init_sim_services() ;
    init_top() ;
    init_swig_double() ;
    init_swig_int() ;
    init_swig_ref() ;
    return ;
}

}
#endif
