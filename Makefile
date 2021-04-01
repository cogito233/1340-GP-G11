# Predefined variables
FLAGS = -pedantic-errors -std=c++11 -I ~/local/include -I ~/local/include/ncurses -L ~/local/lib

# Build the game directly
all:
	@make clean
	@make bin/game
	@echo "Run the game with `bin/game`"

# Build targets
obj/map.o: src/map.cpp src/map.h
	@mkdir obj
	@g++ $(FLAGS) -lncurses $< -c -o $@
	
bin/game: src/main_ncurses.cpp obj/map.o
	@mkdir bin
	@echo "Compiling sources..."
	@g++ $(FLAGS) $^ -lncurses -o $@
	@echo "~~ Successful Compilation ~~"

# Delete all object codes & executable
clean: 
	@rm -rf obj
	@rm -rf bin
	@echo "Directories obj & bin cleaned"

# Build ncurses
ncurses: 
	@echo "Building ncurses..."	
	@chmod +x get.sh
	@./get.sh
	@echo "Installed Successfully"

.PHONY: clean ncurses
