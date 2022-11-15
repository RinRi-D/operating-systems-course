#!/bin/sh

rm -rf tmp
mkdir tmp
touch tmp/file1 tmp/file2
ln tmp/file1 tmp/link1

gcc ex4.c -o ex4.out
./ex4.out
