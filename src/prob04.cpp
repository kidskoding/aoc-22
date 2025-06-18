#include "prob04.h"

#include <fstream>
#include <sstream>
#include <string>

int countOverlappingPairs() {
    std::fstream fs("./input/prob04.txt");
    std::vector<std::string> parts;
    int overlappingPairs = 0;

    while(fs.good()) {
        std::string line;
        std::getline(fs, line);

        std::string part;
        std::stringstream ss(line);
        while(std::getline(ss, part, ',')) {
            parts.push_back(part);
        }
    }

    std::vector<std::string> pairs;
    for(size_t i = 0; i < parts.size(); ++i) {
        pairs.push_back(parts[i]);

        if(pairs.size() == 2) {
            int r1_start, r1_end;
            int r2_start, r2_end;

            parseRangeNumerical(pairs[0], r1_start, r1_end);
            parseRangeNumerical(pairs[1], r2_start, r2_end);
            if((r1_start <= r2_start && r1_end >= r2_end) || (r2_start <= r1_start && r2_end >= r1_end)) {
                overlappingPairs += 1;
            }

            pairs.clear();
        }
    }

    return overlappingPairs;
}

int countOverlappingPairRanges() {
    std::fstream fs("./input/prob04.txt");
    std::vector<std::string> parts;
    int overlappingPairs = 0;

    while(fs.good()) {
        std::string line;
        std::getline(fs, line);

        std::string part;
        std::stringstream ss(line);
        while(std::getline(ss, part, ',')) {
            parts.push_back(part);
        }
    }

    std::vector<std::string> pairs;
    for(size_t i = 0; i < parts.size(); ++i) {
        pairs.push_back(parts[i]);

        if(pairs.size() == 2) {
            int r1_start, r1_end;
            int r2_start, r2_end;

            parseRangeNumerical(pairs[0], r1_start, r1_end);
            parseRangeNumerical(pairs[1], r2_start, r2_end);
            if((r1_start <= r2_end) && (r1_end >= r2_start)) {
                overlappingPairs += 1;
            }

            pairs.clear();
        }
    }

    return overlappingPairs;
}

void parseRangeNumerical(const std::string& rangeStr, int& start, int& end) {
    size_t dashPos = rangeStr.find('-');
    if(dashPos != std::string::npos) {
        start = std::stoi(rangeStr.substr(0, dashPos));
        end = std::stoi(rangeStr.substr(dashPos + 1));
    }
}