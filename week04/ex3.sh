#!/bin/sh

gcc ex3.c -o ex3
./ex3 3 &
sleep 1

i=0
while [ $i -lt 3 ]
do
    pstree
    sleep 5
    i=$(( i + 1 ))
done

./ex3 5 &
sleep 1

i=0
while [ $i -lt 5 ]
do
    pstree
    sleep 5
    i=$(( i + 1 ))
done


