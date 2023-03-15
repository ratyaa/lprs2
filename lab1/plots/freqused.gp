set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_a = "data/freqused_a.csv"
inputfile_b = "data/freqused_b.csv"
inputfile_c = "data/freqused_c.csv"
inputfile_bf = "data/bruteforce_average.csv"

set datafile separator ','
set key left top

set xlabel "N"
set ylabel "time, us"

f_a(x) = k_a * x + b_a
fit f_a(x) inputfile_a using 1:2 via k_a, b_a

f_b(x) = k_b * x + b_b
fit f_b(x) inputfile_b using 1:2 via k_b, b_b

f_c(x) = k_c * x + b_c
fit f_c(x) inputfile_c using 1:2 via k_c, b_c

f_bf(x) = k_bf * x + b_bf
fit f_bf(x) inputfile_bf using 1:2 via k_bf, b_bf

plot inputfile_a using 1:2 axis x1y1 with lines title "Execution time (a, us)",\
     inputfile_b using 1:2 axis x1y1 with lines title "Execution time (b, us)",\
     inputfile_c using 1:2 axis x1y1 with lines title "Execution time (c, us)",\
     inputfile_bf using 1:2 axis x1y1 with lines title "Execution time (bruteforce, us)",\
     f_a(x) with line title "fit (a)",\
     f_b(x) with line title "fit (b)",\
     f_c(x) with line title "fit (c)",\
     f_bf(x) with line title "fit (bruteforce)"


