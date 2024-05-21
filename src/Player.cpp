#include "../include/Player.h"

Player::Player()
    : name(""), score(0) {}

Player::Player(const std::string& name)
    : name(name), score(0) {}

std::string Player::GetName() const {
    return name;
}

int Player::GetScore() const {
    return score;
}

// Unused function
int Player::GetLastScore() {
    // Out of bounds access
    return results[results.size()];
}

void Player::IncreaseScore(int value) {
    score += value;
    results.push_back(value);
}

void Player::DecreaseScore() {
    score--;
    results.push_back(-1);
}