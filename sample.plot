# https://stackoverflow.com/questions/3939200

set terminal postscript color
set output "plot.ps"
set ylabel "time (seconds)"
set xlabel "N"
set palette defined (0 "red", 1 "yellow", 2 "green", 3 "blue", 4 "black")

plot [:][:] "a.out" u 1:2:3 with lines lw 2 palette
