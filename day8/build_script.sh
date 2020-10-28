#!usr/bin/env bash
echo Start of script
mkdir build
cd build
echo This is my build dir $(pwd)

git clone https://github.com/anormen/courseCpp.git

cd courseCpp/day7/w2make1
echo This is my makefile dir $(pwd)
make libshape.so
make
echo This is my makefile dir $(pwd) and this are the files in the directory $(ls)
export LD_LIBRARY_PATH=.
./a.out






