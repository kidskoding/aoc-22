#include <algorithm>
#include <cstddef>
#include <fstream>
#include "prob08.h"

int countVisibleTrees() {
    std::fstream fs("./input/prob08.txt");
    std::vector<std::vector<int>> grid;
    std::string line;
    while(std::getline(fs, line)) {
        std::vector<int> innerGrid;
        for(size_t i = 0; i < line.size(); i++) {
            innerGrid.push_back(std::stoi(line.substr(i, 1)));
        }
        grid.push_back(innerGrid);
    }

    int count = 0;
    for(size_t r = 0; r < grid.size(); r++) {
        for(size_t c = 0; c < grid[r].size(); c++) {
            if(isAtEdge(r, c, grid) || isVisible(r, c, grid)) {
                count++;
            }
        }
    }

    return count;
}

int getMaxScenicScore() {
    std::fstream fs("./input/prob08.txt");
    std::vector<std::vector<int>> grid;
    std::string line;
    int maxScenicScore = 0;

    while(std::getline(fs, line)) {
        std::vector<int> innerGrid;
        for(size_t i = 0; i < line.size(); i++) {
            innerGrid.push_back(std::stoi(line.substr(i, 1)));
        }
        grid.push_back(innerGrid);
    }

    for(size_t r = 0; r < grid.size(); r++) {
        for(size_t c = 0; c < grid[r].size(); c++) {
            maxScenicScore = std::max(maxScenicScore, getScenicScore(r, c, grid));
        }
    }

    return maxScenicScore;
}

bool isAtEdge(size_t r, size_t c, const std::vector<std::vector<int>>& grid) {
    return r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1;
}

bool isVisible(size_t rowIdx, size_t colIdx, std::vector<std::vector<int>>& vec) {
    int curVal = vec[rowIdx][colIdx];

    bool rightVisible = true;
    for(int c = colIdx + 1; c < vec[0].size(); c++) {
        if(vec[rowIdx][c] >= curVal) {
            rightVisible = false;
            break;
        }
    }

    bool leftVisible = true;
    for(int c = colIdx - 1; c >= 0; c--) {
        if(vec[rowIdx][c] >= curVal) {
            leftVisible = false;
            break;
        }
    }

    bool topVisible = true;
    for(int r = rowIdx + 1; r < vec.size(); r++) {
        if(vec[r][colIdx] >= curVal) {
            topVisible = false;
            break;
        }
    }

    bool bottomVisible = true;
    for(int r = rowIdx - 1; r >= 0; r--) {
        if(vec[r][colIdx] >= curVal) {
            bottomVisible = false;
            break;
        }
    }

    return rightVisible || leftVisible || topVisible || bottomVisible;
}

int getScenicScore(size_t rowIdx, size_t colIdx, std::vector<std::vector<int>>& vec) {
    int curVal = vec[rowIdx][colIdx];

    int rightCount = 0;
    for(int c = colIdx + 1; c < vec[0].size(); c++) {
        rightCount++;
        if(vec[rowIdx][c] >= curVal) {
            break;
        }
    }

    int leftCount = 0;
    for(int c = colIdx - 1; c >= 0; c--) {
        leftCount++;
        if(vec[rowIdx][c] >= curVal) {
            break;
        }
    }

    int topCount = 0;
    for(int r = rowIdx + 1; r < vec.size(); r++) {
        topCount++;
        if(vec[r][colIdx] >= curVal) {
            break;
        }
    }

    int bottomCount = 0;
    for(int r = rowIdx - 1; r >= 0; r--) {
        bottomCount++;
        if(vec[r][colIdx] >= curVal) {
            break;
        }
    }

    return topCount * bottomCount * leftCount * rightCount;
}