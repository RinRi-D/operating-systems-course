#!/bin/sh

gcc ex3.c -o ex3
printf "time ./ex3 10000000 1\n" > ex3.txt
time ./ex3 10000000 1 2>> ex3.txt
printf "time ./ex3 10000000 2\n" >> ex3.txt
time ./ex3 10000000 2 2>> ex3.txt
printf "time ./ex3 10000000 4\n" >> ex3.txt
time ./ex3 10000000 4 2>> ex3.txt
printf "time ./ex3 10000000 10\n" >> ex3.txt
time ./ex3 10000000 10 2>> ex3.txt
printf "time ./ex3 10000000 100\n" >> ex3.txt
time ./ex3 10000000 100 2>> ex3.txt
