### Team member

Zhiheng LYU (3035772432)

Xijia TAO(?)

### Game description

- The basic interface is shown below (just a bit similar to it in a way):

![samegame](samegame.png)

- As the game we familiar with, we can eliminate two or more adjacent squares of the same color. The more colors you eliminate at one time, the higher your score will be. There is a bonus point for leaving as few blocks as possible that can not eliminate them.
- If your score exceeds the requirements for the current round, you can continue the game and proceed to the next round。

### Game features

1. Generation of random game sets or events
   - We will generate a random game graph based on a difficulty factor that increases with the number of rounds of the game
2. Data structures for storing game status
   - We will generate a random game graph based on a difficulty factor that increases with the number of rounds of the game
3. Dynamic memory management
   - We use linked lists to store map information, and we delete parts of the map that have been eliminated in time.
   - After finishing a round of the game, we delete and recreate a Map object to prevent memory leaks.
4. Fiplayedle input/output (e.g., for loading/saving game status)
   - We generate a "name.json" (The "name" is from input) to store, including the current map information, the score information, and the number of rounds played.
   - The information about the leaderboards is stored in the rank.json file
5. Program codes in multiple files
   - ./lib is the library file code required by the code
   - ./bin is the binary executables
   - ./src is the source file, including
     - main.cpp
       - save_and_load.cpp
         - save_and_load.h
       - map.cpp
         - map.h
       - visualization.cpp
         - visualization.h

### External libraries that might be used

- `ncurses`# ENGG1340-G11
