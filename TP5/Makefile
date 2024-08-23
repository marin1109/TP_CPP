CC = g++
CFLAGS = -Wall -std=c++17
LDFLAGS = 
EXEC = bin/Main
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p bin)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@$(CC) -MM $(CFLAGS) $< -I$(INCLUDE_DIR) > $@

-include $(OBJECTS:.o=.d)

clean:
	rm -rf $(OBJ_DIR) bin

.PHONY: all clean
