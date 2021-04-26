/*
  This program is responsible for 
    1. defining operations on map
    2. displaying the map
    3. supporting setting map attributes outside the program
*/

#include "map.h"
#include <bits/stdc++.h>
#include <ncurses.h>

namespace mp {

// 1. Count the size of the current link block (set sum as counter)
// 2. eliminate the link block (f[x][y]->0)
//
// The initial input (x, y, colour) should be the coordinates 
// and colours of the points being manipulated in the game
//
// Important: This function will only eliminate the link block, and
// if you need to let the block fall, you'll use the normalization function
void map::dfs(int x, int y, int colour, int &sum) {
  this->f[x][y] = 0;
  sum += 1;
  if (this->f[x - 1][y] == colour)
    this->dfs(x - 1, y, colour, sum);
  if (this->f[x + 1][y] == colour)
    this->dfs(x + 1, y, colour, sum);
  if (this->f[x][y - 1] == colour)
    this->dfs(x, y - 1, colour, sum);
  if (this->f[x][y + 1] == colour)
    this->dfs(x, y + 1, colour, sum);
}

void map::copy_column(int x, int y) {
  if (x == y)
    return;
  for (int i = 1; i <= 20; i++)
    this->f[i][x] = this->f[i][y];
}

// Make the block go down and fall to the left
void map::normalization() {
  for (int j = 1; j <= 20; j++) {
    int k = 21;
    for (int i = 20; i >= 1; i--)
      if (this->f[i][j])
        this->f[--k][j] = this->f[i][j];
    for (k--; k >= 1; k--)
      this->f[k][j] = 0;
  }
  int k = 0;
  for (int i = 1; i <= 20; i++)
    if (this->f[20][i])
      this->copy_column(++k, i);
  for (k++; k <= 20; k++)
    this->copy_column(k, 0);
}

// The map will be randomly generated
map::map() {
  this->score = 0;
  srand(time(0));
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= 20; j++)
      this->f[i][j] = rand() % 3 + 1;
}

//The following four functions are used to modify and query
//class variables, which are protected because they are private
int map::now_score() { return this->score; }
void map::score_set(int val) { this->score = val; }
int map::map_query(int x, int y) { return this->f[x][y]; }
void map::map_set(int x, int y, int val) { this->f[x][y] = val; }

bool map::is_end() {
  bool flag = 1;
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= 20; j++)
      if (f[i][j])
        flag = flag && !(this->f[i][j] == this->f[i][j - 1] ||
                         this->f[i][j] == this->f[i - 1][j]);
  return flag;
}

// Method of operating on the (x, y) point of the map, inculding:
//   1. Check if it is a correction link block thatcan be eliminated;
//   2. Eliminate, maintain the map;
//   3. Calculate the score for this operation.
int map::operation(int x, int y) {
  if (this->f[x][y] == 0)
    return -1;
  if (!(this->f[x][y] == this->f[x][y - 1] ||
        this->f[x][y] == this->f[x - 1][y] ||
        this->f[x][y] == this->f[x + 1][y] ||
        this->f[x][y] == this->f[x][y + 1]))
    return -1;
  int sum = 0;
  this->dfs(x, y, this->f[x][y], sum);
  this->normalization();
  this->score += sum * sum * 5;
  return sum * sum * 5;
}

// Reserved for initial debugging
void map::display() {
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= 20; j++)
      if (f[i][j])
        printf("%d", this->f[i][j]);
      else
        putchar(' ');
    printf("\n");
  }
}
} // namespace mp
