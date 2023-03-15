set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_c = "data/freqused_c.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"
# set y2label "swaps"
# set y2tics

f_c(x) = k_c * x + b_c
fit f_c(x) inputfile_c using 1:2 via k_c, b_c

plot inputfile_c using 1:2 axis x1y1 with lines title "Execution time (c, us)",\
     f_c(x) with line title "fit (c)"


