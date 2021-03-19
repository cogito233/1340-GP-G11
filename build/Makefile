# Predefined variables
FLAGS = -pedantic-errors -std=c++11

# Build targets
map.o: ../src/map.cpp ../src/map.h
	g++ $(FLAGS) -c $<

main: ../src/main.cpp map.o
	g++ $(FLAGS)  $^ -o $@
	@echo "~~Successful Compilation~~"

# Delete all object codes & executable
clean: 
	rm -rfv *.o
	rm main

.PHONY: clean
