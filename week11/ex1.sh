#!/bin/sh

sudo umount lofsdisk
sudo losetup -d $(sudo losetup -j lofs.img | awk -F ':' '{ print $1; }')
rm -rf lofsdisk lofs.img

dd if=/dev/zero of=lofs.img bs=100M count=1
mkfs.ext4 lofs.img
lodevice=$(sudo losetup -fP --show lofs.img)
mkdir lofsdisk
sudo mount "$lodevice" lofsdisk
sudo chmod -R 777 lofsdisk
