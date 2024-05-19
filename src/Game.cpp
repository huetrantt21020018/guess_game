#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Game.h"

Game::Game() {
    attemptsLeft = 0;
    secretNumber = 0;
    playerCreated = false;
}

void Game::Run() {
    std::string playerName;
    bool continuePlaying = true;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    while (continuePlaying) {
        if (!playerCreated) {
            std::cout << "Enter your name: ";
            std::cin >> playerName;
            player = Player(playerName);
            playerCreated = true;
        }

        Initialize();

        while (attemptsLeft > 0) {
            PlayRound();
        }

        std::cout << "Game over! The secret number was: " << secretNumber << std::endl;
        DisplayScore();

        char choice;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            continuePlaying = false;
            std::cout << "Final score: " << player.GetScore() << "\n";
        }
    }
}

void Game::Initialize() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    secretNumber = std::rand() % 100 + 1;  
    attemptsLeft = 9;
}

int Game::GetPlayerGuess() const {
    int guess;
    std::cout << "Enter your guess (1-100): ";
    std::cin >> guess;
    return guess;
}

void Game::PlayRound() {
    int guess = GetPlayerGuess();

    if (IsGuessCorrect(guess)) {
        DisplayResult(true, false);
        player.IncreaseScore(attemptsLeft);
        attemptsLeft = 0;  
    } else {
        attemptsLeft--;
        if (attemptsLeft > 0) {
            if (guess < secretNumber) {
                DisplayResult(false, true);
            } else {
                DisplayResult(false, false);
            }
            std::cout << "Attempts left: " << attemptsLeft << std::endl;
        } else {
            std::cout << "Sorry, you ran out of attempts!" << std::endl;
            player.DecreaseScore();
        }
    }
}

bool Game::IsGuessCorrect(int guess) const {
    return guess == secretNumber;
}

void Game::DisplayResult(bool isCorrect, bool isGreater) {
    if (isCorrect) {
        std::cout << "Congratulations, " << player.GetName() << "! You guessed the correct number." << std::endl;
    } else {
        std::cout << "Sorry, " << player.GetName() << ", your guess was incorrect." << std::endl;
        if (isGreater) {
            std::cout << "The secret number is greater than your guess." << std::endl;
        } else {
            std::cout << "The secret number is smaller than your guess." << std::endl;
        }
    }
}

void Game::DisplayScore() {
    std::cout << player.GetName() << "'s score: " << player.GetLastScore() << std::endl;
}