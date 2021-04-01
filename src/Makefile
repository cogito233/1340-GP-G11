# Predefined variables
FLAGS = -pedantic-errors -std=c++11 -I ~/local/include -I ~/local/include/ncurses -L ~/local/lib

# Build the game directly
all:
	@make clean
	@make testvis
	@echo "Run the game with \`bin/game\`"

# Build targets
map.o: map.cpp map.h
	@g++ $(FLAGS) -lncurses $< -c -o $@
	@echo "~~ finish map ~~"

visualization.o: visualization.cpp visualization.h map.o
	@g++ $(FLAGS) -lncurses $< -c -o $@
	@echo "~~ finish vis ~~"
	
testvis: testvis.cpp visualization.o map.o
	@g++ $(FLAGS) $^ -lncurses -o $@
	@echo "~~ Successful Compilation ~~"

# Delete all object codes & executable
clean: 
	@rm -rf map.o
	@rm -rf visualization.o
	@rm -rf testvis
	@echo "Directories obj & bin cleaned"

# Build ncurses
ncurses: 
	@echo "Building ncurses..."	
	@chmod +x get.sh
	@./get.sh
	@echo "Installed Successfully"

.PHONY: clean ncurses
