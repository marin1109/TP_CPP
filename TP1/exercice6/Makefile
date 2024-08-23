GCC = g++
CFLAGS = -Wall -std=c++11

all: main

main: main.o
	$(GCC) $(CFLAGS) -o main main.o

main.o: main.cpp
	$(GCC) $(CFLAGS) -c main.cpp

clean:
	rm -f main *.o
	