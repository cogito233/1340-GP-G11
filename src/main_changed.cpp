#include <bits/stdc++.h>
#include "map"
using namespace std;
/*
void printMap(map map){
    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++)
            printf("%d", map.map_query(i, j));
        printf("\n");
    }
}*/
map* mp;
// Purpose: game interface
int main(){
    mp = new map();
    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++)
            printf("%d", mp.map_query(i, j));
        printf("\n");
    }

    int x, y, score;
    int score_total = 0;
    
    while (!mp.is_end()){ // while some blocks can be eliminated
        scanf("%d%d", &x, &y); // read x,y coords
        score = mp.operation(x, y); // eliminate blocks based on the given x, y
        score_total += score; // compute total score
        for (int i=0; i<20; i++){
            for (int j=0; j<20; j++)
                printf("%d", mp.map_query(i, j));
            printf("\n");
        }
    }
    printf("%d", score_total);

    return 0;
}

