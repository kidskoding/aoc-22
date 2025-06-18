#include "prob06.h"
#include <fstream>
#include <set>

int getFirstStartOfPacket() {
    std::fstream fs("./input/prob06.txt");
    std::string line;
    std::getline(fs, line);
    for(int i = 0; i < line.size() - 4; i++) {
        std::string sub = line.substr(i, 4);
        std::set<char> set(sub.begin(), sub.end());
        if(set.size() == sub.size()) {
            return i + 4;
        }
    }
    return 0;
}

int getFirstStartOfPacket2() {
    std::fstream fs("./input/prob06.txt");
    std::string line;
    std::getline(fs, line);
    for(int i = 0; i < line.size() - 14; i++) {
        std::string sub = line.substr(i, 14);
        std::set<char> set(sub.begin(), sub.end());
        if(set.size() == sub.size()) {
            return i + 14;
        }
    }
    return 0;
}