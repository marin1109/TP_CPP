GCC = g++
CFLAGS = -Wall -std=c++11

all: test

test: test.o TimeStamp.o 
	$(GCC) $(CFLAGS) -o test test.o TimeStamp.o

TimeStamp.o: TimeStamp.cpp TimeStamp.hpp
	$(GCC) $(CFLAGS) -c TimeStamp.cpp

clean :
	rm *.o test
	