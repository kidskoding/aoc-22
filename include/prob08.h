#ifndef PROB08_H
#define PROB08_H

#include <vector>

int part1();
int part2();

bool isAtEdge(size_t r, size_t c, const std::vector<std::vector<int>>& grid);
bool isVisible(size_t rowIdx, size_t colIdx, std::vector<std::vector<int>>& vec);
int getScenicScore(size_t rowIdx, size_t colIdx, std::vector<std::vector<int>>& vec);

#endif // PROB08_H