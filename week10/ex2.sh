#!/bin/sh

rm -f ../week01/file.txt _ex2.txt
echo "file" > ../week01/file.txt
ln -f ../week01/file.txt _ex2.txt
inode=$(find _ex2.txt -printf '%i')
find .. -inum "$inode" > ex2.txt
find .. -inum "$inode" -exec rm {} \; >> ex2.txt
