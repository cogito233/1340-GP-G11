#include <bits/stdc++.h>
#include "visualization.h"
#include <ncurses.h>
#include "map.h"
using namespace std;

mp::map *board;
vi::game_interface *game;
vi::load_interface *load;
vi::pause_interface *pause;

signed main() {
    initscr();
    cbreak();

    int round = 0;
    board = new mp::map();
    pause = new vi::pause_interface();
    game = new vi::game_interface(round);
    load = new vi::load_interface();
    bool flag_load = 1;
    while (flag_load) {
        string s = load->get_order();
        if (s == "New_Game") flag_load = 0;
        if (s == "End_Game"){
            getch();
            endwin();
            return 0;
        }
    }
    int x = 0, y = 0, score;
    int score_total = 0;
    game->link_map(board);
    game->refresh();
    while (!board->is_end()) {
        string str = game->keyboard_operation(y, x);
        if (str == "Pause") {
            bool flag_pause = 1;
            while (flag_pause) {
                string s = pause->get_order();
                if (s == "Continue") flag_pause = 0;
                if (s == "New_Game") {
                    delete board;
                    board =new mp::map();
                    game->refresh();
                    flag_pause = 0;
                }
                if (s == "End_Game"){
                    getch();
                    endwin();
                    return 0;
                }
            }
            continue;
        }
        //printw("%d %d", y, x);
        score = board->operation(y+1, x);
        score_total += score;
        game->refresh();
    }

    move(21, 0);
    printw("Game over. Press any key to exit.\n");

    printw("Your score is: %d\n", score_total);

    getch();
    endwin();

    return 0;
}