#include <bits/stdc++.h>
#include "map.h"

mp::map *board;

// Purpose: game interface
int main(){
    board = new mp::map();
    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++)
            printf("%d", board->map_query(i, j));
        printf("\n");
    }

    int x, y, score;
    int score_total = 0;
    
    while (!board->is_end()){ // while some blocks can be eliminated
        scanf("%d%d", &x, &y); // read x,y coords
        score = board->operation(x, y); // eliminate blocks based on the given x, y
        score_total += score; // compute total score
        for (int i=0; i<20; i++){
            for (int j=0; j<20; j++)
                printf("%d", board->map_query(i, j));
            printf("\n");
        }
    }
    printf("%d", score_total);

    return 0;
}

