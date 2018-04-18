#!/bin/bash
mkdir -p ml_data
cd ml_data
wget http://dl.caffe.berkeleyvision.org/bvlc_googlenet.caffemodel
#mv bvlc_googlenet.caffemodel models/bvlc_googlenet/
 mkdir -p ilsvrc12
 cd ilsvrc12
 wget -c http://dl.caffe.berkeleyvision.org/caffe_ilsvrc12.tar.gz
 tar -xf caffe_ilsvrc12.tar.gz && rm -f caffe_ilsvrc12.tar.gz
cd ..