GCC = g++
CFLAGS = -Wall -Wextra -std=c++17

EXEC = Main

OBJ = Main.o Article.o ArticleEnSolde.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GCC) $(CFLAGS) -o $(EXEC) $(OBJ)

Main.o: Main.cpp Article.hpp ArticleEnSolde.hpp
	$(GCC) $(CFLAGS) -c Main.cpp

Article.o: Article.cpp Article.hpp
	$(GCC) $(CFLAGS) -c Article.cpp

ArticleEnSolde.o: ArticleEnSolde.cpp ArticleEnSolde.hpp Article.hpp
	$(GCC) $(CFLAGS) -c ArticleEnSolde.cpp

clean:
	rm -rf $(OBJ) $(EXEC)
