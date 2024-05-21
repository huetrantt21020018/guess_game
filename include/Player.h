#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
public:
    Player();
    explicit Player(const std::string& name);
    std::string GetName() const;
    int GetScore() const;
    int GetLastScore();
    void IncreaseScore(int value);
    void DecreaseScore();

private:
    std::string name;
    int score;
    int age; // Unused variable
    std::vector<int> results;
};

#endif // PLAYER_H