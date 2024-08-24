CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++17

EXEC = Test

SRCDIR = src
OBJDIR = obj
INCLUDEDIR = include

OBJ = $(OBJDIR)/Vecteur.o $(OBJDIR)/Test.o $(OBJDIR)/Carre.o $(OBJDIR)/Losange.o $(OBJDIR)/Quadrilatere.o $(OBJDIR)/Rectangle.o $(OBJDIR)/Triangle.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(EXEC) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/Vecteur.o: ../exercice1/Vecteur.cpp ../exercice1/Vecteur.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c ../exercice1/Vecteur.cpp -o $(OBJDIR)/Vecteur.o

$(OBJDIR)/Test.o: Test.cpp ../exercice1/Vecteur.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c Test.cpp -o $(OBJDIR)/Test.o

$(OBJDIR)/Quadrilatere.o: $(SRCDIR)/Quadrilatere.cpp $(INCLUDEDIR)/Quadrilatere.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $(SRCDIR)/Quadrilatere.cpp -o $(OBJDIR)/Quadrilatere.o
	
$(OBJDIR)/Losange.o: $(SRCDIR)/Losange.cpp $(INCLUDEDIR)/Losange.hpp $(INCLUDEDIR)/Quadrilatere.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $(SRCDIR)/Losange.cpp -o $(OBJDIR)/Losange.o

$(OBJDIR)/Rectangle.o: $(SRCDIR)/Rectangle.cpp $(INCLUDEDIR)/Rectangle.hpp $(INCLUDEDIR)/Quadrilatere.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $(SRCDIR)/Rectangle.cpp -o $(OBJDIR)/Rectangle.o

$(OBJDIR)/Carre.o: $(SRCDIR)/Carre.cpp $(INCLUDEDIR)/Carre.hpp $(INCLUDEDIR)/Rectangle.hpp $(INCLUDEDIR)/Losange.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $(SRCDIR)/Carre.cpp -o $(OBJDIR)/Carre.o

$(OBJDIR)/Triangle.o: $(SRCDIR)/Triangle.cpp $(INCLUDEDIR)/Triangle.hpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $(SRCDIR)/Triangle.cpp -o $(OBJDIR)/Triangle.o

clean:
	rm -rf $(OBJDIR) $(EXEC)
