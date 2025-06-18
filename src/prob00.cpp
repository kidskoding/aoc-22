#include "prob00.h"

#include <fstream>
#include <iostream>
#include <string>

void sampleProblem() {
    std::fstream fs("./input/prob00.txt");
    while(fs.good()) {
        std::string line;
        std::getline(fs, line);
        std::cout << line << '\n';
    }
}