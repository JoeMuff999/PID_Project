execfile("Modified_Data/Satellite.dr")

# Enable Monte Carlo.
trick.mc_set_enabled(1)
trick.mc_add_slave("joey-VirtualBox")
trick.mc_add_slave("joey-VirtualBox")
trick.mc_add_slave("joey-VirtualBox")
trick.mc_add_slave("joey-VirtualBox")

# Sets the number of runs to perform to 20. Trick will not exceed the number of values in an input file.
trick.mc_set_num_runs(100)

# Create and add a new Monte Carlo File variable to the simulation.
mcvar_kP = trick.MonteVarCalculated("dyn.satellite.pid.kP","1")
trick_mc.mc.add_variable(mcvar_kP)
mcvar_kD = trick.MonteVarCalculated("dyn.satellite.pid.kD","1")
trick_mc.mc.add_variable(mcvar_kD)
mcvar_kI = trick.MonteVarCalculated("dyn.satellite.pid.kI","1")
trick_mc.mc.add_variable(mcvar_kI)
#mcvar_SettlingTime = trick.MonteVarCalculated("")

# Stop the simulation run after 15 seconds of simulation time.
trick.stop(50)
