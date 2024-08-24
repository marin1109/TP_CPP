GPP = c++
CFLAGS = -Wall -std=c++17

EXEC = Test

all: $(EXEC)

Test: Test.o
	$(GPP) $(CFLAGS) -o Test Test.o

Test.o: Test.cpp
	$(GPP) $(CFLAGS) -c Test.cpp

clean:
	rm -f *.o $(EXEC)
