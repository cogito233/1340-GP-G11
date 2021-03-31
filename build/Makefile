# Predefined variables
FLAGS = -pedantic-errors -std=c++11 -I ~/local/include -I ~/local/include/ncurses -L ~/local/lib

# Build targets
map.o: ../src/map.cpp ../src/map.h
	g++ $(FLAGS) -lncurses -c $<

main_ncurses: ../src/main_ncurses.cpp map.o
	g++ $(FLAGS) $^ -lncurses -o $@
	@echo "~~Successful Compilation~~"

# Delete all object codes & executable
clean: 
	rm -rfv *.o
	rm -f main_ncurses


.PHONY: clean
