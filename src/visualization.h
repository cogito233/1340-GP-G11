#ifndef vis_h
#define vis_h

#include "map.h"
#include "saveAndLoad.h"
#include <ncurses.h>
#include <string>

namespace vi {
struct text_anchor {
  int x, y;
  int direct[4];
  std::string text;
};
class load_interface { // Load, Game Mode, New Game, End Game, Help
private:
  text_anchor load[5];
  std::string pic[22] = {
  "                                                  ",
  "                                                  ",
  "                                                  ",
  "       _/_/_/                                     ",
  "    _/          _/_/_/  _/_/_/  _/_/      _/_/    ",
  "     _/_/    _/    _/  _/    _/    _/  _/_/_/_/   ",
  "        _/  _/    _/  _/    _/    _/  _/          ",
  " _/_/_/      _/_/_/  _/    _/    _/    _/_/_/     ",
  "                                                  ",
  "                                                         ",
  "                                                         ",
  "            _/_/_/                                       ",
  "           _/          _/_/_/  _/_/_/  _/_/      _/_/    ",
  "          _/  _/_/  _/    _/  _/    _/    _/  _/_/_/_/   ",
  "         _/    _/  _/    _/  _/    _/    _/  _/          ",
  "          _/_/_/    _/_/_/  _/    _/    _/    _/_/_/     ",
  "                                                         ",
  "                                                         ",
  "                                                         ",
  " Author: Xijia Tao, Zhiheng Lyu                          ",
  "                                                         ",
  " Use [Up/Down] to move the cursor, [Space] to confirm    "
  };
  std::string help[20] = {
  "  ---------------------------------------------------------------- ",
  " | New Game   | Start a new game                                  |",
  "  ---------------------------------------------------------------- ",
  " | End Game   | End the current game                              |",
  "  ---------------------------------------------------------------- ",
  " | Click Mode | Play the game by mouse                            |",
  " |            | Click to eliminate blocks                         |",
  "  ---------------------------------------------------------------- ",
  " | Key Mode   | Play the game by keyboard                         |",
  " |            | Use [Up/Down/Left/Right] to navigate in the board |",
  " |            | Press [Space] to eliminate blocks                 |",
  "  ---------------------------------------------------------------- ",
  " | Save       | Save the game status with inputted filename       |",
  " |            | (without extension)                               |",
  "  ---------------------------------------------------------------- ",
  " | Load       | Load stored game status with inputted filename    |",
  " |            | (without extension)                               |",
  "  ---------------------------------------------------------------- ",
  "                                                                   ",  
  "   Press any key to exit.                                           "
  };
public:
  std::string save_or_load(std::string s);
  void Help();
  void refresh(text_anchor a[], int n, int highlight);
  load_interface();
  std::string get_order();
};
class pause_interface
    : public load_interface { // Save, Load, Continue, New Game, End Game,Help
private:
  text_anchor pause[6];

public:
  pause_interface();
  std::string get_order();
};
class game_interface {
private:
  int *round;
  mp::map *board;
  sl::rank_list *rank;
  void print_map();
  void print_interface();

public:
  game_interface();
  void link_map(mp::map *mp);
  void set_round(int &round);
  void link_rank(sl::rank_list *rank);
  std::string mouse_operation(int &y, int &x);
  std::string keyboard_operation(int &y, int &x);
  void refresh();
};
} // namespace vi
#endif
