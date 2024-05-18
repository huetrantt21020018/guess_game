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

void Player::IncreaseScore() {
    score++;
}