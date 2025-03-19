#pragma once

#include <fstream>
#include <unordered_map>

int getScore() {
    std::fstream fs("./input/rock_paper_scissors.txt");

    std::unordered_map<char, int> scores;
    scores.insert(std::make_pair('X', 1));
    scores.insert(std::make_pair('Y', 2));
    scores.insert(std::make_pair('Z', 3));

    std::unordered_map<char, char> outcomes;
    outcomes.insert(std::make_pair('A', 'Y'));
    outcomes.insert(std::make_pair('B', 'Z'));
    outcomes.insert(std::make_pair('C', 'X'));

    int score = 0;
    while(fs.good()) {
        std::string input;
        std::getline(fs, input);
        if(input.empty()) continue;

        char opponent = input[0];
        char player = input[2];

        if(outcomes[opponent] == player) {
            score += 6 + scores[player];
        } else if(player - opponent == 23) {
            score += 3 + scores[player];
        } else {
            score += scores[player];
        }
    }

    return score;
}
