#include "prob03.h"

#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>

int prioritize() {
    std::fstream fs("input/prob03.txt");
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

        char commonChar = '\0';
        for(const auto& item : firstSet) {
            if(secondSet.find(item) != secondSet.end()) {
                commonChar = item;
                break;
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

int prioritizeInGroups() {
    std::fstream fs("input/prob03.txt");
    std::vector<std::set<char>> sets;
    int sum = 0;
    std::string line;

    while(std::getline(fs, line)) {
        if(line.empty()) continue;

        std::set<char> set(line.begin(), line.end());
        sets.push_back(set);

        if(sets.size() == 3) {
            char common = commonChar(sets[0], sets[1], sets[2]);
            sum += helper(common);
            sets.clear();
        }
    }

    return sum;
}

char commonChar(std::set<char> one, std::set<char> two, std::set<char> three) {
    std::set<char> commonChars;
    std::set_intersection(one.begin(), one.end(),
        two.begin(), two.end(), std::inserter(commonChars, commonChars.begin()));
    
    std::set<char> finalCommon;
    std::set_intersection(commonChars.begin(), commonChars.end(),
        three.begin(), three.end(), std::inserter(finalCommon, finalCommon.begin()));

    if(finalCommon.empty()) {
        return '\0';
    }
    return *finalCommon.begin();
}

int helper(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 96;
    }
    if(c >= 'A' && c <= 'Z') {
        return c - 38;
    }
    return 0;
}
