# Predefined variables
FLAGS = -pedantic-errors -std=c++11

# Build targets
map.o: ../src/map.cpp ../src/map.h
	g++ $(FLAGS) -lncurses -c $<

main: ../src/main.cpp map.o
	g++ $(FLAGS)  $^ -lncurses -o $@
	@echo "~~Successful Compilation~~"

main_ncurses: ../src/main_ncurses.cpp map.o
	g++ $(FLAGS)  $^ -lncurses -o $@
	@echo "~~Successful Compilation~~"

# Delete all object codes & executable
clean: 
	rm -rfv *.o
	rm main

.PHONY: clean
