#include <Python.h>
#if PY_VERSION_HEX >= 0x03000000
extern "C" {

PyObject * PyInit__m16b90ae9ca38ff00fe00c4cdfcd8394d(void) ; /* /root/PID_Project/SIM_cannon_analytic/S_source.hh */
PyObject * PyInit__me2b567c1ad62da055c8123315a993d30(void) ; /* /root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon.h */
PyObject * PyInit__m8c15403d0f0788188a0cd132ec8cd2e3(void) ; /* /root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon_analytic.h */
PyObject * PyInit__sim_services(void) ;
PyObject * PyInit__top(void) ;
PyObject * PyInit__swig_double(void) ;
PyObject * PyInit__swig_int(void) ;
PyObject * PyInit__swig_ref(void) ;

void init_swig_modules(void) {

    PyImport_AppendInittab("_me2b567c1ad62da055c8123315a993d30", PyInit__me2b567c1ad62da055c8123315a993d30) ;
    PyImport_AppendInittab("_m8c15403d0f0788188a0cd132ec8cd2e3", PyInit__m8c15403d0f0788188a0cd132ec8cd2e3) ;
    PyImport_AppendInittab("_m16b90ae9ca38ff00fe00c4cdfcd8394d", PyInit__m16b90ae9ca38ff00fe00c4cdfcd8394d) ;
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

void init_m16b90ae9ca38ff00fe00c4cdfcd8394d(void) ; /* /root/PID_Project/SIM_cannon_analytic/S_source.hh */
void init_me2b567c1ad62da055c8123315a993d30(void) ; /* /root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon.h */
void init_m8c15403d0f0788188a0cd132ec8cd2e3(void) ; /* /root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon_analytic.h */
void init_sim_services(void) ;
void init_top(void) ;
void init_swig_double(void) ;
void init_swig_int(void) ;
void init_swig_ref(void) ;

void init_swig_modules(void) {

    init_me2b567c1ad62da055c8123315a993d30() ;
    init_m8c15403d0f0788188a0cd132ec8cd2e3() ;
    init_m16b90ae9ca38ff00fe00c4cdfcd8394d() ;
    init_sim_services() ;
    init_top() ;
    init_swig_double() ;
    init_swig_int() ;
    init_swig_ref() ;
    return ;
}

}
#endif
