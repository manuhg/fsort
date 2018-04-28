#!/bin/sh
echo "In order for this script to succeed, all caffe-1.0 dependencies must be already installed!"
set -x
rm -rf caffe
ln -s ~/caffe caffe
cd ~
mkdir -p devloka && cd devloka
git clone git@github.com:bvlc/caffe.git
cd caffe
# sed -i '/Flags/a link_libraries("-static")' CMakeLists.txt
mkdir cmake_build && cd cmake_build
cmake .. -DCPU_ONLY=ON -DCMAKE_BUILD_TYPE=Release
make -j12
make install
cp -rapv install ~/caffe
cd ~/caffe
[ ! -d lib ] && [ -d lib64 ] && ln -s lib64 lib
cd ~
# cmake .. -DCPU_ONLY=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release
# cmake . -DCMAKE_BUILD_TYPE=Debug     # switch to debug
# make -j 12 && make install           # installs by default to build_dir/install
# cmake . -DCMAKE_BUILD_TYPE=Release   # switch to release
# make -j 12 && make install           # doesn’t overwrite debug install
# make symlink
#cp Makefile.config.example Makefile.config
#make all -j8
#make test -j8
#make runtest -j8
#make distribute -j8
