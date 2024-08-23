GCC = g++
CFLAGS = -Wall -Wextra -std=c++11

EXEC = Test

OBJ = Test.o  Scrutin.o Urne.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

Test.o: Test.cpp Scrutin.hpp Urne.hpp
	$(GCC) $(CFLAGS) -c Test.cpp

Scrutin.o: Scrutin.cpp Scrutin.hpp
	$(GCC) $(CFLAGS) -c Scrutin.cpp

Urne.o: Urne.cpp Urne.hpp
	$(GCC) $(CFLAGS) -c Urne.cpp

clean:
	rm -f $(OBJ) $(EXEC)
