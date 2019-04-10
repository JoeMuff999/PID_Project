dlmread('settlingtime.csv')
#s.runNumber, s.kP, s.kI, s.kD, s.meanSettlingTime, s.meanPercentOvershoot, s.settlingTimeRank
graphics_toolkit("gnuplot")
Array = dlmread('settlingtime.csv');
kp = Array(:,2)
#kd = Array(:,4)
ts98 = Array(:,5)
plot(kp,ts98)
#plot3(kp,kd,ts98)

