#pragma once

#include "Player.h"

// Represents a display strategy for a Pishti game
class DisplayStrategy: public PishtiObserver {
public:
    virtual void displayPlayedCards(const CardList& cards) const = 0;

    virtual void displayTableCards(const CardList& cards) const = 0;

    virtual void displayScores(const std::vector<Player*>& players) const = 0;

    virtual void displayGameState() const = 0;

    void update(PishtiEvent type, void *payload) override = 0;

    ~DisplayStrategy() override = default;
};
