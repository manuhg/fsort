cmake_minimum_required(VERSION 2.8)
project(sforfsort)
include(MergeStaticLibs.cmake)
#link_directories(./)
#OBfile(GLOB opencv_ ./opencv3/*.a )

set(LIBS bhtsne boost_system boost_thread glog lmdb cblas hdf5_hl leveldb gflags protobuf hdf5 caffe boost_filesystem caffeproto )
merge_static_libs(sforfsort ${LIBS} )
