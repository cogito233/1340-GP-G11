#include <bits/stdc++.h>
#include <map.h>
using namespace std;

void printMap(map map){
    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++)
            printf("%d", map.map_query(i, j));
        printf("\n");
    }
}

// Purpose: game interface
int main(){
	map map;
    printMap(map);

    int x, y, score;
    int score_total = 0;
    
    while (!map.is_end()){ // while some blocks can be eliminated
        scanf("%d%d", &x, &y); // read x,y coords
        score = map.operation(x, y); // eliminate blocks based on the given x, y
        score_total += score; // compute total score
        printMap(map);
    }
    printf("%d", reward_total);

    return 0;
}
