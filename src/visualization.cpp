#include "visualization.h"

namespace vi {
load_interface::load_interface() {
  clear();
  initscr();
  cbreak();
  keypad(stdscr, true);
  start_color();

  this->load[0].text = " New_Game ";
  this->load[1].text = "Click Mode";
  this->load[2].text = "   Load   ";
  this->load[3].text = "   Help   ";
  this->load[4].text = " End_Game ";

  this->load[0].x = 4;
  this->load[0].y = 50;
  this->load[1].x = 8;
  this->load[1].y = 50;
  this->load[2].x = 12;
  this->load[2].y = 50;
  this->load[3].x = 16;
  this->load[3].y = 50;
  this->load[4].x = 20;
  this->load[4].y = 50;

  int a[5][4] = {
      {0, 1, 0, 0}, {0, 2, 1, 1}, {1, 3, 2, 2}, {2, 4, 3, 3}, {3, 4, 4, 4}};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
      this->load[i].direct[j] = a[i][j];

  this->refresh(load, 5, 0);
  printw("233");
}
std::string load_interface::save_or_load(std::string s) {
  clear();
  keypad(stdscr, true);
  start_color();

  move(0, 0);
  printw("%s", s.c_str());
  char c = getch();
  std::string str = "";
  while (c != '\n') {
    str += c;
    c = getch();
  }
  return str;
}

void load_interface::Help() {
  clear();
  keypad(stdscr, true);
  start_color();

  move(0, 0);
  printw("This is a Help.\n");
  printw("Press any key to exit.\n");
  getch();
}

void load_interface::refresh(text_anchor a[], int n, int highlight) {
  clear();
  keypad(stdscr, true);
  start_color();

  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_BLACK, COLOR_RED);
  for (int i = 0; i < n; i++) {
    int l = a[i].text.length();

    move(a[i].x - 1, a[i].y);
    printw(" ");
    for (int j = 1; j <= l; j++)
      printw("-");
    printw(" ");

    move(a[i].x, a[i].y);
    printw("|");
    attron(COLOR_PAIR(i == highlight));
    printw("%s", a[i].text.c_str());
    attroff(COLOR_PAIR(i == highlight));
    printw("|");

    move(a[i].x + 1, a[i].y);
    printw(" ");
    for (int j = 1; j <= l; j++)
      printw("-");
    printw(" ");
  }

  move(30, 0);
}

std::string load_interface::get_order() {

  int highlight = 0;
  this->refresh(load, 5, highlight);
  move(30, 0);

  int c = getch();
  while (c != ' ') {
    if (c == KEY_UP)
      highlight = this->load[highlight].direct[0];
    if (c == KEY_DOWN)
      highlight = this->load[highlight].direct[1];
    if (c == KEY_LEFT)
      highlight = this->load[highlight].direct[2];
    if (c == KEY_RIGHT)
      highlight = this->load[highlight].direct[3];
    printw("%d", highlight);
    this->refresh(load, 5, highlight);
    move(30, 0);
    c = getch();
  }
  if (highlight == 0) {
    if (this->load[1].text == " Key Mode ")
      return "New_Game_Key";
    else
      return "New_Game_Cli";
  }
  if (highlight == 1) {
    if (this->load[highlight].text == " Key Mode ")
      this->load[highlight].text = "Click Mode";
    else
      this->load[highlight].text = " Key Mode ";
  }
  if (highlight == 2)
    return "Load " + this->save_or_load("Load from (input filename): ");
  if (highlight == 3)
    this->Help();
  if (highlight == 4)
    return "End_Game";

  return "Error";
}
// class load_interface
pause_interface::pause_interface() {
  clear();
  initscr();
  cbreak();
  keypad(stdscr, true);
  start_color();

  this->pause[0].text = "  New_Game  ";
  this->pause[1].text = "Load";
  this->pause[2].text = "    Help    ";
  this->pause[3].text = "  End_Game  ";
  this->pause[4].text = "  Continue  ";
  this->pause[5].text = "Save";

  this->pause[4].x = 3;
  this->pause[4].y = 30;
  this->pause[1].x = 7;
  this->pause[1].y = 30;
  this->pause[5].x = 7;
  this->pause[5].y = 38;
  this->pause[0].x = 11;
  this->pause[0].y = 30;
  this->pause[2].x = 15;
  this->pause[2].y = 30;
  this->pause[3].x = 19;
  this->pause[3].y = 30;

  int a[6][4] = {{5, 2, 0, 0}, {4, 0, 1, 5}, {0, 3, 2, 2},
                 {2, 3, 3, 3}, {4, 1, 4, 4}, {4, 0, 1, 5}};
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 4; j++)
      this->pause[i].direct[j] = a[i][j];

  this->refresh(pause, 6, 4);
}

