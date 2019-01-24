#include <Python.h>
#if PY_VERSION_HEX >= 0x03000000
extern "C" {

PyObject * PyInit__mbec6de62925f3041cb8a23383c3e4ac2(void) ; /* /root/PID_Project/Satellite/S_source.hh */
PyObject * PyInit__mfdff56e8d3eba163ff89f67962c185fe(void) ; /* /root/PID_Project/Satellite/models/ISS/headers/satellite.h */
PyObject * PyInit__mf35f39864a9115e02690bd9f80f33b23(void) ; /* /root/PID_Project/Satellite/models/ISS/headers/satellite_analytic.h */
PyObject * PyInit__sim_services(void) ;
PyObject * PyInit__top(void) ;
PyObject * PyInit__swig_double(void) ;
PyObject * PyInit__swig_int(void) ;
PyObject * PyInit__swig_ref(void) ;

void init_swig_modules(void) {

    PyImport_AppendInittab("_mfdff56e8d3eba163ff89f67962c185fe", PyInit__mfdff56e8d3eba163ff89f67962c185fe) ;
    PyImport_AppendInittab("_mf35f39864a9115e02690bd9f80f33b23", PyInit__mf35f39864a9115e02690bd9f80f33b23) ;
    PyImport_AppendInittab("_mbec6de62925f3041cb8a23383c3e4ac2", PyInit__mbec6de62925f3041cb8a23383c3e4ac2) ;
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

void init_mbec6de62925f3041cb8a23383c3e4ac2(void) ; /* /root/PID_Project/Satellite/S_source.hh */
void init_mfdff56e8d3eba163ff89f67962c185fe(void) ; /* /root/PID_Project/Satellite/models/ISS/headers/satellite.h */
void init_mf35f39864a9115e02690bd9f80f33b23(void) ; /* /root/PID_Project/Satellite/models/ISS/headers/satellite_analytic.h */
void init_sim_services(void) ;
void init_top(void) ;
void init_swig_double(void) ;
void init_swig_int(void) ;
void init_swig_ref(void) ;

void init_swig_modules(void) {

    init_mfdff56e8d3eba163ff89f67962c185fe() ;
    init_mf35f39864a9115e02690bd9f80f33b23() ;
    init_mbec6de62925f3041cb8a23383c3e4ac2() ;
    init_sim_services() ;
    init_top() ;
    init_swig_double() ;
    init_swig_int() ;
    init_swig_ref() ;
    return ;
}

}
#endif
