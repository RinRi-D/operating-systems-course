#!/bin/sh

date
sleep 3
mkdir root
date
sleep 3
mkdir home
date
sleep 3
ls -tr / > ./root/root.txt
date
sleep 3
ls -tr ~ > ./home/home.txt
ls
ls ./root
ls ./home
