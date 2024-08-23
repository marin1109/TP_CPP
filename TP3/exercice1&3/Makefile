GCC = g++
CFLAGS = -Wall -Wextra -std=c++11

# Nom de l'exécutable
EXEC = Main

# Liste des fichiers objets
OBJ = Main.o Horloge.o Date.o RendezVous.o

# Règle par défaut
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Règle pour compiler main.cpp
Main.o: Main.cpp Horloge.hpp Date.hpp RendezVous.hpp
	$(GCC) $(CFLAGS) -c Main.cpp

# Règle pour compiler Horloge.cpp
Horloge.o: Horloge.cpp Horloge.hpp
	$(GCC) $(CFLAGS) -c Horloge.cpp

# Règle pour compiler Date.cpp
Date.o: Date.cpp Date.hpp
	$(GCC) $(CFLAGS) -c Date.cpp

# Règle pour compiler RendezVous.cpp
RendezVous.o: RendezVous.cpp RendezVous.hpp
	$(GCC) $(CFLAGS) -c RendezVous.cpp

clean:
	rm -f $(OBJ) $(EXEC)
