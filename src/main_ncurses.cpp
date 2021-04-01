#include <bits/stdc++.h>
#include <ncurses.h>
#include "map.h"

mp::map *board;

void getyx_(int &y, int &x);

int main() {
    initscr();
    cbreak();
	
	board = new mp::map();
	board->display_ncurses();
	int x, y, score;
	int score_total = 0;
	
	while (!board->is_end()) {
		getyx_(y, x);
		printw("%d %d", y, x);
		score = board->operation(y+1, x);
		score_total += score;
		board ->display_ncurses();
	}

	move(21, 0);
	printw("Game over. Press any key to exit.\n");
	
	printw("Your score is: %d\n", score_total);

	getch();
	endwin();

	return 0;
}

void getyx_(int &y, int &x) {
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
        }
        if (isChosen)
                break;
    }
}
