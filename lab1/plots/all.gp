set terminal png font "IBM Plex Mono" size 1200, 600
inputfile_a = "data/freqused_a.csv"
inputfile_b = "data/freqused_b.csv"
inputfile_c = "data/freqused_c.csv"
inputfile_bfa = "data/bruteforce_average.csv"
inputfile_bfw = "data/bruteforce_worst.csv"
inputfile_ba = "data/binary_average.csv"
inputfile_bw = "data/binary_worst.csv"

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

f_bfa(x) = k_bfa * x + b_bfa
fit f_bfa(x) inputfile_bfa using 1:2 via k_bfa, b_bfa

f_bfw(x) = k_bfw * x + b_bfw
fit f_bfw(x) inputfile_bfw using 1:2 via k_bfw, b_bfw

f_ba(x) = k_ba * x + b_ba
fit f_ba(x) inputfile_ba using 1:2 via k_ba, b_ba

f_bw(x) = k_bw * x + b_bw
fit f_bw(x) inputfile_bw using 1:2 via k_bw, b_bw

plot inputfile_a using 1:2 axis x1y1  title "Execution time (a, us)",\
     inputfile_b using 1:2 axis x1y1  title "Execution time (b, us)",\
     inputfile_c using 1:2 axis x1y1  title "Execution time (c, us)",\
     inputfile_bfa using 1:2 axis x1y1  title "Execution time (bruteforce, average, us)",\
     inputfile_bfw using 1:2 axis x1y1  title "Execution time (bruteforce, worst, us)",\
     inputfile_ba using 1:2 axis x1y1  title "Execution time (binary, average, us)",\
     inputfile_bw using 1:2 axis x1y1  title "Execution time (binary, worst, us)",\
     f_a(x) with line title "fit (a)",\
     f_b(x) with line title "fit (b)",\
     f_c(x) with line title "fit (c)",\
     f_bfa(x) with line title "fit (bruteforce, average)",\
     f_bfw(x) with line title "fit (bruteforce, worst)",\
     # f_ba(x) with line title "fit (binary, average)",\
     # f_bw(x) with line title "fit (binary, worst)"


