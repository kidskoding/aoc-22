#include "prob05.h"
#include <deque>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

std::string part1() {
    std::fstream fs("./input/prob05.txt");
    std::vector<std::string> lines;
    while(fs.good()) {
        std::string line;
        std::getline(fs, line);
        if(line[1] == '1') {
            break;
        }
        lines.push_back(line);
    }

    std::vector<std::vector<char>> arr;
    for(int i = 0; i < lines.size(); i++) {
        std::vector<char> innerArr;
        std::string& str = lines[i];
        int j = 0;

        while(j < str.size() - 2) {
            std::string chunk = str.substr(j, 3);
            if(chunk == "   ") {
                innerArr.push_back(' ');
            } else if(chunk[0] == '[' && chunk[2] == ']') {
                innerArr.push_back(chunk[1]);
            }
            j += 4;
        }

        arr.push_back(innerArr);
    }

    std::vector<std::stack<char>> stacks;
    for(int c = 0; c < arr[0].size(); c++) {
        std::stack<char> stack;
        for(int r = arr.size() - 1; r >= 0; r--) {
            if(c < arr[r].size() && arr[r][c] != ' ') {
                stack.push(arr[r][c]);
            }
        }
        stacks.push_back(stack);
    }

    std::string instruction;
    while(std::getline(fs, instruction)) {
        std::stringstream ss(instruction);
        std::vector<std::string> chunks;
        if(instruction.empty()) {
            continue;
        }

        std::string chunk;
        while(ss >> chunk) {
            chunks.push_back(chunk);
        }

        int n = std::stoi(chunks[1]);
        int source = std::stoi(chunks[3]);
        int destination = std::stoi(chunks[5]);
        for(int k = 1; k <= n; k++) {
            char val = stacks[source - 1].top();
            stacks[source - 1].pop();
            stacks[destination - 1].push(val);
        }
    }

    std::string res;
    for(std::stack<char>& stack : stacks) {
        res += stack.top();
    }

    return res;
}

std::string part2() {
    std::fstream fs("./input/prob05.txt");
    std::vector<std::string> lines;
    while(fs.good()) {
        std::string line;
        std::getline(fs, line);
        if(line[1] == '1') {
            break;;
        }
        lines.push_back(line);
    }

    std::vector<std::vector<char>> arr;
    for(int i = 0; i < lines.size(); i++) {
        std::vector<char> innerArr;
        std::string& str = lines[i];
        int j = 0;

        while(j < str.size() - 2) {
            std::string chunk = str.substr(j, 3);
            if(chunk == "   ") {
                innerArr.push_back(' ');
            } else if(chunk[0] == '[' && chunk[2] == ']') {
                innerArr.push_back(chunk[1]);
            }
            j += 4;
        }

        arr.push_back(innerArr);
    }

    std::vector<std::stack<char>> stacks;
    for(int c = 0; c < arr[0].size(); c++) {
        std::stack<char> stack;
        for(int r = arr.size() - 1; r >= 0; r--) {
            if(c < arr[r].size() && arr[r][c] != ' ') {
                stack.push(arr[r][c]);
            }
        }
        stacks.push_back(stack);
    }

    std::string instruction;
    while(std::getline(fs, instruction)) {
        std::stringstream ss(instruction);
        std::vector<std::string> chunks;
        if(instruction.empty()) {
            continue;
        }

        std::string chunk;
        while(ss >> chunk) {
            chunks.push_back(chunk);
        }

        int n = std::stoi(chunks[1]);
        int source = std::stoi(chunks[3]);
        int destination = std::stoi(chunks[5]);

        std::deque<char> deque;
        for(int k = 1; k <= n; k++) {
            char val = stacks[source - 1].top();
            stacks[source - 1].pop();
            deque.push_back(val);
        }
        while(!deque.empty()) {
            char temp = deque.back();
            deque.pop_back();
            stacks[destination - 1].push(temp);
        }
    }

    std::string res;
    for(std::stack<char>& stack : stacks) {
        res += stack.top();
    }

    return res;
}