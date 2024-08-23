GCC = g++
CFLAGS = -Wall -Wextra -std=c++17

EXEC = Inheritance

all: $(EXEC)

OBJ = Inheritance.o

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

Inheritance.o: Inheritance.cpp
	$(GCC) $(CFLAGS) -c Inheritance.cpp

clean:
	rm -rf $(OBJ) $(EXEC)
	