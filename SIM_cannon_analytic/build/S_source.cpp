
/* Created 2019/01/22 22:29:12 root $ */
#include "../S_source.hh"



SimEnvironment trick_env ;

int SysSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            sched.process_sim_args() ;
            break ;
        case 1:
            sched.get_freeze_job(name + ".sched") ;
            break ;
        case 2:
            exec_collect_init() ;
            break ;
        case 3:
            sched.write_s_run_summary(NULL) ;
            break ;
        case 4:
            sched.check_all_jobs_handled() ;
            break ;
        case 5:
            sched.check_all_job_cycle_times() ;
            break ;
        case 6:
            sched.create_threads() ;
            break ;
        case 7:
            sched.write_s_job_execution(NULL) ;
            break ;
        case 8:
            sched.async_freeze_to_exec_command() ;
            break ;
        case 9:
            sched.checkpoint() ;
            break ;
        case 10:
            sched.post_checkpoint() ;
            break ;
        case 11:
            exec_collect_init() ;
            break ;
        case 12:
            sched.write_s_job_execution(NULL) ;
            break ;
        case 13:
            sched.write_s_run_summary(NULL) ;
            break ;
        case 14:
            sched.sched_freeze_to_exec_command(false) ;
            break ;
        case 15:
            sched.sched_freeze_to_exec_command(true) ;
            break ;
        case 16:
            sched.async_freeze_to_exec_command() ;
            break ;
        case 17:
            sched.init_freeze_scheduled() ;
            break ;
        case 18:
            sched.advance_sim_time() ;
            break ;
        case 19:
            sched.thread_sync() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double SysSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int MonteCarloSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            mc.process_sim_args() ;
            break ;
        case 1:
            mc.execute_monte() ;
            break ;
        case 2:
            mc.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double MonteCarloSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int MemoryManagerSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double MemoryManagerSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int CheckPointRestartSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            cpr.find_write_checkpoint_jobs(name + ".cpr") ;
            break ;
        case 1:
            cpr.load_default_data() ;
            break ;
        case 2:
            cpr.write_pre_init_checkpoint() ;
            break ;
        case 3:
            cpr.write_post_init_checkpoint() ;
            break ;
        case 4:
            cpr.write_checkpoint() ;
            break ;
        case 5:
            cpr.write_dmtcp_checkpoint() ;
            break ;
        case 6:
            cpr.safestore_checkpoint() ;
            break ;
        case 7:
            cpr.write_end_checkpoint() ;
            break ;
        case 8:
            cpr.load_checkpoint_job() ;
            break ;
        case 9:
            cpr.load_checkpoint_job() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double CheckPointRestartSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int SieSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            sie.process_sim_args() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double SieSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int CommandLineArgumentsSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double CommandLineArgumentsSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int MessageSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            mpublisher.subscribe(&mcout) ;
            break ;
        case 1:
            mpublisher.subscribe(&mfile) ;
            break ;
        case 2:
            mpublisher.subscribe(&mdevice) ;
            break ;
        case 3:
            mpublisher.subscribe(&pfile) ;
            break ;
        case 4:
            mdevice.default_data() ;
            break ;
        case 5:
            mpublisher.init() ;
            break ;
        case 6:
            mfile.init() ;
            break ;
        case 7:
            pfile.init() ;
            break ;
        case 8:
            mdevice.init() ;
            break ;
        case 9:
            mpublisher.init() ;
            break ;
        case 10:
            mdevice.restart() ;
            break ;
        case 11:
            mdevice.restart() ;
            break ;
        case 12:
            mtcout.shutdown() ;
            break ;
        case 13:
            mdevice.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double MessageSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int JITSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            jit.process_sim_args() ;
            break ;
        case 1:
            trick_ret = jit.init() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double JITSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int InputProcessorSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            ip.process_sim_args() ;
            break ;
        case 1:
            ip.init() ;
            break ;
        case 2:
            ip.restart() ;
            break ;
        case 3:
            ip.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double InputProcessorSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int ThreadProcessEventSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            ep.add_pending_events(exec_get_time_tics()) ;
            break ;
        case 1:
            ep.add_pending_events(exec_get_time_tics(), true) ;
            break ;
        case 2:
            ep.add_pending_events(exec_get_time_tics()) ;
            break ;
        case 3:
            ep.process_event(exec_get_time_tics()) ;
            break ;
        case 4:
            ep.preload_checkpoint() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double ThreadProcessEventSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int EventManagerSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            create_thread_process_event() ;
            break ;
        case 1:
            ep.add_pending_events(exec_get_time_tics()) ;
            break ;
        case 2:
            ep.add_pending_events(exec_get_time_tics(), true) ;
            break ;
        case 3:
            ep.add_pending_events(exec_get_time_tics()) ;
            break ;
        case 4:
            ep.process_event(exec_get_time_tics()) ;
            break ;
        case 5:
            em.time_tic_changed() ;
            break ;
        case 6:
            em.preload_checkpoint() ;
            break ;
        case 7:
            ep.preload_checkpoint() ;
            break ;
        case 8:
            em.restart() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double EventManagerSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int VariableServerSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            vs.default_data() ;
            break ;
        case 1:
            trick_ret = vs.init() ;
            break ;
        case 2:
            trick_ret = vs.init() ;
            break ;
        case 3:
            monte_carlo_disable_all_apps() ;
            break ;
        case 4:
            Trick::launch_all_external_applications() ;
            break ;
        case 5:
            vs.restart() ;
            break ;
        case 6:
            Trick::launch_all_external_applications() ;
            break ;
        case 7:
            vs.suspendPreCheckpointReload() ;
            break ;
        case 8:
            vs.restart() ;
            break ;
        case 9:
            vs.resumePostCheckpointReload() ;
            break ;
        case 10:
            vs.copy_data_top() ;
            break ;
        case 11:
            vs.copy_data_scheduled() ;
            break ;
        case 12:
            vs.freeze_init() ;
            break ;
        case 13:
            vs.copy_data_freeze_scheduled() ;
            break ;
        case 14:
            vs.copy_data_freeze() ;
            break ;
        case 15:
            vs.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double VariableServerSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int DataRecordDispatcherSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            drd.remove_files() ;
            break ;
        case 1:
            drd.init() ;
            break ;
        case 2:
            drd.remove_files() ;
            break ;
        case 3:
            drd.signal_thread() ;
            break ;
        case 4:
            drd.preload_checkpoint() ;
            break ;
        case 5:
            drd.restart() ;
            break ;
        case 6:
            drd.dmtcp_restart() ;
            break ;
        case 7:
            drd.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double DataRecordDispatcherSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int RTSyncSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            rt_sync.get_sim_start_time() ;
            break ;
        case 1:
            rt_sync.rt_clock->calc_sim_time_ratio(exec_get_time_tic_value()) ;
            break ;
        case 2:
            trick_ret = rt_sync.initialize() ;
            break ;
        case 3:
            rt_sync.start_realtime(exec_get_software_frame() , exec_get_time_tics()) ;
            break ;
        case 4:
            rt_sync.get_sim_end_init_time() ;
            break ;
        case 5:
            rt_sync.restart(exec_get_time_tics()) ;
            break ;
        case 6:
            rt_sync.restart(exec_get_time_tics()) ;
            break ;
        case 7:
            rt_sync.freeze_init(exec_get_freeze_frame()) ;
            break ;
        case 8:
            rt_sync.freeze_pause(exec_get_freeze_frame()) ;
            break ;
        case 9:
            rt_sync.unfreeze(exec_get_time_tics(), exec_get_software_frame()) ;
            break ;
        case 10:
            rt_sync.rt_monitor(exec_get_time_tics()) ;
            break ;
        case 11:
            rt_sync.get_sim_end_time() ;
            break ;
        case 12:
            rt_sync.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double RTSyncSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int FrameLogSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            frame_log.frame_clock_start(curr_job) ;
            break ;
        case 1:
            frame_log.frame_clock_stop(curr_job) ;
            break ;
        case 2:
            frame_log.default_data() ;
            break ;
        case 3:
            frame_log.create_DP_files() ;
            break ;
        case 4:
            frame_log.clear_data_record_info() ;
            break ;
        case 5:
            frame_log.restart() ;
            break ;
        case 6:
            frame_log.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double FrameLogSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int MasterSlaveSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            master.process_sim_args() ;
            break ;
        case 1:
            slave.process_sim_args() ;
            break ;
        case 2:
            master.init() ;
            break ;
        case 3:
            slave.init() ;
            break ;
        case 4:
            master.checkpoint() ;
            break ;
        case 5:
            master.preload_checkpoint() ;
            break ;
        case 6:
            master.checkpoint() ;
            break ;
        case 7:
            slave.dmtcp_restart() ;
            break ;
        case 8:
            master.end_of_frame_status_from_slave() ;
            break ;
        case 9:
            master.end_of_frame_status_to_slave() ;
            break ;
        case 10:
            slave.end_of_frame() ;
            break ;
        case 11:
            master.freeze_init() ;
            break ;
        case 12:
            slave.freeze_init() ;
            break ;
        case 13:
            master.freeze() ;
            break ;
        case 14:
            slave.freeze() ;
            break ;
        case 15:
            master.unfreeze() ;
            break ;
        case 16:
            slave.unfreeze() ;
            break ;
        case 17:
            master.shutdown() ;
            break ;
        case 18:
            slave.shutdown() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double MasterSlaveSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int InstrumentationSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            echo_jobs.echo_job(curr_job) ;
            break ;
        case 1:
            debug_pause.debug_pause(curr_job) ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double InstrumentationSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int DMTCPSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            dmtcp.init() ;
            break ;
        case 1:
            dmtcp.freeze() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double DMTCPSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int InjectorExecSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            rtie.Exec() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double InjectorExecSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int InjectorSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            create_injector_executors() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double InjectorSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int ZeroconfSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            zc.init() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double ZeroconfSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int UnitTestSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            unit_tests.write_output() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double UnitTestSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int UdUnitsSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            udunits.read_default_xml() ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double UdUnitsSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}

int CannonSimObject::call_function ( Trick::JobData * curr_job ) {

    int trick_ret = 0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        case 0:
            cannon_default_data( &cannon ) ;
            break ;
        case 1:
            cannon_init( &cannon ) ;
            break ;
        case 2:
            cannon_analytic( &cannon ) ;
            break ;
        case 3:
            cannon_shutdown( &cannon ) ;
            break ;
        default:
            trick_ret = -1 ;
            break ;
    }

    return(trick_ret) ;
}

double CannonSimObject::call_function_double ( Trick::JobData * curr_job ) {

    double trick_ret = 0.0 ;
    if ( curr_job->disabled ) return (trick_ret) ;

    switch ( curr_job->id ) {
        default:
            trick_ret = 0.0 ;
            break ;
    }

    return(trick_ret) ;
}


// Instantiate stuff
SysSimObject trick_sys ;
MonteCarloSimObject trick_mc ;
MemoryManagerSimObject trick_mm ;
CheckPointRestartSimObject trick_cpr ;
SieSimObject trick_sie ;
CommandLineArgumentsSimObject trick_cmd_args ;
MessageSimObject trick_message ;
JITSimObject trick_jit ;
InputProcessorSimObject trick_ip ;
EventManagerSimObject trick_em ;
VariableServerSimObject trick_vs ;
DataRecordDispatcherSimObject trick_data_record ;
RTSyncSimObject trick_real_time ;
FrameLogSimObject trick_frame_log(trick_real_time.gtod_clock) ;
MasterSlaveSimObject trick_master_slave ;
InstrumentationSimObject trick_instruments ;
DMTCPSimObject trick_dmtcp ;
InjectorSimObject trick_inject ;
ZeroconfSimObject trick_zero_conf ;
UnitTestSimObject trick_utest ;
UdUnitsSimObject trick_udunits;
CannonSimObject dyn ;

