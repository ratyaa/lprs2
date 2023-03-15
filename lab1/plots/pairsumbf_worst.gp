set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_worst = "data/pairsumbf_worst.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"
# set y2label "swaps"
# set y2tics

f_worst(x) = k_worst * x * x + b_worst
fit f_worst(x) inputfile_worst using 1:2 via k_worst, b_worst

plot inputfile_worst using 1:2 axis x1y1 with lines title "Execution time (worst, us)",\
     f_worst(x) with line title "fit (worst)"


