#pragma once

#include "DisplayStrategy.h"
#include "Player.h"

class ConsoleDisplay : public DisplayStrategy {
    uint8_t roundNumber;
    uint8_t tableCardsCount;
    uint8_t playedCardsCount;
    uint8_t playerCount;

public:
    ConsoleDisplay();

    void displayPlayedCards(const CardList& cards) const override;

    void displayTableCards(const CardList& cards) const override;

    void displayScores(const std::vector<Player*>& players) const override;

    void displayGameState() const override;

    void update(PishtiEvent type, void *payload) override;
};
