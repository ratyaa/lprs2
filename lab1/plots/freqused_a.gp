set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_a = "data/freqused_a.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"
# set y2label "swaps"
# set y2tics

f_a(x) = k_a * x + b_a
fit f_a(x) inputfile_a using 1:2 via k_a, b_a

plot inputfile_a using 1:2 axis x1y1 with lines title "Execution time (a, us)",\
     f_a(x) with line title "fit (a)"


