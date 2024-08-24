GPP = c++
CFLAGS = -Wextra -std=c++17

EXEC = Main
OBJS = Main.o

$(EXEC): $(OBJS)
	$(GPP) $(CFLAGS) -o $(EXEC) $(OBJS)

Main.o: Main.cpp MonPtrU.hpp
	$(GPP) $(CFLAGS) -c Main.cpp

clean:
	rm -f $(OBJS) $(EXEC)
