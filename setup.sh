#!/bin/zsh
c1="\033[0;32m"
c2="\033[0;34m"
rc="\033[0;31m"
nc="\033[0m"
bold="\033[1m"

libs=('opencv' 'glfw')
gitrepos=('https://github.com/opencv/opencv.git' 'https://github.com/glfw/glfw.git')
flags=('-DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=/usr/local' '')
for ((i=1;i<=${#libs};i++)) do
 echo $c1"Setting up$c2$bold $libs[$i]$nc"
 echo $c1"git clone $c2$gitrepos[$i]$nc" && git clone $gitrepos[$i]
 echo "cd $libs[$i]" && cd $libs[$i]
 echo "mkdir bin && cd bin" &&  mkdir bin && cd bin
 echo $c1"cmake $c2$flags[$i]$c1 .."$nc &&  cmake $flags[$i] ..
 echo $c1"make -j4"$nc &&  make -j4
 echo $c1"installing $libs[$i] library"$nc && sudo make install
 echo "cd ../.." && cd ../..
 echo $rc"rm -rf $libs[$i]"$nc
 rm -rf $libs[$i]
done

[ -d bhtsne ] && echo $c2"bhtsne$nc already exists and will be removed\n"$rc"rm -rf bhtsne$nc"  && rm -rf bhtsne

echo $c1"git clone$c2$bold https://github.com/lvdmaaten/bhtsne.git$nc"
git clone https://github.com/lvdmaaten/bhtsne.git

echo "cd bhtsne" && cd bhtsne
echo "Building static library$c1 libbhtsne.a$nc"

g++ -c -O2 sptree.cpp tsne.cpp && ar rcs libbhtsne.a sptree.o tsne.o
cd ..

[ -d lib ] && echo $c2"lib$nc already exists and will be removed\n"$rc"rm -rf lib$nc"  && rm -rf lib
mkdir lib && cp bhtsne/libbhtsne.a lib/

echo "cp bhtsne/libbhtsne.a ->$c1 lib/libbhtsne.a"
echo $rc"rm -rf bhtsne"
rm -rf bhtsne
