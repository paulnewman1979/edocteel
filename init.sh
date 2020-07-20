#!/bin/bash

if [ $# -ne 1 ]
then
    echo "wrong usage"
    exit 255
fi

num=$1
dir=`expr $1 / 10`
if [ $dir -lt 10 ]
then
    dir="0$dir"
fi
mkdir -p $dir
cp -r /Users/taoliu/Documents/git/github/edocteel/80/801 $dir/$num
cd $dir/$num
rm -f Makefile
ln -s ../../template/Makefile ./
ln -s ../../template/commit.sh ./ 
