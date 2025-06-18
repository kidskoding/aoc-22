#include "prob02.h"

#include <fstream>
#include <unordered_map>

int getScore() {
    std::fstream fs("./input/prob02.txt");

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

int getScore2() {
    std::fstream fs("./input/prob02.txt");

    std::unordered_map<char, int> scores;
    scores.insert(std::make_pair('X', 1));
    scores.insert(std::make_pair('Y', 2));
    scores.insert(std::make_pair('Z', 3));

    std::unordered_map<char, char> outcomes;
    outcomes.insert(std::make_pair('A', 'Y'));
    outcomes.insert(std::make_pair('B', 'Z'));
    outcomes.insert(std::make_pair('C', 'X'));

    std::unordered_map<char, char> draws;
    draws.insert(std::make_pair('A', 'X'));
    draws.insert(std::make_pair('B', 'Y'));
    draws.insert(std::make_pair('C', 'Z'));

    std::unordered_map<char, char> losses;
    losses.insert(std::make_pair('A', 'Z'));
    losses.insert(std::make_pair('B', 'X'));
    losses.insert(std::make_pair('C', 'Y'));

    int score = 0;
    while(fs.good()) {
        std::string input;
        std::getline(fs, input);
        if(input.empty()) continue;

        char opponent = input[0];
        char desired = input[2];

        if(desired == 'X') { // lose
            score += scores[losses[opponent]];
        } else if(desired == 'Y') { // draw
            score += scores[draws[opponent]] + 3;
        } else { // win
            score += scores[outcomes[opponent]] + 6;
        }
    }
    return score;
}
