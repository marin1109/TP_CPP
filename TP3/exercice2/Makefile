GCC = g++
CFLAGS = -Wall -Wextra -std=c++11

EXEC = Test

OBJ = Test.o BoxInt.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

Test.o: Test.cpp BoxInt.hpp
	$(GCC) $(CFLAGS) -c Test.cpp

BoxInt.o: BoxInt.cpp BoxInt.hpp
	$(GCC) $(CFLAGS) -c BoxInt.cpp

clean:
	rm -f $(OBJ) $(EXEC)
	