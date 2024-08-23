GCC = g++
CFLAGS = -Wall -Wextra -std=c++11

EXEC = Test

OBJ = List.o Cell.o Test.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

List.o: List.cpp List.hpp Cell.hpp
	$(GCC) $(CFLAGS) -c List.cpp

Cell.o: Cell.cpp Cell.hpp
	$(GCC) $(CFLAGS) -c Cell.cpp

clean:
	rm -f $(OBJ) $(EXEC)
	