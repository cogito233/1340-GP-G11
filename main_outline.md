#  🍊Outline for `main.cpp` (First Stage)

Note: `map.h` contains headers for all the methods mentioned below in the namespace `map`. For explanations of what they actually do, see [`/src/map.h`](https://github.com/cogito233/1340-GP-G11/blob/main/src/map.h)

- Save & load the rank & map info (if applies)
- Generate a map randomly via `map(int difficulty_coefficient)`
- Read inputs of `x` & `y` coordinates of the selected block while `is_end()` is true
- Eliminate the blocks around it and address the consequences brought to the other blocks beneath via `operation(int x, int y)`
- Record the score obtained from each operation
- Compute the final score with `reward_score()`

