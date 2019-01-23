%module m16b90ae9ca38ff00fe00c4cdfcd8394d

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/root/PID_Project/SIM_cannon_analytic/S_source.hh"
%}

%trick_swig_class_typemap(SimEnvironment, SimEnvironment)
%trick_swig_class_typemap(SysSimObject, SysSimObject)
%trick_swig_class_typemap(MonteCarloSimObject, MonteCarloSimObject)
%trick_swig_class_typemap(MemoryManagerSimObject, MemoryManagerSimObject)
%trick_swig_class_typemap(CheckPointRestartSimObject, CheckPointRestartSimObject)
%trick_swig_class_typemap(SieSimObject, SieSimObject)
%trick_swig_class_typemap(CommandLineArgumentsSimObject, CommandLineArgumentsSimObject)
%trick_swig_class_typemap(MessageSimObject, MessageSimObject)
%trick_swig_class_typemap(JITSimObject, JITSimObject)
%trick_swig_class_typemap(InputProcessorSimObject, InputProcessorSimObject)
%trick_swig_class_typemap(ThreadProcessEventSimObject, ThreadProcessEventSimObject)
%trick_swig_class_typemap(EventManagerSimObject, EventManagerSimObject)
%trick_swig_class_typemap(VariableServerSimObject, VariableServerSimObject)
%trick_swig_class_typemap(DataRecordDispatcherSimObject, DataRecordDispatcherSimObject)
%trick_swig_class_typemap(RTSyncSimObject, RTSyncSimObject)
%trick_swig_class_typemap(FrameLogSimObject, FrameLogSimObject)
%trick_swig_class_typemap(MasterSlaveSimObject, MasterSlaveSimObject)
%trick_swig_class_typemap(InstrumentationSimObject, InstrumentationSimObject)
%trick_swig_class_typemap(DMTCPSimObject, DMTCPSimObject)
%trick_swig_class_typemap(InjectorExecSimObject, InjectorExecSimObject)
%trick_swig_class_typemap(InjectorSimObject, InjectorSimObject)
%trick_swig_class_typemap(ZeroconfSimObject, ZeroconfSimObject)
%trick_swig_class_typemap(UnitTestSimObject, UnitTestSimObject)
%trick_swig_class_typemap(UdUnitsSimObject, UdUnitsSimObject)
%trick_swig_class_typemap(CannonSimObject, CannonSimObject)





#ifndef __S_SOURCE_HH__
#define __S_SOURCE_HH__


%import(module="sim_services") "trick/attributes.h"
%import(module="sim_services") "trick/populate_attribute_maps.hh"
%import(module="sim_services") "trick/ClassSizeCheck.hh"

%import(module="sim_services") "trick/SimObject.hh"
%import(module="sim_services") "trick/JobData.hh"
%import(module="sim_services") "trick/UnitsMap.hh"

#define ip_alloc calloc

