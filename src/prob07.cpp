#include "prob07.h"
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <utility>
#include <map>
#include <string>

void getDirectorySizes() {
    std::fstream fs("./input/prob07.txt");
    std::stack<std::string> path;
    std::map<std::string, std::set<std::string>> families;
    std::map<std::string, int> sizes;
    std::string line;
    std::string bufferedLine;
    
    std::getline(fs, line);
    path.push("/");

    while(true) {
        if(!bufferedLine.empty()) {
            line = bufferedLine;
            bufferedLine.clear();
        } else if(!std::getline(fs, line)) {
            break;
        }

        if(line == "$ cd .." && !path.empty()) {
            path.pop();
            continue;
        }
        
        if(line.substr(0, 4) == "$ cd") {
            path.push(line.substr(5));
            continue;
        }
        
        if(line.substr(0, 4) == "$ ls") {
            std::string contents;
            while(std::getline(fs, contents)) {
                if(contents[0] == '$') {
                    bufferedLine = contents;
                    break;
                }
            }
        }
    }

    while(!path.empty()) {
        std::cout << path.top() << std::endl;
        path.pop();
    }
}