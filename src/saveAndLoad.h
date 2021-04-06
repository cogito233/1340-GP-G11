#ifndef sl_h
#define sl_h

#include "map.h"
#include "visualization.h"
#include <string>
#include <fstream>
#include <time.h>

namespace sl{
    class rank_list {

    };
    
    class current_map {
        private:
            void mapInfo();
            void scoreInfo();
            void roundInfo();
        public:
            int save(mp::map *board, int round, std::string name);
            int load(mp::map *board, int &round, std::string &name);
    };
}

#endif