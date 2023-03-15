set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_average = "data/bruteforce_average.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"
# set y2label "swaps"
# set y2tics

f_average(x) = k_average * x + b_average
fit f_average(x) inputfile_average using 1:2 via k_average, b_average

plot inputfile_average using 1:2 axis x1y1 with lines title "Execution time (average, us)",\
     f_average(x) with line title "fit (average)"


