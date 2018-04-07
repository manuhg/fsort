#!/usr/bin/sh
set -x
[ -f ../lib/libfsort.a ] && rm libfsort.a
mkdir -p ../include
mkdir -p ../lib
cp ../../libfsort/src/build/libfsort.a ../lib/
[ -d ../include ] && rm -rf ../include
cp -rapv ../../libfsort/include ../
[ -f ../include/libfsort.h ] && rm libfsort.h
cp ../../libfsort/src/libfsort.h ../include/