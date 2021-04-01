#ifndef vis_h
#define vis_h

#include <ncurses.h>
#include "map.h"
#include <string>
namespace vi{
    struct ranklist{
        std::string name;
        int score;
    };
    struct text_anchor{
        int x,y;
        int direct[4];
        std::string text;
    };
	class load_interface{//Load,New_Game,End_Game,Help
		private:
            text_anchor load[4];
        public:
            std::string save_or_load(std::string s);
            void Help();
            void refresh(text_anchor a[], int n, int highlight);
            load_interface();
            std::string get_order();
	};
    class pause_interface:public load_interface{//Save,Load,Continue,New_Game,End_Game,Help
        private:
            text_anchor pause[6];
        public:
            pause_interface();
            std::string get_order();
    };
    class game_interface{
    private:
        mp::map *board;
        ranklist rk[10];
        int ranker_num, round;
        void print_map();
        void print_rank();
        void print_interface();
    public:
        game_interface(int round);
        int add_rank_info(std::string name, int score);
        void link_map(mp::map *mp);
        std::string keyboard_operation(int &y, int &x);
        void refresh();
    };
}
#endif
