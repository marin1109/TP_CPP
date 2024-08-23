GCC = g++
CFLAGS = -Wall -Wextra -std=c++11

EXEC = Main

OBJ = Main.o Vector.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

Main.o: Main.cpp Vector.hpp
	$(GCC) $(CFLAGS) -c Main.cpp

Vector.o: Vector.cpp Vector.hpp
	$(GCC) $(CFLAGS) -c Vector.cpp

clean:
	rm -f $(OBJ) $(EXEC)
	