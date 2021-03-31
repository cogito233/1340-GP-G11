#include <bits/stdc++.h>
#include <ncurses.h>
#include "map.h"

mp::map *board;

void getyx_(int &y, int &x);

int main() {
    initscr();
    noecho();
    cbreak();
	
	board = new mp::map();
	board->display_ncurses();
	int x, y, score;
	int score_total = 0;
	
	while (!board->is_end()) {
		getyx_(y, x);
		score = board->operation(y+1, x+1);
		score_total += score;
		board ->display_ncurses();
	}

	endwin();
	printf("Your score is:%d\n", score_total);

	return 0;
}

void getyx_(int &y, int &x) {
    keypad(stdscr, true);

	int c;
	bool isChosen = false;

	move(0, 0);

	while (true) {
        c = getch();
        getyx(stdscr, y, x);
        switch (c) {
            case KEY_UP:
                if (y > 0)
                    move(y - 1, x);
                break;
            case KEY_DOWN:
                if (y < 19)
                    move(y + 1, x);
                break;
            case KEY_LEFT:
                if (x > 0)
                    move(y, x - 1);
                break;
            case KEY_RIGHT:
                if (x < 19)
                    move(y, x + 1);
                break;
            case KEY_BACKSPACE:
				isChosen = true;
                break;
        }
		if (isChosen)
			break;
    }
}