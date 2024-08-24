GPP = g++
CFLAGS = -Wextra -std=c++17

OBJ = Main.o
HEADERS = $(wildcard *.h)

Main: $(OBJ) $(HEADERS)
	$(GPP) $(CFLAGS) -o Main $(OBJ)

%.o: %.cpp $(HEADERS)
	$(GPP) $(CFLAGS) -c $<

clean:
	rm -f Main $(OBJ)
	