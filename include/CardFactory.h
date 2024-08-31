#pragma once

#include <map>

#include "Card.h"

class CardFactory final {
    // Map to hold unique Card objects based on Suit and Rank
    std::map<std::pair<Suit, Rank>, Card *> cardMap;

    CardFactory();

    ~CardFactory();

    // Private static instance pointer for singleton pattern
    static CardFactory *instance;

public:
    // Static method to access the singleton instance
    static CardFactory &getInstance();

    // Method to get or create a Card object
    // If the Card object already exists, return it
    // Otherwise, create a new Card object and return it
    Card *getCard(Suit suit, Rank rank);
};
