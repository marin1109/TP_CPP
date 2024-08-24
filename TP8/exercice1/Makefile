GCC = g++
CFLAGS = -Wall -Wextra -std=c++17

EXEC = Test

OBJ = Test.o Vecteur.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

Test.o: Test.cpp Vecteur.hpp
	$(GCC) $(CFLAGS) -c Test.cpp

Vecteur.o: Vecteur.cpp Vecteur.hpp
	$(GCC) $(CFLAGS) -c Vecteur.cpp

clean:
	rm -f $(OBJ) $(EXEC)
	