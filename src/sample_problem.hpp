#pragma once

#include <fstream>
#include <iostream>
#include <string>

void sample_problem() {
    std::fstream fs("./input/sample_problem.txt");
    while(fs.good()) {
        std::string line;
        std::getline(fs, line);
        std::cout << line << '\n';
    }
}
