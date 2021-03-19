#include <bits/stdc++.h>
#include <map.h>
using namespace std;

// Purpose: game interface
int main(){
	Map map;
    int x, y, score;
    int score_total = 0;
    
    while (!map.is_end()){ // while some blocks can be eliminated
        scanf("%d%d", &x, &y); // read x,y coords
        score = map.operation(x, y); // eliminate blocks based on the given x, y
        score_total += score; // compute total score
    }
    printf("%d", reward_total);

    return 0;
}
