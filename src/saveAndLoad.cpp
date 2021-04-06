#include "saveAndLoad.h"

namespace sl {
    int current_map::save(mp::map *board, int round, std::string name) {
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
            printf("Store operation failed:\ncannot open file %s", filename.c_str());
            return 1;
        }

        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++)
                fout << board->map_query(i, j);
            fout << std::endl;
        }

        fout << board->now_score() << std::endl;
        fout << round << std::endl;

        fout.close();
        return 0;
    }
}
