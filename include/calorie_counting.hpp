#pragma once

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int getMaxCalories() {
    std::vector<int> calories;
    std::fstream fs("input/calorie_counting.txt");

    std::string line;
    while(std::getline(fs, line)) {
        int totalCalories = 0;
        if(line.empty()) {
            calories.push_back(totalCalories);
            totalCalories = 0;
        } else {
            totalCalories += std::stoi(line);
        }
    }

    return *std::max_element(calories.begin(), calories.end());
}