std::string pause_interface::get_order() {
  int highlight = 4;
  this->refresh(pause, 6, highlight);
  move(30, 0);

  int c = getch();
  while (c != ' ') {
    if (c == KEY_UP)
      highlight = this->pause[highlight].direct[0];
    if (c == KEY_DOWN)
      highlight = this->pause[highlight].direct[1];
    if (c == KEY_LEFT)
      highlight = this->pause[highlight].direct[2];
    if (c == KEY_RIGHT)
      highlight = this->pause[highlight].direct[3];

    this->refresh(pause, 6, highlight);
    move(30, 0);
    c = getch();
  }
  if (highlight == 0)
    return "New_Game";
  if (highlight == 3)
    return "End_Game";
  if (highlight == 2)
    this->Help();
  if (highlight == 4)
    return "Continue";
  if (highlight == 1) {
    return "Load " + this->save_or_load("Load from (input filename): ");
  }
  if (highlight == 5) {
    return "Save " + this->save_or_load("Save as: ");
  }
  return "Error";
}
// class pause_interface

game_interface::game_interface() {
  keypad(stdscr, true);
  start_color();

  // this->rank->round_set(round);
}
void game_interface::set_round(int &round) { this->round = &round; }
void game_interface::print_map() {
  move(0, 0);

  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_BLUE);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);

  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= 20; j++) {
      attron(COLOR_PAIR(this->board->map_query(i, j)));
      printw("  ");
      attroff(COLOR_PAIR(this->board->map_query(i, j)));
    }
    printw("\n");
  }
}

void game_interface::print_interface() {
  move(22, 0);
  printw("Your score: %d\n", this->board->now_score());
  printw("Now is Round %d\n", *this->round);
  printw("target score is %d\n",
         *this->round * 24000 + 2000 * *this->round * (*this->round - 1) / 2);
}

void game_interface::refresh() {
  erase();

  this->print_map();
  this->print_interface();
  this->rank->print_rank();
}

void game_interface::link_map(mp::map *mp) { this->board = mp; }

void game_interface::link_rank(sl::rank_list *rank_list) {
  this->rank = rank_list;
}

std::string game_interface::mouse_operation(int &y, int &x) {
  keypad(stdscr, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);
  MEVENT event;
  int ch;

  move(0, 0);
  while (true) {
    ch = getch();
    if (ch == KEY_MOUSE && getmouse(&event) == OK) {
      y = event.y;
      x = event.x / 2;
      return "Chosen";
    } else if (ch == 'p')
      return "Pause";
  }
}

std::string game_interface::keyboard_operation(int &y, int &x) {
  move(y, 2*x);
  keypad(stdscr, true);
  int ch;

  while (true) {
    ch = getch();
    switch (ch) {
    case KEY_UP:
      if (y > 0)
        y--;
      break;
    case KEY_DOWN:
      if (y < 19)
        y++;
      break;
    case KEY_LEFT:
      if (x > 0)
        x--;
      break;
    case KEY_RIGHT:
      if (x < 19)
        x++;
      break;
    case ' ':
      return "Chosen";
    case 'p':
      return "Pause";
    }
    move(y, 2*x);
  }
}
} // namespace vi
