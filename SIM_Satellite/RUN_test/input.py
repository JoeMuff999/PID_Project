execfile("Modified_Data/Satellite.dr")
time = 6000
trick.stop(time)

dyn.satellite.runtime = time
dyn.satellite.interval = .1
dyn.satellite.pid.kP = 30;
dyn.satellite.pid.kI = 0; #set to 0 because of the way controller is setup
dyn.satellite.pid.kD = 15;

#pid.setKValues(789.568,1,2513.274,1); set in input file now
#pid.setKValues(7.89,1,251.332,1);
#pid.setKValues(1,1,1,1);

# Enable Monte Carlo.
#trick.mc_set_enabled(1)

# Sets the number of runs to perform to 20. Trick will not exceed the number of values in an input file.
#trick.mc_set_num_runs(20)

# Create and add a new Monte Carlo File variable to the simulation.
#mcvar_kP = trick.MonteVarFile("dyn.satellite.pid.kP", "kValues/kP_value_list", 1)
#trick_mc.mc.add_variable(mcvar_kP)

# Stop the simulation run after 15 seconds of simulation time.
