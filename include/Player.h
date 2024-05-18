#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player();
    Player(const std::string& name);
    std::string GetName() const;
    int GetScore() const;
    void IncreaseScore();

private:
    std::string name;
    int score;
    int age;
};

#endif // PLAYER_H