// Integration Loop Sim Object(s) JMP

/* Default Environment */
SimEnvironment::SimEnvironment() {

    local_env["TRICK_CC"] = "/usr/bin/gcc";
    setenv("TRICK_CC", local_env["TRICK_CC"].c_str(), 0);
    local_env["TRICK_CFLAGS"] = " -Imodels";
    setenv("TRICK_CFLAGS", local_env["TRICK_CFLAGS"].c_str(), 1);
    local_env["TRICK_CONVERT_SWIG_FLAGS"] = "";
    setenv("TRICK_CONVERT_SWIG_FLAGS", local_env["TRICK_CONVERT_SWIG_FLAGS"].c_str(), 0);
    local_env["TRICK_CPPC"] = "/usr/bin/g++";
    setenv("TRICK_CPPC", local_env["TRICK_CPPC"].c_str(), 0);
    local_env["TRICK_CXXFLAGS"] = " -Imodels";
    setenv("TRICK_CXXFLAGS", local_env["TRICK_CXXFLAGS"].c_str(), 1);
    local_env["TRICK_DEBUG"] = "0";
    setenv("TRICK_DEBUG", local_env["TRICK_DEBUG"].c_str(), 0);
    local_env["TRICK_EDITOR"] = "";
    setenv("TRICK_EDITOR", local_env["TRICK_EDITOR"].c_str(), 0);
    local_env["TRICK_EXEC_LINK_LIBS"] = " -L/usr/lib -lpython2.7 -lpthread -ldl  -lutil -lm -ludunits2 -lrt -lm -ldl";
    setenv("TRICK_EXEC_LINK_LIBS", local_env["TRICK_EXEC_LINK_LIBS"].c_str(), 0);
    local_env["TRICK_EXT_LIB_DIRS"] = "";
    setenv("TRICK_EXT_LIB_DIRS", local_env["TRICK_EXT_LIB_DIRS"].c_str(), 0);
    local_env["TRICK_FORCE_32BIT"] = "0";
    setenv("TRICK_FORCE_32BIT", local_env["TRICK_FORCE_32BIT"].c_str(), 0);
    local_env["TRICK_GTE_EXT"] = "";
    setenv("TRICK_GTE_EXT", local_env["TRICK_GTE_EXT"].c_str(), 0);
    local_env["TRICK_HOME"] = "/usr/local";
    setenv("TRICK_HOME", local_env["TRICK_HOME"].c_str(), 0);
    local_env["TRICK_HOST_CPU"] = "Linux_5.4_x86_64";
    setenv("TRICK_HOST_CPU", local_env["TRICK_HOST_CPU"].c_str(), 0);
    local_env["TRICK_HOST_CPU_USER_SUFFIX"] = "";
    setenv("TRICK_HOST_CPU_USER_SUFFIX", local_env["TRICK_HOST_CPU_USER_SUFFIX"].c_str(), 0);
    local_env["TRICK_HOST_TYPE"] = "Linux";
    setenv("TRICK_HOST_TYPE", local_env["TRICK_HOST_TYPE"].c_str(), 0);
    local_env["TRICK_ICGFLAGS"] = "";
    setenv("TRICK_ICGFLAGS", local_env["TRICK_ICGFLAGS"].c_str(), 0);
    local_env["TRICK_ICG_COMPAT15"] = "";
    setenv("TRICK_ICG_COMPAT15", local_env["TRICK_ICG_COMPAT15"].c_str(), 0);
    local_env["TRICK_ICG_EXCLUDE"] = "";
    setenv("TRICK_ICG_EXCLUDE", local_env["TRICK_ICG_EXCLUDE"].c_str(), 0);
    local_env["TRICK_ICG_IGNORE_TYPES"] = "";
    setenv("TRICK_ICG_IGNORE_TYPES", local_env["TRICK_ICG_IGNORE_TYPES"].c_str(), 0);
    local_env["TRICK_ICG_NOCOMMENT"] = "";
    setenv("TRICK_ICG_NOCOMMENT", local_env["TRICK_ICG_NOCOMMENT"].c_str(), 0);
    local_env["TRICK_LDFLAGS"] = "";
    setenv("TRICK_LDFLAGS", local_env["TRICK_LDFLAGS"].c_str(), 0);
    local_env["TRICK_MAKE"] = "";
    setenv("TRICK_MAKE", local_env["TRICK_MAKE"].c_str(), 0);
    local_env["TRICK_PATH"] = "/usr/local/libexec/bin";
    setenv("TRICK_PATH", local_env["TRICK_PATH"].c_str(), 0);
    local_env["TRICK_PRINTER_NAME"] = "";
    setenv("TRICK_PRINTER_NAME", local_env["TRICK_PRINTER_NAME"].c_str(), 0);
    local_env["TRICK_PRINT_CMD"] = "lpr";
    setenv("TRICK_PRINT_CMD", local_env["TRICK_PRINT_CMD"].c_str(), 0);
    local_env["TRICK_PYTHON_PATH"] = "";
    setenv("TRICK_PYTHON_PATH", local_env["TRICK_PYTHON_PATH"].c_str(), 0);
    local_env["TRICK_SFLAGS"] = "";
    setenv("TRICK_SFLAGS", local_env["TRICK_SFLAGS"].c_str(), 0);
    local_env["TRICK_SWIG_EXCLUDE"] = "";
    setenv("TRICK_SWIG_EXCLUDE", local_env["TRICK_SWIG_EXCLUDE"].c_str(), 0);
    local_env["TRICK_SYSTEM_CFLAGS"] = "-I/usr/local/trick_source -I/usr/local/include -I/usr/local/include/trick/compat -DTRICK_VER=17 -DTRICK_MINOR=4 -fpic  -DUSE_ER7_UTILS_INTEGRATORS -fexceptions ";
    setenv("TRICK_SYSTEM_CFLAGS", local_env["TRICK_SYSTEM_CFLAGS"].c_str(), 0);
    local_env["TRICK_SYSTEM_CXXFLAGS"] = "-I/usr/local/trick_source -I/usr/local/include -I/usr/local/include/trick/compat -DTRICK_VER=17 -DTRICK_MINOR=4 -fpic  -DUSE_ER7_UTILS_INTEGRATORS ";
    setenv("TRICK_SYSTEM_CXXFLAGS", local_env["TRICK_SYSTEM_CXXFLAGS"].c_str(), 0);
    local_env["TRICK_SYSTEM_LDFLAGS"] = "-Wl,--export-dynamic";
    setenv("TRICK_SYSTEM_LDFLAGS", local_env["TRICK_SYSTEM_LDFLAGS"].c_str(), 0);
    local_env["TRICK_USER_CSHRC"] = "/root/.Trick_user_cshrc";
    setenv("TRICK_USER_CSHRC", local_env["TRICK_USER_CSHRC"].c_str(), 0);
    local_env["TRICK_USER_HOME"] = "/root/trick_sims";
    setenv("TRICK_USER_HOME", local_env["TRICK_USER_HOME"].c_str(), 0);
    local_env["TRICK_USER_LINK_LIBS"] = "";
    setenv("TRICK_USER_LINK_LIBS", local_env["TRICK_USER_LINK_LIBS"].c_str(), 0);
    local_env["TRICK_USER_PROFILE"] = "/root/.Trick_user_profile";
    setenv("TRICK_USER_PROFILE", local_env["TRICK_USER_PROFILE"].c_str(), 0);
    local_env["TRICK_VER"] = "trick_dev";
    setenv("TRICK_VER", local_env["TRICK_VER"].c_str(), 0);
    local_env["XML_CATALOG_FILES"] = "/usr/local/libexec/trick_source/data_products/DPX/XML/catalog.xml";
    setenv("XML_CATALOG_FILES", local_env["XML_CATALOG_FILES"].c_str(), 0);
}

