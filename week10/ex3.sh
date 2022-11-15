#!/bin/sh

rm -f _ex3.txt
echo "lol" > _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod 707 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod a=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "660 means read and write permissions (6) for user and the group" >> ex3.txt
echo "775 means read, write, and execute permissions (7) for user and the group, and read and execute permissions (5) for others" >> ex3.txt
echo "777 means read, write, and execute permissions (7) for everyone" >> ex3.txt
