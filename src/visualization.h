#ifndef vis_h
#define vis_h

#include <ncurses.h>
#include <string>
#include "saveAndLoad.h"
#include "map.h"

namespace vi{
    struct text_anchor{
        int x,y;
        int direct[4];
        std::string text;
    };
	class load_interface{//Load, Game Mode, New_Game, End_Game, Help
		private:
            text_anchor load[5];
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
        int *round;
        mp::map *board;
        sl::rank_list *rank;
        void print_map();
        void print_interface();
    public:
        game_interface();
        void link_map(mp::map *mp);
        void set_round(int &round);
        void link_rank(sl::rank_list *rank);
        std::string mouse_operation(int &y, int &x);
        std::string keyboard_operation(int &y, int &x);
        void refresh();
    };
}
#endif
