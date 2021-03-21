#include <bits/stdc++.h>
#include "ncurses.h"
#include "map.h"

mp::map *board;

int main(){
	board = new mp::map();
	board->display_ncurses();

	int x, y, score;
	int score_total = 0;
	
	while (!board->is_end()){
		scanf("%d%d", &x, &y);
		score = board->operation(x, y);
		score_total += score;
		board ->display_ncurses();
	}

	printf("Your score is:%d\n", score_total);

	return 0;
}