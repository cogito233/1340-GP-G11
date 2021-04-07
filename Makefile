# Predefined variables
FLAGS = -pedantic-errors -std=c++11 -I ~/local/include -I ~/local/include/ncurses -L ~/local/lib

# Build the game directly
all:
	@make clean
	@make bin/game
	@echo "Run the game with \`bin/game\`"

# Build targets
obj/map.o: src/map.cpp src/map.h
	@mkdir obj
	@g++ $(FLAGS) -lncurses $< -g -c -o $@

obj/visualization.o: src/visualization.cpp src/visualization.h obj/map.o
	@g++ $(FLAGS) -lncurses $< -g -c -o $@

obj/saveAndLoad.o: src/saveAndLoad.cpp src/saveAndLoad.h obj/map.o obj/visualization.o
	@g++ $(FLAGS) -lncurses $< -g -c -o $@

bin/game: src/main_vis.cpp obj/map.o obj/visualization.o obj/saveAndLoad.o
	@mkdir bin
	@echo "Compiling sources..."
	@g++ $(FLAGS) $^ -lncurses -g -o $@
	@echo "~~ Successful Compilation ~~"
	@mkdir -p log
	@touch __rank__.txt

# Delete all object codes & executable
clean: 
	@rm -rf obj
	@rm -rf bin
	@echo "Directories obj & bin cleaned"

# Clean game records
clean-log:
	@rm -rf log
	@echo "Cleaned all game records"

# Build ncurses
ncurses: 
	@echo "Building ncurses..."	
	@chmod +x get.sh
	@./get.sh
	@echo "Installed Successfully"

.PHONY: clean clean-log ncurses
