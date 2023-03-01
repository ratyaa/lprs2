set terminal png font "IBM Plex Mono" size 800, 600

set datafile separator ','
set key right bottom

set xlabel "N"
set ylabel "time, us"
set y2label "swaps"

plot inputfile using 1:2 axis x1y1 title "Execution time (us)",\
     inputfile using 1:3 axis x1y2 title "Amount of swaps" 
