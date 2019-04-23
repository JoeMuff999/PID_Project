execfile("Modified_Data/Satellite.dr")
trick.stop(20)
# Enable Monte Carlo.
#trick.mc_set_enabled(1)

# Sets the number of runs to perform to 20. Trick will not exceed the number of values in an input file.
#trick.mc_set_num_runs(20)

# Create and add a new Monte Carlo File variable to the simulation.
#mcvar_kP = trick.MonteVarFile("dyn.satellite.pid.kP", "kValues/kP_value_list", 1)
#trick_mc.mc.add_variable(mcvar_kP)

# Stop the simulation run after 15 seconds of simulation time.
