set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_average = "data/bruteforce_average.csv"
inputfile_worst = "data/bruteforce_worst.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"
# set y2label "swaps"
# set y2tics

f_average(x) = k_average * x + b_average
fit f_average(x) inputfile_average using 1:2 via k_average, b_average

f_worst(x) = k_worst * x + b_worst
fit f_worst(x) inputfile_worst using 1:2 via k_worst, b_worst

plot inputfile_average using 1:2 axis x1y1 with lines title "Execution time (average, us)",\
     inputfile_worst using 1:2 axis x1y1 with lines title "Execution time (worst, us)",\
     f_average(x) with line title "fit (average)",\
     f_worst(x) with line title "fit (worst)"

