#!/bin/sh

if [ $# -ne 1 ]; then
    printf "Usage: %s [subs]\n" "$0"
    exit
fi

if [ -z "$TERMINAL" ]; then
    TERMINAL=xterm
fi

gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

$TERMINAL -e ./publisher "$1" &

i=0
while [ $i -lt "$1" ]; do
    $TERMINAL -e ./subscriber &
    i=$(( i + 1 ))
done