%import(module="sim_services") "trick/AttributesMap.hh"
%import(module="sim_services") "trick/CheckPointRestart.hh"
%import(module="sim_services") "trick/CommandLineArguments.hh"
%import(module="sim_services") "trick/DMTCP.hh"
%import(module="sim_services") "trick/DataRecordDispatcher.hh"
%import(module="sim_services") "trick/DebugPause.hh"
%import(module="sim_services") "trick/EchoJobs.hh"
%import(module="sim_services") "trick/Environment.hh"
%import(module="sim_services") "trick/EventManager.hh"
%import(module="sim_services") "trick/EventManager_c_intf.hh"
%import(module="sim_services") "trick/EventProcessor.hh"
%import(module="sim_services") "trick/Executive.hh"
%import(module="sim_services") "trick/ExternalApplicationManager.hh"
%import(module="sim_services") "trick/FrameLog.hh"
%import(module="sim_services") "trick/GetTimeOfDayClock.hh"
%import(module="sim_services") "trick/IPPython.hh"
%import(module="sim_services") "trick/IPPythonEvent.hh"
%import(module="sim_services") "trick/ITimer.hh"
%import(module="sim_services") "trick/IntegLoopManager.hh"
%import(module="sim_services") "trick/IntegLoopScheduler.hh"
%import(module="sim_services") "trick/IntegLoopSimObject.hh"
%import(module="sim_services") "trick/Integrator.hh"
%import(module="sim_services") "trick/JITEvent.hh"
%import(module="sim_services") "trick/JITInputFile.hh"
%import(module="sim_services") "trick/JSONVariableServer.hh"
%import(module="sim_services") "trick/MSSharedMem.hh"
%import(module="sim_services") "trick/MSSocket.hh"
%import(module="sim_services") "trick/MTV.hh"
%import(module="sim_services") "trick/MalfunctionsTrickView.hh"
%import(module="sim_services") "trick/Master.hh"
%import(module="sim_services") "trick/MemoryManager.hh"
%import(module="sim_services") "trick/MessageCout.hh"
%import(module="sim_services") "trick/MessageFile.hh"
%import(module="sim_services") "trick/MessageLCout.hh"
%import(module="sim_services") "trick/MessagePublisher.hh"
%import(module="sim_services") "trick/MessageSubscriber.hh"
%import(module="sim_services") "trick/MessageTCDevice.hh"
%import(module="sim_services") "trick/MessageThreadedCout.hh"
%import(module="sim_services") "trick/MonteCarlo.hh"
%import(module="sim_services") "trick/MonteMonitor.hh"
%import(module="sim_services") "trick/PlaybackFile.hh"
%import(module="sim_services") "trick/RealtimeSync.hh"
%import(module="sim_services") "trick/RtiExec.hh"
%import(module="sim_services") "trick/RtiStager.hh"
%import(module="sim_services") "trick/Sie.hh"
%import(module="sim_services") "trick/SimControlPanel.hh"
%import(module="sim_services") "trick/SimObject.hh"
%import(module="sim_services") "trick/SimTime.hh"
%import(module="sim_services") "trick/Slave.hh"
%import(module="sim_services") "trick/StripChart.hh"
%import(module="sim_services") "trick/TrickView.hh"
%import(module="sim_services") "trick/UdUnits.hh"
%import(module="sim_services") "trick/UnitTest.hh"
%import(module="sim_services") "trick/VariableServer.hh"
%import(module="sim_services") "trick/Zeroconf.hh"
%import(module="sim_services") "trick/collect_proto.hh"
%import(module="sim_services") "trick/exec_proto.hh"
%import(module="sim_services") "trick/jit_input_file_proto.hh"

#ifdef __cplusplus
extern "C" {
#endif

%import "build/root/PID_Project/SIM_cannon_analytic/models/cannon/include/cannon_analytic_py.i"
%import(module="sim_services") "trick/clock_proto.h"
%import(module="sim_services") "trick/data_record_proto.h"
%import(module="sim_services") "trick/env_proto.h"
%import(module="sim_services") "trick/exec_proto.h"
%import(module="sim_services") "trick/memorymanager_c_intf.h"
%import(module="sim_services") "trick/montecarlo_c_intf.h"
%import(module="sim_services") "trick/trick_tests.h"

#ifdef __cplusplus
}
#endif





class SimEnvironment : public Trick::Environment {
    public:
       SimEnvironment() ;
};
#define TRICK_SWIG_DEFINED_SimEnvironment


void exec_collect_init( void ) ;

class SysSimObject : public Trick::SimObject {

    public:
        Trick::Executive sched ;

        SysSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "sched.process_sim_args", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "default_data", NULL, 1, "sched.get_freeze_job", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "initialization", NULL, 1, "exec_collect_init", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "initialization", NULL, 1, "sched.write_s_run_summary", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "initialization", NULL, 1, "sched.check_all_jobs_handled", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "initialization", NULL, 1, "sched.check_all_job_cycle_times", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "initialization", NULL, 1, "sched.create_threads", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "initialization", NULL, 1, "sched.write_s_job_execution", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "initialization", NULL, 1, "sched.async_freeze_to_exec_command", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 9, "checkpoint", NULL, 1, "sched.checkpoint", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 10, "post_checkpoint", NULL, 1, "sched.post_checkpoint", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 11, "restart", NULL, 1, "exec_collect_init", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 12, "dmtcp_restart", NULL, 1, "sched.write_s_job_execution", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 13, "dmtcp_restart", NULL, 1, "sched.write_s_run_summary", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 14, "system_moding", NULL, 1, "sched.sched_freeze_to_exec_command", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 15, "end_of_frame", NULL, 1, "sched.sched_freeze_to_exec_command", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 16, "end_of_frame", NULL, 1, "sched.async_freeze_to_exec_command", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 17, "freeze_init", NULL, 1, "sched.init_freeze_scheduled", "", 60000) ;
            job = this->add_job(0, 18, "system_advance_sim_time", NULL, 1, "sched.advance_sim_time", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 19, "system_thread_sync", NULL, 1, "sched.thread_sync", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;


    private:
        

        void operator =(const SysSimObject &) {};
};
#define TRICK_SWIG_DEFINED_SysSimObject

