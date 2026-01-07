#include "prob10.h"
#include <fstream>
#include <string>
#include <vector>

int part1() {
    std::fstream fs("./input/prob10.txt");
    std::string line;
    int x = 1;
    int cycleToGet = 20;
    int cycles = 0;
    int sum = 0;
    while(std::getline(fs, line)) {
        std::string opcode = line.substr(0, 4);
        if(cycles + 2 >= cycleToGet) {
            sum += cycleToGet * x;
            cycleToGet += 40;
        }
        if(opcode == "addx") {
            int val = std::stoi(line.substr(5));
            x += val;
            cycles += 2;
        } else {
            cycles += 1;
        }
    }

    return sum;
}

std::string part2() {
    std::fstream fs("./input/prob10.txt");
    std::string line;
    int x = 1;
    int cycle = 1;
    std::vector<std::string> screen(6, "");

    auto draw = [&](int c, int x) {
        int col = (c - 1) % 40;
        int row = (c - 1) / 40;
        if(row < 6) {
            screen[row] += (col >= x - 1 && col <= x + 1) ? '#' : '.';
        }
    };

    while(std::getline(fs, line)) {
        std::string opcode = line.substr(0, 4);
        if(opcode == "addx") {
            int val = std::stoi(line.substr(5));
            draw(cycle++, x);
            draw(cycle++, x);
            x += val;
        } else {
            draw(cycle++, x);
        }
    }

    std::string res;
    for(const auto& x : screen) {
        res += x + "\n";
    }
    
    return res;
}