#pragma once

#include <string>

#include "CardList.h"
#include "PishtiEvent.h"
#include "PishtiObserver.h"

class Player : public PishtiObserver {
protected:
    // The name of the player
    std::string name;

    // The cards a player currently holds and can play
    CardList hand;

    // The cards a player has collected during the game
    CardList pile;

    void addCard(Card *card);

    void displayHand() const;

    virtual Card *playCard() = 0;

    virtual void collectPile(CardList &collectedPile);

    /*virtual void clearHand();

    virtual void getHand() const;*/

    // Update the player with the event
    void update(PishtiEvent type, void *payload) override = 0;

public:
    explicit Player(std::string name);

    virtual std::string getName() const;

    friend class Manager;
};
