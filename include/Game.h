#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
public:
    Game(); 
    void Run();
    
private:
    int attemptsLeft;
    int secretNumber;
    bool playerCreated = false;
    Player player;

    void Initialize();
    int GetPlayerGuess() const;
    void PlayRound();
    bool IsGuessCorrect(int guess) const;
    void DisplayResult(bool isCorrect, bool isGreater);
    void DisplayScore();
};

#endif // GAME_H