#include "prob11.h"
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstddef>
#include <print>

int part1() {
    std::fstream fs("./input/prob11.txt");
	
    std::map<int, std::vector<int>> map;
    std::map<int, char> opCharMap;      
    std::map<int, std::string> operand1Map;
    std::map<int, std::string> operand2Map;
    std::map<int, int> testDivisorMap;     
    std::map<int, int> trueTargetMap;      
    std::map<int, int> falseTargetMap;     
    std::map<int, int> inspectionCount;

    while(fs.good()) {
        int monkeyNo = -1;
        std::vector<int> worryLevels;
        char opChar = 0;
        std::string operand1, operand2;
        int testDivisor = 0;
        int trueTarget = 0;
        int falseTarget = 0;

        for(int k = 1; k <= 6; k++) {
            std::string line;
            std::getline(fs, line);
            if(line.empty()) {
                break;
            }

            switch(k) {
                case 1: {
                    monkeyNo = std::stoi(line.substr(7));
                    break;
                }
                case 2: {
                    size_t colonPos = line.find(':');
                    if(colonPos == std::string::npos) {
                        throw std::runtime_error("Line missing colon: " + line);
                    }
                    std::string worryVals = line.substr(colonPos + 2);
                    size_t start = 0, end;
                    while((end = worryVals.find(", ", start)) != std::string::npos) {
                        worryLevels.push_back(std::stoi(worryVals.substr(start, end - start)));
                        start = end + 2;
                    }
                    worryLevels.push_back(std::stoi(worryVals.substr(start)));
                    break;
                }
                case 3: {
                    int eqPos = line.find('=');
                    std::string expr = line.substr(eqPos + 2);
                    operand1 = expr.substr(0, 3);
                    opChar = expr[4];
                    operand2 = expr.substr(6);
                    break;
                }
                case 4: {
                    testDivisor = std::stoi(line.substr(21));
                    break;
                }
                case 5: {
                    trueTarget = std::stoi(line.substr(29));
                    break;
                }
                case 6: {
                    falseTarget = std::stoi(line.substr(30));
                    break;
                }
            }
        }

        if(monkeyNo != -1) {
            map[monkeyNo] = worryLevels;
            opCharMap[monkeyNo] = opChar;
            operand1Map[monkeyNo] = operand1;
            operand2Map[monkeyNo] = operand2;
            testDivisorMap[monkeyNo] = testDivisor;
            trueTargetMap[monkeyNo] = trueTarget;
            falseTargetMap[monkeyNo] = falseTarget;
            inspectionCount[monkeyNo] = 0;
        }
    }

    for(int round = 0; round < 20; ++round) {
        for(auto& [monkeyNo, items] : map) {
            std::vector<int> currentItems = items;
            items.clear();
            inspectionCount[monkeyNo] += currentItems.size();

            for(int val : currentItems) {
                int val1 = (operand1Map[monkeyNo] == "old") ? val : std::stoi(operand1Map[monkeyNo]);
                int val2 = (operand2Map[monkeyNo] == "old") ? val : std::stoi(operand2Map[monkeyNo]);

                int res = 0;
                switch(opCharMap[monkeyNo]) {
                    case '+': res = val1 + val2; break;
                    case '-': res = val1 - val2; break;
                    case '*': res = val1 * val2; break;
                    case '/': res = val1 / val2; break;
                    default: throw std::runtime_error("Invalid operation");
                }

                res /= 3;

                if(res % testDivisorMap[monkeyNo] == 0) {
                    map[trueTargetMap[monkeyNo]].push_back(res);
                } else {
                    map[falseTargetMap[monkeyNo]].push_back(res);
                }
            }
        }
    }

    std::vector<int> counts;
    for(const auto& [_, count] : inspectionCount) {
        counts.push_back(count);
    }
    std::sort(counts.begin(), counts.end(), std::greater<>());
    return counts[0] * counts[1];
}

int part2() {

}