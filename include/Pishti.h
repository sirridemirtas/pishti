#pragma once

#include "Deck.h"
#include "Player.h"

// Maintains and provides the game state
// The game is managed by the Manager class
class Pishti {
    std::vector<Player *> players;

    // Standard deck of cards
    Deck deck;

    // The cards that are currently in play
    CardList pile;

    // The player who is currently playing the turn
    int turn = 0;

    // The current round of the game
    // Number of rounds played so far
    // It is incremented each time a new round begins
    int round = 0;

    // The score required to win the game
    // Target score needed to end the game
    // New rounds are played until this score is reached or exceeded
    int endGameScore = 51;

    // Played cards in the current round
    std::vector<Card *> playedCards;

    // Score of each player
    std::vector<std::pair<Player *, int> > scores;

    bool gameOver = false;

public:
    Pishti() = default;

    ~Pishti();

    void setScore(Player *player, int score);

    int getScore(Player *player) const;

    bool isGameOver() const;

    uint8_t getDeckSize() const;

    friend class Manager;
};
