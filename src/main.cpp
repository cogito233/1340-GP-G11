#include "map.h"
#include "saveAndLoad.h"
#include "visualization.h"
#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;

mp::map *board;
vi::game_interface *game;
vi::load_interface *load;
vi::pause_interface *pause;
sl::current_map *cur_map;
sl::rank_list *rank_list;
void end_game() {
  delete board;
  delete game;
  delete load;
  delete pause;
  delete cur_map;
  delete rank_list;
}

signed main() {
  initscr();
  cbreak();
  noecho();

  int round = 1;
  std::string rank_name = "rank.txt";

  board = new mp::map();
  rank_list = new sl::rank_list(rank_name);
  pause = new vi::pause_interface();
  game = new vi::game_interface();
  game->set_round(round);
  load = new vi::load_interface();
  cur_map = new sl::current_map(board, round);

  bool flag_load = 1;
  string s;

  while (flag_load) {
    s = load->get_order();
    if (s == "New_Game_Cli" || s == "New_Game_Key")
      flag_load = 0;
    if (s == "End_Game") {
      end_game();
      endwin();
      return 0;
    }
    if (s.find("Load") != std::string::npos)
      cur_map->load(s.substr(5));
  }
  int x = 0, y = 0, score;
  int score_total = 0;
  string str;
  bool isCli = (s == "New_Game_Cli");

  game->link_map(board);
  game->link_rank(rank_list);
  game->refresh();

  while (1) {
    while (!board->is_end()) {
      if (isCli)
        str = game->mouse_operation(y, x);
      else
        str = game->keyboard_operation(y, x);

      if (str == "Pause") {
        bool flag_pause = 1;
        while (flag_pause) {
          string s = pause->get_order();
          if (s == "Continue") {
            flag_pause = 0;
            game->refresh();
          }
          if (s == "New_Game") {
            delete board;
            board = new mp::map();
            delete cur_map;
            round = 1;
            cur_map = new sl::current_map(board, round);
            game->set_round(round);

            game->refresh();
            flag_pause = 0;
          }
          if (s == "End_Game") {
            endwin();
            end_game();
            return 0;
          }
          if (s.find("Save") != std::string::npos)
            cur_map->save(s.substr(5));

          if (s.find("Load") != std::string::npos)
            cur_map->load(s.substr(5));
        }
        continue;
      }

      score = board->operation(y + 1, x + 1);
      // score_total += score;
      game->refresh();
    }

    int now_round = cur_map->get_round();
    int target_score =
        now_round * 24000 + 2000 * now_round * (now_round - 1) / 2;
    int now_score = board->now_score();
    if (now_score < target_score) {
      move(21, 0);
      printw("Sadly, the target score was %d and you got %d\n", target_score,
             now_score);
      break;
    }
    delete board;
    board = new mp::map();
    delete cur_map;
    round = now_round + 1;
    cur_map = new sl::current_map(board, round);
    game->set_round(round);
    board->score_set(now_score);

    game->refresh();
    // flag_pause = 0;
  }
  move(22, 0);
  printw("Game over\nTo display your score on the leaderboard, \nInput your "
         "preferred name here: ");
  
  echo();
  char c = getch();
  std::string name = "";
  while (c != '\n') {
    name += c;
    c = getch();
  }

  if (name != "") {
    rank_list->add(name, board->now_score());
    rank_list->save();
  }

  printw("Press any key to exit.\n");
  getch();
  endwin();

  printf("Your score is: %d\n", board->now_score());
  end_game();

  return 0;
}