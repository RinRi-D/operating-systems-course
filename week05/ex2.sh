#!/bin/sh

gcc ex2.c -o ex2 -pthread
./ex2 $1