Trick::ClassSizeCheck * Trick::ClassSizeCheck::pInstance = NULL ;

/* Memory Init */
void memory_init( void ) {

    ALLOC_INFO * ai ;
    exec_set_version_date_tag( "@(#)CP Version 17.4.dev, Tue Jan 22 22:29:12 2019" ) ;
    exec_set_build_date( "Tue Jan 22 22:29:12 2019" ) ;
    exec_set_current_version( "17.4.dev" ) ;

    populate_sim_services_class_map() ;
    populate_sim_services_enum_map() ;
    populate_class_map() ;
    populate_enum_map() ;

    exec_add_scheduled_job_class("automatic") ;
    exec_add_scheduled_job_class("random") ;
    exec_add_scheduled_job_class("environment") ;
    exec_add_scheduled_job_class("sensor") ;
    exec_add_scheduled_job_class("sensor_emitter") ;
    exec_add_scheduled_job_class("sensor_reflector") ;
    exec_add_scheduled_job_class("sensor_receiver") ;
    exec_add_scheduled_job_class("scheduled") ;
    exec_add_scheduled_job_class("effector") ;
    exec_add_scheduled_job_class("effector_emitter") ;
    exec_add_scheduled_job_class("effector_receiver") ;
    exec_add_scheduled_job_class("automatic_last") ;
    exec_add_scheduled_job_class("logging") ;
    exec_add_scheduled_job_class("data_record") ;
    exec_add_scheduled_job_class("system_checkpoint") ;
    exec_add_scheduled_job_class("system_advance_sim_time") ;
    exec_add_scheduled_job_class("system_moding") ;
    exec_add_scheduled_job_class("integ_loop") ;

    exec_add_sim_object(&trick_sys, "trick_sys") ;
    TMM_declare_ext_var(&trick_sys, TRICK_STRUCTURED,"SysSimObject", 0, "trick_sys", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_sys)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_mc, "trick_mc") ;
    TMM_declare_ext_var(&trick_mc, TRICK_STRUCTURED,"MonteCarloSimObject", 0, "trick_mc", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_mc)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_mm, "trick_mm") ;
    TMM_declare_ext_var(&trick_mm, TRICK_STRUCTURED,"MemoryManagerSimObject", 0, "trick_mm", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_mm)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_cpr, "trick_cpr") ;
    TMM_declare_ext_var(&trick_cpr, TRICK_STRUCTURED,"CheckPointRestartSimObject", 0, "trick_cpr", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_cpr)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_sie, "trick_sie") ;
    TMM_declare_ext_var(&trick_sie, TRICK_STRUCTURED,"SieSimObject", 0, "trick_sie", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_sie)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_cmd_args, "trick_cmd_args") ;
    TMM_declare_ext_var(&trick_cmd_args, TRICK_STRUCTURED,"CommandLineArgumentsSimObject", 0, "trick_cmd_args", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_cmd_args)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_message, "trick_message") ;
    TMM_declare_ext_var(&trick_message, TRICK_STRUCTURED,"MessageSimObject", 0, "trick_message", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_message)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_jit, "trick_jit") ;
    TMM_declare_ext_var(&trick_jit, TRICK_STRUCTURED,"JITSimObject", 0, "trick_jit", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_jit)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_ip, "trick_ip") ;
    TMM_declare_ext_var(&trick_ip, TRICK_STRUCTURED,"InputProcessorSimObject", 0, "trick_ip", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_ip)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_em, "trick_em") ;
    TMM_declare_ext_var(&trick_em, TRICK_STRUCTURED,"EventManagerSimObject", 0, "trick_em", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_em)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_vs, "trick_vs") ;
    TMM_declare_ext_var(&trick_vs, TRICK_STRUCTURED,"VariableServerSimObject", 0, "trick_vs", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_vs)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_data_record, "trick_data_record") ;
    TMM_declare_ext_var(&trick_data_record, TRICK_STRUCTURED,"DataRecordDispatcherSimObject", 0, "trick_data_record", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_data_record)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_real_time, "trick_real_time") ;
    TMM_declare_ext_var(&trick_real_time, TRICK_STRUCTURED,"RTSyncSimObject", 0, "trick_real_time", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_real_time)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_frame_log, "trick_frame_log") ;
    TMM_declare_ext_var(&trick_frame_log, TRICK_STRUCTURED,"FrameLogSimObject", 0, "trick_frame_log", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_frame_log)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_master_slave, "trick_master_slave") ;
    TMM_declare_ext_var(&trick_master_slave, TRICK_STRUCTURED,"MasterSlaveSimObject", 0, "trick_master_slave", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_master_slave)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_instruments, "trick_instruments") ;
    TMM_declare_ext_var(&trick_instruments, TRICK_STRUCTURED,"InstrumentationSimObject", 0, "trick_instruments", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_instruments)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_dmtcp, "trick_dmtcp") ;
    TMM_declare_ext_var(&trick_dmtcp, TRICK_STRUCTURED,"DMTCPSimObject", 0, "trick_dmtcp", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_dmtcp)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_inject, "trick_inject") ;
    TMM_declare_ext_var(&trick_inject, TRICK_STRUCTURED,"InjectorSimObject", 0, "trick_inject", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_inject)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_zero_conf, "trick_zero_conf") ;
    TMM_declare_ext_var(&trick_zero_conf, TRICK_STRUCTURED,"ZeroconfSimObject", 0, "trick_zero_conf", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_zero_conf)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_utest, "trick_utest") ;
    TMM_declare_ext_var(&trick_utest, TRICK_STRUCTURED,"UnitTestSimObject", 0, "trick_utest", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_utest)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&trick_udunits, "trick_udunits") ;
    TMM_declare_ext_var(&trick_udunits, TRICK_STRUCTURED,"UdUnitsSimObject", 0, "trick_udunits", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&trick_udunits)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    exec_add_sim_object(&dyn, "dyn") ;
    TMM_declare_ext_var(&dyn, TRICK_STRUCTURED,"CannonSimObject", 0, "dyn", 0, NULL) ;
    if ( (ai = get_alloc_info_at(&dyn)) != NULL ) {
        ai->alloced_in_memory_init = 1 ;
    }
    // Add Integration Loop Sim Object(s) JMP


    Trick::ClassSizeCheck::class_size_check()->print_nonzero_diffs() ;
    Trick::ClassSizeCheck::reset_instance() ;
    return ;
}


/*---------------------------------------------------------------------*/

void exec_collect_init( void ) {

    return ;
}

int master( int nargs, char ** args ) ;

int main( int nargs, char ** args ) {
    return master(nargs, args) ;
}
