#include "saveAndLoad.h"

namespace sl {
    rank_list::rank_list(std::string filename) {
        this->filename = "log/" + filename;
        std::ifstream fin (this->filename.c_str());

        std::string name;
        int score;
        this->ranker_num = 0;

        if (fin.fail()) {
            move(25, 0);
            printw("Cannot load log/%s\n", filename.c_str());
            printw("Press any key to exit.");
            getch();
            return;
        }
        
        while (fin >> name) {
            fin >> score;
            if (name.length() <= 10) 
                add(name, score);
        }
        fin.close();
    }
    
    void rank_list::sort() {
        for (int i = ranker_num; i > 0; i--) {
            if (this->rk[i].score > this->rk[i-1].score) {
                ranklist k = this->rk[i];
                this->rk[i] = this->rk[i-1];
                this->rk[i-1] = k;
            } 
            else 
                break;
        }
    }
    
    void rank_list::add(std::string name, int score) {
        this->rk[ranker_num].name = name;
        this->rk[ranker_num].score = score;
        this->sort();
        this->ranker_num++;
    } 

    int rank_list::save() {
        std::ofstream fout;
        fout.open(this->filename);

        if (fout.fail()) {
            move(25, 0);
            printw("Store operation failed:\ncannot open file %s\n", filename.c_str());
            printw("Press any key to exit.");
            getch();
            return 1;
        }

        for (int i = 0; i < this->ranker_num; i++) 
            fout << this->rk[i].name << ' ' << this->rk[i].score << std::endl;

        fout.close();
        return 0;
    }

    void rank_list::print_rank() {
        move(0,25);
        printw("Rank List:");
        for (int i = 0; i < this->ranker_num; i++) {
            move(i+2, 25);
            printw("%s", this->rk[i].name.c_str());
            move(i+2, 35);
            printw(" %d\n", this->rk[i].score);
        }
    }

    current_map::current_map(mp::map *board, int round) {
        this->board = board;
        this->round = round;
    }

    int current_map::save(std::string name) {
        // Find current time and store it in buffer
        time_t rawtime;
        struct tm * timeinfo;
        char buffer [80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, 80, "%F-%H-%M-%S", timeinfo);

        // Write to file
        std::string filename = "log/" + name + '-' + buffer + ".txt";
        std::ofstream fout;
        fout.open(filename);

        if (fout.fail()) {
            move(0, 1);
            printw("Store operation failed: cannot open file %s\n", filename.c_str());
            printw("Press any key to exit.");
            getch();
            return 1;
        }

        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++)
                fout << this->board->map_query(i, j) << ' ';
            fout << std::endl;
        }

        fout << this->board->now_score() << std::endl;
        fout << this->round << std::endl;

        fout.close();

        move(1, 0);
        printw("Save success! Press any key to quit.\n");
        getch();

        return 0;
    }

    int current_map::load(std::string name) {
        int val;
        std::ifstream fin;
        std::string filename = "log/" + name;
        fin.open(filename.c_str());

        if (fin.fail()) {
            move(1, 0);
            printw("Load operation failed: cannot open file %s\n", filename.c_str());
            printw("Press any key to exit.");
            getch();
            return 1;
        }

        for (int i = 1; i <= 20; i++) 
            for (int j = 1; j <= 20; j++) {
                fin >> val;
                this->board->map_set(i, j, val);
            }
        fin >> val;
        this->board->score_set(val);
        fin >> this->round;
        
        fin.close();

        move(1, 0);
        printw("Load success! Press any key to quit.\n");
        getch();

        return 0;       
    }
    int current_map::get_round() {
        return this->round;
    }
}
