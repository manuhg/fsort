#!/bin/sh
git clone git@github.com:BVLC/caffe.git
cd caffe && mkdir cmake_build && cd cmake_build
cmake .. -DBUILD_SHARED_LIB=ON -DCPU_ONLY=ON
cmake . -DCMAKE_BUILD_TYPE=Debug     # switch to debug
make -j 12 && make install           # installs by default to build_dir/install
cmake . -DCMAKE_BUILD_TYPE=Release   # switch to release
make -j 12 && make install           # doesn’t overwrite debug install
make symlink