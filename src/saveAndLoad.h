#ifndef sl_h
#define sl_h

#include "map.h"
#include "visualization.h"
#include <string>
#include <fstream>
#include <time.h>
#include <ncurses.h>

namespace sl{
    class rank_list {

    };
    
    class current_map {
        private:
            mp::map *board;
            int round;
        public:
            current_map(mp::map *board, int &round);
            int save(std::string name);
            int load(std::string filename);
    };
}

#endif