#!/bin/sh

chmod +x ex1.sh
./ex1.sh

echo "Amirlan" > lofsdisk/file1
echo "Sharipov" > lofsdisk/file2

mkdir lofsdisk/usr
mkdir lofsdisk/usr/bin
mkdir lofsdisk/usr/lib
mkdir lofsdisk/usr/lib64

# I am using Arch Linux, that's why some libraries may differ from Ubuntu
# Sorry for the inconvinience

cp /bin/bash /bin/ls /bin/echo /bin/cat lofsdisk/usr/bin
cp /lib/libreadline.so* lofsdisk/usr/lib/
cp /lib/libdl.so.2* lofsdisk/usr/lib/
cp /lib/libc.so* lofsdisk/usr/lib/
cp /lib/libncursesw.so* lofsdisk/usr/lib/
cp /lib/libcap.so.2* lofsdisk/usr/lib/
cp /lib64/ld-linux-x86-64.so.2 lofsdisk/usr/lib64/

# symbolic links contain just the path, so after chroot they will pick the directories inside lofsdisk
ln -sf /usr/lib lofsdisk/lib
ln -sf /usr/lib64 lofsdisk/lib64
ln -sf /usr/bin lofsdisk/bin

gcc ex2.c -o ex2.out
cp ex2.out lofsdisk

printf "\nW/ CHROOT\n" > ex2.txt
sudo chroot lofsdisk /ex2.out >> ex2.txt
printf "\nW/O CHROOT\n" >> ex2.txt
./ex2.out >> ex2.txt
