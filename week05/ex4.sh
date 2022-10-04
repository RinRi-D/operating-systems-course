#!/bin/sh

gcc ex4.c -o ex4
printf "time ./ex4 10000000 1\n" > ex4.txt
time ./ex4 10000000 1 2>> ex4.txt
printf "time ./ex4 10000000 2\n" >> ex4.txt
time ./ex4 10000000 2 2>> ex4.txt
printf "time ./ex4 10000000 4\n" >> ex4.txt
time ./ex4 10000000 4 2>> ex4.txt
printf "time ./ex4 10000000 10\n" >> ex4.txt
time ./ex4 10000000 10 2>> ex4.txt
printf "time ./ex4 10000000 100\n" >> ex4.txt
time ./ex4 10000000 100 2>> ex4.txt
