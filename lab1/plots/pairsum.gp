set terminal png font "IBM Plex Mono" size 1200, 600

inputfile_average = "data/pairsumbf_average.csv"
inputfile_worst = "data/pairsumbf_worst.csv"
inputfile_fast = "data/pairsumf.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"

f_average(x) = k_average * x * x + b_average
fit f_average(x) inputfile_average using 1:2 via k_average, b_average

f_worst(x) = k_worst * x * x + b_worst
fit f_worst(x) inputfile_worst using 1:2 via k_worst, b_worst

f_fast(x) = k_fast * x + b_fast
fit f_fast(x) inputfile_fast using 1:2 via k_fast, b_fast

plot inputfile_average using 1:2 axis x1y1 with lines title "Execution time (average, us)",\
     inputfile_worst using 1:2 axis x1y1 with lines title "Execution time (worst, us)",\
     inputfile_fast using 1:2 axis x1y1 with lines title "Execution time (fast, us)",\
     f_average(x) with line title "fit (average)",\
     f_worst(x) with line title "fit (worst)",\
     f_fast(x) with line title "fit (fast)"

