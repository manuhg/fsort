#!/bin/bash
mkdir -p ml_data
cd ml_data
wget http://dl.caffe.berkeleyvision.org/bvlc_reference_caffenet.caffemodel
mv bvlc_reference_caffenet.caffemodel models/bvlc_reference_caffenet/
 mkdir -p ilsvrc12
 cd ilsvrc12
 wget -c http://dl.caffe.berkeleyvision.org/caffe_ilsvrc12.tar.gz
 tar -xf caffe_ilsvrc12.tar.gz && rm -f caffe_ilsvrc12.tar.gz
cd ..
