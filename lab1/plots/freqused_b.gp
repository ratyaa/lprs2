set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_b = "data/freqused_b.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"
# set y2label "swaps"
# set y2tics

f_b(x) = k_b * x + b_b
fit f_b(x) inputfile_b using 1:2 via k_b, b_b

plot inputfile_b using 1:2 axis x1y1 with lines title "Execution time (b, us)",\
     f_b(x) with line title "fit (b)"


