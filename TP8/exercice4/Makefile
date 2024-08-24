GPP = g++
CFLAGS = -Wall -std=c++17

all: Test

Test: Test.o
	$(GPP) $(CFLAGS) -o Test Test.o

Test.o: Test.cpp Fraction.hpp
	$(GPP) $(CFLAGS) -c Test.cpp

clean:
	rm -f Test Test.o
	