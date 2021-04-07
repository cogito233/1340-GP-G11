#include <bits/stdc++.h>
#include <ncurses.h>
#include "visualization.h"
#include "saveAndLoad.h"
#include "map.h"
using namespace std;

mp::map *board;
vi::game_interface *game;
vi::load_interface *load;
vi::pause_interface *pause;
sl::current_map *cur_map;
sl::rank_list *rank_list;

signed main() {
    initscr();
    cbreak();

    int round = 0;
    std::string rank_name = "__rank__.txt";

    board = new mp::map();
    rank_list = new sl::rank_list(rank_name);
    pause = new vi::pause_interface();
    game = new vi::game_interface(round);
    load = new vi::load_interface();
    cur_map = new sl::current_map(board, round);

    bool flag_load = 1;
    string s;

    while (flag_load) {
        s = load->get_order();
        if (s == "New_Game_Cli" || s == "New_Game_Key") 
            flag_load = 0;
        if (s == "End_Game"){
            endwin();
            return 0;
        }
        if (s.find("Load") != std::string::npos) 
            cur_map->load(s.substr(5));
    }
    int x = 0, y = 0, score;
    int score_total = 0;
    string str;
    bool isCli = (s == "New_Game_Cli");

    game->link_map(board);
    game->link_rank(rank_list);
    game->refresh();
    while (!board->is_end()) {
        if (isCli) str = game->mouse_operation(y, x);
        else str = game->keyboard_operation(y, x);

        if (str == "Pause") {
            bool flag_pause = 1;
            while (flag_pause) {
                string s = pause->get_order();
                if (s == "Continue") {
                    flag_pause = 0;
                    game->refresh();
                }
                if (s == "New_Game") {
                    delete board;
                    board = new mp::map();
                    game->refresh();
                    flag_pause = 0;
                }
                if (s == "End_Game"){
                    endwin();
                    return 0;
                }
                if (s.find("Save") != std::string::npos) 
                    cur_map->save(s.substr(5));
                    
                if (s.find("Load") != std::string::npos) 
                    cur_map->load(s.substr(5));
            }
            continue;
        }

        score = board->operation(y+1, x+1);
        score_total += score;
        game->refresh();
    }

    move(21, 0);
    printw("Game over\nTo display your score on the leaderboard, \ninput your preferred name here:");
    
    char c = getch();
    std::string name = "";
    while (c != '\n') {
        name += c;
        c = getch();
    }
    
    if (name != "") {
        rank_list->add(name, score_total);
        rank_list->save();
    }

    printw("Press any key to exit.\n");
    getch();
    endwin();

    printf("Your score is: %d\n", score_total);

    return 0;
}