class MonteCarloSimObject : public Trick::SimObject {
    public:
        Trick::MonteCarlo mc ;

        MonteCarloSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
exec_register_scheduler(&mc) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "mc.process_sim_args", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "mc.execute_monte", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "shutdown", NULL, 1, "mc.shutdown", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_MonteCarloSimObject

class MemoryManagerSimObject : public Trick::SimObject {

    public:
        Trick::MemoryManager mm ;

        MemoryManagerSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
}

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_MemoryManagerSimObject

class CheckPointRestartSimObject : public Trick::SimObject {

    public:
        Trick::CheckPointRestart cpr ;

        CheckPointRestartSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
exec_register_scheduler(&cpr) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "cpr.find_write_checkpoint_jobs", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "default_data", NULL, 1, "cpr.load_default_data", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "initialization", NULL, 1, "cpr.write_pre_init_checkpoint", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "initialization", NULL, 1, "cpr.write_post_init_checkpoint", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "system_checkpoint", NULL, 1, "cpr.write_checkpoint", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "top_of_frame", NULL, 1, "cpr.write_dmtcp_checkpoint", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "system_checkpoint", NULL, 1, "cpr.safestore_checkpoint", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "shutdown", NULL, 1, "cpr.write_end_checkpoint", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "freeze", NULL, 1, "cpr.load_checkpoint_job", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 9, "end_of_frame", NULL, 1, "cpr.load_checkpoint_job", "", 0) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_CheckPointRestartSimObject

class SieSimObject : public Trick::SimObject {
    public:

        Trick::Sie sie ;

        SieSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "sie.process_sim_args", "", 0) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_SieSimObject

class CommandLineArgumentsSimObject : public Trick::SimObject {
    public:
        Trick::CommandLineArguments cmd_args;

        CommandLineArgumentsSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
}

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_CommandLineArgumentsSimObject

class MessageSimObject : public Trick::SimObject {

    public:
        Trick::MessagePublisher mpublisher ;
        Trick::MessageCout mcout ;
        Trick::MessageThreadedCout mtcout ;
        Trick::MessageFile mfile ;
        Trick::MessageTCDevice mdevice ;
        Trick::PlaybackFile pfile ;

        MessageSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "mpublisher.subscribe", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "default_data", NULL, 1, "mpublisher.subscribe", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "default_data", NULL, 1, "mpublisher.subscribe", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "default_data", NULL, 1, "mpublisher.subscribe", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "default_data", NULL, 1, "mdevice.default_data", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "initialization", NULL, 1, "mpublisher.init", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "initialization", NULL, 1, "mfile.init", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "initialization", NULL, 1, "pfile.init", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "initialization", NULL, 1, "mdevice.init", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 9, "exec_time_tic_changed", NULL, 1, "mpublisher.init", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 10, "restart", NULL, 1, "mdevice.restart", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 11, "dmtcp_restart", NULL, 1, "mdevice.restart", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 12, "shutdown", NULL, 1, "mtcout.shutdown", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 13, "shutdown", NULL, 1, "mdevice.shutdown", "", 60000) ;
            job->add_tag("TRK") ;

        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;


    private:
        

        void operator =(const MessageSimObject &) {};
};
#define TRICK_SWIG_DEFINED_MessageSimObject

class JITSimObject : public Trick::SimObject {
    public:
        Trick::JITInputFile jit ;

        JITSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "input_processor", NULL, 1, "jit.process_sim_args", "", 50000) ;
            job = this->add_job(0, 1, "input_processor", NULL, 1, "jit.init", "", 50000) ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_JITSimObject

class InputProcessorSimObject : public Trick::SimObject {

    public:
        Trick::IPPython ip ;
        Trick::MTV mtv ;
        Trick::UnitsMap * units_map_ptr ; 


        InputProcessorSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
units_map_ptr = Trick::UnitsMap::units_map() ;
            job = this->add_job(0, 0, "input_processor", NULL, 1, "ip.process_sim_args", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "input_processor", NULL, 1, "ip.init", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "restart", NULL, 1, "ip.restart", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "shutdown", NULL, 1, "ip.shutdown", "", 65535) ;
            job->add_tag("TRK") ;

            Trick::IPPythonEvent::set_python_processor(&ip) ;
            Trick::IPPythonEvent::set_mtv(&mtv) ;
        }

        ~InputProcessorSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
delete units_map_ptr ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_InputProcessorSimObject

class ThreadProcessEventSimObject : public Trick::SimObject {
    public:
        Trick::EventProcessor ep ;

        ThreadProcessEventSimObject(unsigned int thread_id ) {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "initialization", NULL, 1, "ep.add_pending_events", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "restart", NULL, 1, "ep.add_pending_events", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(thread_id, 2, "top_of_frame", NULL, 1, "ep.add_pending_events", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(thread_id, 3, "automatic", NULL, 1, "ep.process_event", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "preload_checkpoint", NULL, 1, "ep.preload_checkpoint", "", 60000) ;
            job->add_tag("TRK") ;

            
            ep.set_process_event_job(get_job("ep.process_event")) ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_ThreadProcessEventSimObject

class EventManagerSimObject : public Trick::SimObject {
    public:
        Trick::EventManager em ;
        Trick::EventProcessor ep ;
        std::vector< ThreadProcessEventSimObject * > thread_process_event_so ; 


        void create_thread_process_event() {
            unsigned int ii ;
            unsigned int num_threads = exec_get_num_threads() ;
            for ( ii = 1 ; ii < num_threads ; ii++ ) {
                ThreadProcessEventSimObject * tpeso = new ThreadProcessEventSimObject(ii) ;
                std::ostringstream oss ;
                oss << "thread_process_event_" << ii ;
                thread_process_event_so.push_back(tpeso) ;
                exec_add_sim_object(tpeso, oss.str().c_str()) ;
                TMM_declare_ext_var(tpeso, TRICK_STRUCTURED,"ThreadProcessEventSimObject", 0, oss.str().c_str(), 0, NULL) ;
                

                em.add_event_processor(&(tpeso->ep)) ;
            }
        }

        EventManagerSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
em.add_event_processor(&ep) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "create_thread_process_event", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "ep.add_pending_events", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "restart", NULL, 1, "ep.add_pending_events", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "top_of_frame", NULL, 1, "ep.add_pending_events", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "input_processor_run", NULL, 1, "ep.process_event", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "exec_time_tic_changed", NULL, 1, "em.time_tic_changed", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "preload_checkpoint", NULL, 1, "em.preload_checkpoint", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "preload_checkpoint", NULL, 1, "ep.preload_checkpoint", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "restart", NULL, 1, "em.restart", "", 60000) ;
            job->add_tag("TRK") ;

            
            ep.set_process_event_job(get_job("ep.process_event")) ;

        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_EventManagerSimObject

class VariableServerSimObject : public Trick::SimObject {

    public:
        Trick::VariableServer vs ;
        Trick::SimControlPanel sim_control_panel ;
        Trick::TrickView trick_view ;
        Trick::MalfunctionsTrickView malfunctions_trick_view ;
        Trick::StripChart stripchart ;

        Trick::MonteMonitor monte_monitor ;

        void monte_carlo_disable_all_apps() {
            if ( mc_get_slave_id() ) {
                Trick::remove_all_external_applications() ;
            }
        }


        VariableServerSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "vs.default_data", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "vs.init", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "monte_master_init", NULL, 1, "vs.init", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "initialization", NULL, 1, "monte_carlo_disable_all_apps", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "initialization", NULL, 1, "Trick::launch_all_external_applications", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "dmtcp_restart", NULL, 1, "vs.restart", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "dmtcp_restart", NULL, 1, "Trick::launch_all_external_applications", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "preload_checkpoint", NULL, 1, "vs.suspendPreCheckpointReload", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "restart", NULL, 1, "vs.restart", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 9, "restart", NULL, 1, "vs.resumePostCheckpointReload", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 10, "top_of_frame", NULL, 1, "vs.copy_data_top", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 11, "automatic_last", NULL, 1, "vs.copy_data_scheduled", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 12, "freeze_init", NULL, 1, "vs.freeze_init", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 13, "freeze_automatic", NULL, 1, "vs.copy_data_freeze_scheduled", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 14, "freeze", NULL, 1, "vs.copy_data_freeze", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 15, "shutdown", NULL, 1, "vs.shutdown", "", 60000) ;
            job->add_tag("TRK") ;

            
            Trick::VariableServerThread::set_vs_ptr(&vs) ;

            
            vs.set_copy_data_job(get_job("vs.copy_data_scheduled")) ;
            vs.set_copy_data_freeze_job(get_job("vs.copy_data_freeze_scheduled")) ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;


        private:

        VariableServerSimObject &operator=(const VariableServerSimObject &);
};
#define TRICK_SWIG_DEFINED_VariableServerSimObject

class DataRecordDispatcherSimObject : public Trick::SimObject {

    public:
        Trick::DataRecordDispatcher drd ;

        DataRecordDispatcherSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
exec_register_scheduler(&drd) ;
            job = this->add_job(0, 0, "initialization", NULL, 1, "drd.remove_files", "", 1) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "drd.init", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "monte_slave_init", NULL, 1, "drd.remove_files", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "end_of_frame", NULL, 1, "drd.signal_thread", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "preload_checkpoint", NULL, 1, "drd.preload_checkpoint", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "restart", NULL, 1, "drd.restart", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "dmtcp_restart", NULL, 1, "drd.dmtcp_restart", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "shutdown", NULL, 1, "drd.shutdown", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;


    private:
        void operator =(const DataRecordDispatcherSimObject &) ;
};
#define TRICK_SWIG_DEFINED_DataRecordDispatcherSimObject

class RTSyncSimObject : public Trick::SimObject {

    public:

        Trick::GetTimeOfDayClock gtod_clock ;
        Trick::ITimer itimer ;
        Trick::RealtimeSync rt_sync ;

        RTSyncSimObject() : rt_sync(&gtod_clock, &itimer) {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "rt_sync.get_sim_start_time", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "rt_sync.rt_clock->calc_sim_time_ratio", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "initialization", NULL, 1, "rt_sync.initialize", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "initialization", NULL, 1, "rt_sync.start_realtime", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "initialization", NULL, 1, "rt_sync.get_sim_end_init_time", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "restart", NULL, 1, "rt_sync.restart", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "dmtcp_restart", NULL, 1, "rt_sync.restart", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "freeze_init", NULL, 1, "rt_sync.freeze_init", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "freeze", NULL, 1, "rt_sync.freeze_pause", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 9, "unfreeze", NULL, 1, "rt_sync.unfreeze", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 10, "end_of_frame", NULL, 1, "rt_sync.rt_monitor", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 11, "shutdown", NULL, 1, "rt_sync.get_sim_end_time", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 12, "shutdown", NULL, 1, "rt_sync.shutdown", "", 65535) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_RTSyncSimObject

class FrameLogSimObject : public Trick::SimObject {

    public:

        Trick::FrameLog frame_log ;

        FrameLogSimObject(Trick::Clock &in_clock) : frame_log(in_clock) {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "instrumentation", NULL, 1, "frame_log.frame_clock_start", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "instrumentation", NULL, 1, "frame_log.frame_clock_stop", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "default_data", NULL, 1, "frame_log.default_data", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "initialization", NULL, 1, "frame_log.create_DP_files", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "restart", NULL, 1, "frame_log.clear_data_record_info", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "restart", NULL, 1, "frame_log.restart", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "shutdown", NULL, 1, "frame_log.shutdown", "", 65535) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;


    private:
        

        void operator =(const FrameLogSimObject &) {};
};
#define TRICK_SWIG_DEFINED_FrameLogSimObject

class MasterSlaveSimObject : public Trick::SimObject {

    public:

        Trick::Master master ;
        Trick::Slave slave ;

        MasterSlaveSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "initialization", NULL, 1, "master.process_sim_args", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "slave.process_sim_args", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 2, "initialization", NULL, 1, "master.init", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 3, "initialization", NULL, 1, "slave.init", "", 0) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 4, "checkpoint", NULL, 1, "master.checkpoint", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 5, "preload_checkpoint", NULL, 1, "master.preload_checkpoint", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 6, "dmtcp_pre", NULL, 1, "master.checkpoint", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 7, "dmtcp_restart", NULL, 1, "slave.dmtcp_restart", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 8, "end_of_frame", NULL, 1, "master.end_of_frame_status_from_slave", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 9, "end_of_frame", NULL, 1, "master.end_of_frame_status_to_slave", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 10, "end_of_frame", NULL, 1, "slave.end_of_frame", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 11, "freeze_init", NULL, 1, "master.freeze_init", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 12, "freeze_init", NULL, 1, "slave.freeze_init", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 13, "freeze", NULL, 1, "master.freeze", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 14, "freeze", NULL, 1, "slave.freeze", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 15, "unfreeze", NULL, 1, "master.unfreeze", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 16, "unfreeze", NULL, 1, "slave.unfreeze", "", 65535) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 17, "shutdown", NULL, 1, "master.shutdown", "", 65534) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 18, "shutdown", NULL, 1, "slave.shutdown", "", 65534) ;
            job->add_tag("TRK") ;

        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_MasterSlaveSimObject

