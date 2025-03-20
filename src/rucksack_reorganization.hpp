#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

int prioritize() {
    std::fstream fs("input/rucksack_reorganization.txt");
    int sum = 0;
    while(fs.good()) {
        std::string line;
        std::getline(fs, line);
        if (line.empty()) continue;

        int half = line.size() / 2;

        std::string first = line.substr(0, half);
        std::string second = line.substr(half);

        std::unordered_set<char> firstSet(first.begin(), first.end());
        std::unordered_set<char> secondSet(second.begin(), second.end());

        char commonChar;
        for(auto& item : firstSet) {
            if(secondSet.find(item) != secondSet.end()) {
                commonChar = item;
            }
        }

        if(commonChar >= 'a' && commonChar <= 'z') {
            sum += commonChar - 96;
        } else if(commonChar >= 'A' && commonChar <= 'Z') {
            sum += commonChar - 38;
        }
    }

    return sum;
}
