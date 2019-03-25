execfile("Modified_Data/Satellite.dr")

# Enable Monte Carlo.
trick.mc_set_enabled(1)

# Sets the number of runs to perform to 20. Trick will not exceed the number of values in an input file.
#trick.mc_set_num_runs(2005);

slave1 = trick.MonteSlave("joey-VirtualBox");
trick_mc.mc.add_slave(slave1);
slave2 = trick.MonteSlave("joey-VirtualBox");
trick_mc.mc.add_slave(slave2);
slave3 = trick.MonteSlave("joey-VirtualBox");
trick_mc.mc.add_slave(slave3);
slave4 = trick.MonteSlave("joey-VirtualBox");
trick_mc.mc.add_slave(slave4);
#slave3 = trick.MonteSlave("joey-VirtualBox");
#trick_mc.mc.add_slave(slave3);

# Create and add a new Monte Carlo File variable to the simulation.
mcvar_kP = trick.MonteVarCalculated("dyn.satellite.pid.kP","1")
trick_mc.mc.add_variable(mcvar_kP)
mcvar_kD = trick.MonteVarCalculated("dyn.satellite.pid.kD","1")
trick_mc.mc.add_variable(mcvar_kD)
mcvar_kI = trick.MonteVarCalculated("dyn.satellite.pid.kI","1")
trick_mc.mc.add_variable(mcvar_kI)
mcvar_RUN= trick.MonteVarCalculated("dyn.satellite.pid.runneth","1")
trick_mc.mc.add_variable(mcvar_RUN)
mcvar_RunCounter = trick.MonteVarCalculated("dyn.money.runCounter","1")
trick_mc.mc.add_variable(mcvar_RunCounter)
mcvar_runspgs = trick.MonteVarCalculated("dyn.money.runsPerGainValueSet","1")
trick_mc.mc.add_variable(mcvar_runspgs)

#mcvar_runstore = trick.MonteVarCalculated("dyn.money.storage","1")
#trick_mc.mc.add_variable(mcvar_runstore)

#mcvar_SettlingTime = trick.MonteVarCalculated("")

# Stop the simulation run after 15 seconds of simulation time.
trick.stop(15)
