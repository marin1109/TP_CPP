CPP = g++
CFLAGS = --std=c++11 -Wall

all : test

test : test.o triangle.o trigo.o
	$(CPP) -o test test.o triangle.o trigo.o

test.o : triangle.cpp trigo.cpp test.cpp
	$(CPP) -c test.cpp

triangle.o : triangle.cpp trigo.cpp
	$(CPP) -c triangle.cpp

trigo.o : trigo.cpp
	$(CPP) -c trigo.cpp

clean :
	rm *.o test
	