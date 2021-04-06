#include "saveAndLoad.h"

namespace sl {
    current_map::current_map(mp::map *board, int &round) {
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
            printf("Store operation failed:\ncannot open file %s\n", filename.c_str());
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
            printf("Store operation failed:\ncannot open file %s", filename.c_str());
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
}
