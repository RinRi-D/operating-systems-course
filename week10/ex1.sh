#!/bin/sh

rm -f _ex1*
echo "RinRi" > _ex1.txt
ln -f _ex1.txt _ex1_1.txt
ln -f _ex1.txt _ex1_2.txt
ls -i _ex1.txt > ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt
