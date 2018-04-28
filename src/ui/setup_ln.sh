#!/usr/bin/zsh
set -x
find -type d -name "build-*" -exec  ln -s ../../../ml_data {}/ml_data \;
