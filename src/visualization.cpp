#include "map.h"
#include <bits/stdc++.h>
#include <ncurses.h>


namespace vi{
    load_interface::load_interface() {
        this->load[0].text = "New_Game";
        this->load[1].text = "Load";
        this->load[2].text = "Help";
        this->load[3].text = "End_Game";

        this->refresh();
    }//TODO
    string load_interface::save_or_load(string s) {

    }//TODO
    void load_interface::Help() {

    }//TODO
    void load_interface::refresh(text_anchor a[], int n, int highlight) {

        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_BLACK, COLOR_RED);
        for (int i = 0; i < n; i++) {
            move(a[i].x, a[i].y);
            if
        }
    }//TODO
    void load_interface::get_order() {

    }//TODO
    //class load_interface
    pause_interface::pause_interface() {
        this->pause[0].text = "New_Game";
        this->pause[1].text = "Load";
        this->pause[2].text = "Help";
        this->pause[3].text = "End_Game";
        this->pause[4].text = "Continue";
        this->pause[5].text = "Save";

        this->refresh();
    }//TODO
    void pause_interface::get_order() {

    }//TODO
    //class pause_interface

    game_interface::game_interface() {
        this->ranker_num = 0;
    }
    void game_interface::print_map() {

    }//TODO
    void game_interface::print_rank() {

    }//TODO
    void game_interface::print_interface() {
        move(0, 0);

        start_color();
        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_BLACK, COLOR_RED);
        init_pair(2, COLOR_BLACK, COLOR_BLUE);
        init_pair(3, COLOR_BLACK, COLOR_GREEN);

        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                attron(COLOR_PAIR(this->board->map_query(i, j)));
                printw(" ");
                attroff(COLOR_PAIR(this->board->map_query(i, j))));
            }
            printw("\n");
        }
    }
    void game_interface::refresh() {
        this->print_map();
        this->print_interface();
        this->print_rank();
    }
    int game_interface::add_rank_info(string name, int score) {
        if (name.length()>8){
            return 0;
        }
        this->ranker_num++;
        this->rk[ranker_num].name = name;
        this->rk[ranker_num].score = score;
        for (int i = ranker_num-1; i >=1; i--) {
            if (this->rk[i].score > this->rk[i-1].score) {
                swap(rk[i], rk[i-1]);
            } else {
                break;
            }
        }
        return 1;
    }
    void game_interface::link_map(mp::map *mp) {
        this->board = mp;
    }
    void game_interface::keyboard_operation() {

    }//TODO
}