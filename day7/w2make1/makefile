CXX = g++

exe.a: main.cpp shape.o
	$(CXX) main.cpp libshape.so

libshape.so: shape.cpp shape.h
	$(CXX) shape.cpp -o libshape.so -fPIC -shared

