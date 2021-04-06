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
        public:
            int save(mp::map *board, int round, std::string name);
            int load(mp::map *board, int &round, std::string name);
    };
}

#endif