#include <bits/stdc++.h>
#include "visualization.h"
#include "map.h"
using namespace std;
//vi::game_interface *game;
vi::pause_interface *load;
//vi::pause_interface *pause;
signed main() {
    cout<<1<<endl;
    load = new vi::pause_interface();
    move(0,0);
    cout<<2<<endl;
    string s = load->get_order();
    cout<<s<<endl;
    return 1;
}
//
// Created by c on 2021/4/1.
//

