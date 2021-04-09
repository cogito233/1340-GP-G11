#ifndef sl_h
#define sl_h

#include "map.h"
#include <string>
#include <fstream>
#include <time.h>
#include <ncurses.h>

namespace sl{
    struct ranklist{
        std::string name;
        int score;
    };

    class rank_list {
        private:
            ranklist rk[10];
            int ranker_num;
            std::string filename;
        public:
            rank_list(std::string filename);
            void sort();
            void add(std::string name, int score);
            int save();
            void print_rank();
    };
    
    class current_map {
        private:
            mp::map *board;
            int *round;
        public:
            current_map(mp::map *board, int &round);
            //void link_map(mp::map *board);
            //void set_round(int round);
            int get_round();
            int save(std::string name);
            int load(std::string filename);
    };
}

#endif