class InstrumentationSimObject : public Trick::SimObject {

    public:
        Trick::EchoJobs echo_jobs ;
        Trick::DebugPause debug_pause ;

        InstrumentationSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "instrumentation", NULL, 1, "echo_jobs.echo_job", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "instrumentation", NULL, 1, "debug_pause.debug_pause", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_InstrumentationSimObject

class DMTCPSimObject : public Trick::SimObject {
    public:
        Trick::DMTCP dmtcp ;
        DMTCPSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
exec_register_scheduler(&dmtcp) ;
            job = this->add_job(0, 0, "initialization", NULL, 1, "dmtcp.init", "", 60000) ;
            job->add_tag("TRK") ;
            job = this->add_job(0, 1, "freeze", NULL, 1, "dmtcp.freeze", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_DMTCPSimObject

class InjectorExecSimObject : public Trick::SimObject {
    public:
        Trick::RtiExec rtie ;
        InjectorExecSimObject(unsigned int thread_id ) {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(thread_id, 0, "top_of_frame", NULL, 1, "rtie.Exec", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_InjectorExecSimObject

class InjectorSimObject : public Trick::SimObject {

    public:
        Trick::RtiStager rtis ;
        std::vector< InjectorExecSimObject * > injector_executor_so ; 


        void create_injector_executors() {
            unsigned int ii ;
            unsigned int num_threads = exec_get_num_threads() ;
            for ( ii = 0 ; ii < num_threads ; ii++ ) {
                InjectorExecSimObject * ieso = new InjectorExecSimObject(ii) ;
                std::ostringstream oss ;
                oss << "trick_injector_executor_" << ii ;
                injector_executor_so.push_back(ieso) ;
                exec_add_sim_object(ieso, oss.str().c_str()) ;
                TMM_declare_ext_var(ieso, TRICK_STRUCTURED,"InjectorExecSimObject", 0, oss.str().c_str(), 0, NULL) ;
                

                rtis.AddInjectorExecutor(&(ieso->rtie)) ;
            }
        }

        InjectorSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "create_injector_executors", "", 0) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_InjectorSimObject

class ZeroconfSimObject : public Trick::SimObject {
    public:
        Trick::Zeroconf zc ;
        ZeroconfSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "initialization", NULL, 1, "zc.init", "", 60000) ;
            job->add_tag("TRK") ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_ZeroconfSimObject

class UnitTestSimObject : public Trick::SimObject {
    public:
        Trick::UnitTest unit_tests ;
        UnitTestSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "shutdown", NULL, 1, "unit_tests.write_output", "", 65535) ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_UnitTestSimObject

class UdUnitsSimObject : public Trick::SimObject {
    public:
        Trick::UdUnits udunits ;
        UdUnitsSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "udunits.read_default_xml", "", 65535) ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_UdUnitsSimObject

class CannonSimObject : public Trick::SimObject {

    public:
        CANNON cannon;

        CannonSimObject() {
            Trick::JobData * job __attribute__((unused)) ;
            job = this->add_job(0, 0, "default_data", NULL, 1, "cannon_default_data", "", 60000) ;
            job = this->add_job(0, 1, "initialization", NULL, 1, "cannon_init", "", 60000) ;
            job = this->add_job(0, 2, "scheduled", NULL, 0.01, "cannon_analytic", "", 60000) ;
            job = this->add_job(0, 3, "shutdown", NULL, 1, "cannon_shutdown", "", 60000) ;
        }

    public:
        virtual int call_function( Trick::JobData * curr_job ) ;
        virtual double call_function_double( Trick::JobData * curr_job ) ;

};
#define TRICK_SWIG_DEFINED_CannonSimObject

#ifdef TRICK_ICG
#endif

#ifndef SWIG
extern SysSimObject trick_sys ;
extern MonteCarloSimObject trick_mc ;
extern MemoryManagerSimObject trick_mm ;
extern CheckPointRestartSimObject trick_cpr ;
extern SieSimObject trick_sie ;
extern CommandLineArgumentsSimObject trick_cmd_args ;
extern MessageSimObject trick_message ;
extern JITSimObject trick_jit ;
extern InputProcessorSimObject trick_ip ;
extern EventManagerSimObject trick_em ;
extern VariableServerSimObject trick_vs ;
extern DataRecordDispatcherSimObject trick_data_record ;
extern RTSyncSimObject trick_real_time ;
extern FrameLogSimObject trick_frame_log;
extern MasterSlaveSimObject trick_master_slave ;
extern InstrumentationSimObject trick_instruments ;
extern DMTCPSimObject trick_dmtcp ;
extern InjectorSimObject trick_inject ;
extern ZeroconfSimObject trick_zero_conf ;
extern UnitTestSimObject trick_utest ;
extern UdUnitsSimObject trick_udunits;
extern CannonSimObject dyn ;
#endif


#endif

#ifdef TRICK_SWIG_DEFINED_SimEnvironment
%trick_cast_as(SimEnvironment, SimEnvironment)
#endif
#ifdef TRICK_SWIG_DEFINED_SysSimObject
%trick_cast_as(SysSimObject, SysSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_MonteCarloSimObject
%trick_cast_as(MonteCarloSimObject, MonteCarloSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_MemoryManagerSimObject
%trick_cast_as(MemoryManagerSimObject, MemoryManagerSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_CheckPointRestartSimObject
%trick_cast_as(CheckPointRestartSimObject, CheckPointRestartSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_SieSimObject
%trick_cast_as(SieSimObject, SieSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_CommandLineArgumentsSimObject
%trick_cast_as(CommandLineArgumentsSimObject, CommandLineArgumentsSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_MessageSimObject
%trick_cast_as(MessageSimObject, MessageSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_JITSimObject
%trick_cast_as(JITSimObject, JITSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_InputProcessorSimObject
%trick_cast_as(InputProcessorSimObject, InputProcessorSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_ThreadProcessEventSimObject
%trick_cast_as(ThreadProcessEventSimObject, ThreadProcessEventSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_EventManagerSimObject
%trick_cast_as(EventManagerSimObject, EventManagerSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_VariableServerSimObject
%trick_cast_as(VariableServerSimObject, VariableServerSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_DataRecordDispatcherSimObject
%trick_cast_as(DataRecordDispatcherSimObject, DataRecordDispatcherSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_RTSyncSimObject
%trick_cast_as(RTSyncSimObject, RTSyncSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_FrameLogSimObject
%trick_cast_as(FrameLogSimObject, FrameLogSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_MasterSlaveSimObject
%trick_cast_as(MasterSlaveSimObject, MasterSlaveSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_InstrumentationSimObject
%trick_cast_as(InstrumentationSimObject, InstrumentationSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_DMTCPSimObject
%trick_cast_as(DMTCPSimObject, DMTCPSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_InjectorExecSimObject
%trick_cast_as(InjectorExecSimObject, InjectorExecSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_InjectorSimObject
%trick_cast_as(InjectorSimObject, InjectorSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_ZeroconfSimObject
%trick_cast_as(ZeroconfSimObject, ZeroconfSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_UnitTestSimObject
%trick_cast_as(UnitTestSimObject, UnitTestSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_UdUnitsSimObject
%trick_cast_as(UdUnitsSimObject, UdUnitsSimObject)
#endif
#ifdef TRICK_SWIG_DEFINED_CannonSimObject
%trick_cast_as(CannonSimObject, CannonSimObject)
#endif
