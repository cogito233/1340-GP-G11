#ifndef map_h
#define map_h

#include <time.h>

namespace mp {
class map {
private:
  int f[30][30], score;
  void copy_column(int x, int y);
  void normalization();
  void dfs(int x, int y, int colour, int &sum);

public:
  map(); 
  int now_score();
  void score_set(int val);
  int map_query(int x, int y); 
  void map_set(int x, int y, int val);
  bool is_end();               
  int operation(int x, int y); 
  void display();              
};
} // namespace mp
#endif
