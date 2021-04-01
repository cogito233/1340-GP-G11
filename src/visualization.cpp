#include "map.h"
#include <bits/stdc++.h>
#include <ncurses.h>


namespace vi{
    load_interface::load_interface() {
        start_color();

        this->load[0].text = "New_Game";
        this->load[1].text = "  Load  ";
        this->load[2].text = "  Help  ";
        this->load[3].text = "End_Game";

        this->load[0].x = 5; this->load[0].y = 50;
        this->load[1].x = 10; this->load[1].y = 50;
        this->load[2].x = 15; this->load[2].y = 50;
        this->load[3].x = 20; this->load[3].y = 50;

        this->load[0].direct={0,1,0,0};
        this->load[1].direct={0,2,1,1};
        this->load[2].direct={1,3,2,2};
        this->load[3].direct={2,3,3,3};

        this->refresh();
    }
    string load_interface::save_or_load(string s) {
        erase();

        move(0,0);
        printw(s);
        char c = getch();
        string str = "";
        while (c!='\n') {
            str += c;
            c = getch()
        }
        return str;
    }

    void load_interface::Help() {
        erase();

        move(0,0);
        printw("This is a Help.\n");
        printw("Press any key to exit.\n");
        getch();
    }

    void load_interface::refresh(text_anchor a[], int n, int highlight) {
        erase();

        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_BLACK, COLOR_YELLOW);
        for (int i = 0; i < n; i++) {
            move(a[i].x, a[i].y);
            attron(i == highlight ? 1 : 0);
            printw(a[i].text);
            attroff(i == highlight ? 1 : 0);
        }

        move(30, 0);
    }

    string load_interface::get_order() {
        int highlight = 0;
        refresh(load,4,highlight);
        move(30, 0);

        char c = getch();
        while (c != ' ' || highlight == 2) {
            while (c == ' ' && highlight == 2) {
                this->Help();
                c = getch();
            }
            if (c == KEY_UP) highlight = this->load[highlight].direct[0];
            if (c == KEY_DOWN) highlight = this->load[highlight].direct[1];
            if (c == KEY_LEFT) highlight = this->load[highlight].direct[2];
            if (c == KEY_RIGHT) highlight = this->load[highlight].direct[3];

            refresh(load,4,highlight);
            move(30, 0);
            c = getch();
        }
        if (highlight == 0) return "New_Game";
        if (highlight == 3) return "End_Game";
        if (highlight == 1) {
            return "Load "+this->save_or_load("Load form: ");
        }
        return "Error";
    }
    //class load_interface

    pause_interface::pause_interface() {
        start_color();

        this->pause[0].text = "  New_Game  ";
        this->pause[1].text = "Load";
        this->pause[2].text = "    Help    ";
        this->pause[3].text = "  End_Game  ";
        this->pause[4].text = "  Continue  ";
        this->pause[5].text = "Save";

        this->load[4].x = 3; this->load[4].y = 30;
        this->load[1].x = 7; this->load[1].y = 30;
        this->load[5].x = 7; this->load[5].y = 36;
        this->load[0].x = 11; this->load[0].y = 30;
        this->load[2].x = 15; this->load[2].y = 30;
        this->load[3].x = 19; this->load[3].y = 30;

        this->load[4].direct={4,1,4,4};
        this->load[1].direct={4,0,1,5};
        this->load[5].direct={4,0,1,5};
        this->load[0].direct={5,2,0,0};
        this->load[2].direct={0,3,2,2};
        this->load[3].direct={2,3,3,3};

        this->refresh();
    }

    string pause_interface::get_order() {
        int highlight = 0;
        refresh(pause,6,highlight);
        move(30, 0);

        char c = getch();
        while (c != ' ' || highlight == 2) {
            while (c == ' ' && highlight == 2) {
                this->Help();
                c = getch();
            }
            if (c == KEY_UP) highlight = this->load[highlight].direct[0];
            if (c == KEY_DOWN) highlight = this->load[highlight].direct[1];
            if (c == KEY_LEFT) highlight = this->load[highlight].direct[2];
            if (c == KEY_RIGHT) highlight = this->load[highlight].direct[3];

            refresh(pause,6,highlight);
            move(30, 0);
            c = getch();
        }
        if (highlight == 0) return "New_Game";
        if (highlight == 3) return "End_Game";
        if (highlight == 4) return "Continue";
        if (highlight == 1) {
            return "Load "+this->save_or_load("Load form: ");
        }
        if (highlight == 5) {
            return "Save "+this->save_or_load("Save as: ");
        }
        return "Error";
    }
    //class pause_interface

    game_interface::game_interface(int round) {
        this->ranker_num = 0;
        this->round = round;
        start_color();
    }
    
    void game_interface::print_map() {
        move(0, 0);

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

    void game_interface::print_rank() {
        move(0, 50);
        for (int i = 0; i < this->ranker_num; i++) {
            printw("%s", this->rk[i].name.c_str());
            printw(": %d\n", this->rk[i].score);
        }
    }

    void game_interface::print_interface() {
        move(30,0);
        printw("Your score: %d\n",this->board->reward_score());
    }

    void game_interface::refresh() {
        erase();

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

    string game_interface::keyboard_operation(int &y, int &x) {
        keypad(stdscr, true);

        int c;
        bool isChosen = false;

        if (x != 0) x--;
        move(y, x);

        while (true) {
            c = getch();
            getyx(stdscr, y, x);
            switch (c) {
                case KEY_UP:
                    if (y > 0)
                        move(y - 1, x);
                    y--;
                    break;
                case KEY_DOWN:
                    if (y < 19)
                        move(y + 1, x);
                    y++;
                    break;
                case KEY_LEFT:
                    if (x > 0)
                        move(y, x - 1);
                    x--;
                    break;
                case KEY_RIGHT:
                    if (x < 19)
                        move(y, x + 1);
                    x++;
                    break;
                case ' ':
                    isChosen = true;
                    break;
                case 27:
                    return "Pause"
            }
            if (isChosen)
                break;
        }
        return "Chosen";
    }//TODO
    //class game_interface
}