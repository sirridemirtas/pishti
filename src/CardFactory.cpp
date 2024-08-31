#include "../include/CardFactory.h"

// Initialize the static member variable
CardFactory *CardFactory::instance = nullptr;

CardFactory::CardFactory() = default;

CardFactory::~CardFactory() {
    // Free all allocated Card objects
    for (auto &entry: cardMap) {
        delete entry.second;
    }
}

// Static method to get the singleton instance
CardFactory &CardFactory::getInstance() {
    if (!instance) {
        instance = new CardFactory();
    }
    return *instance;
}

// Method to get or create a Card object
Card *CardFactory::getCard(Suit suit, Rank rank) {
    std::pair<Suit, Rank> key = std::make_pair(suit, rank);

    auto it = cardMap.find(key);
    if (it != cardMap.end()) {
        return it->second;
    }

    // Create a new Card if it does not exist
    Card *newCard = new Card(suit, rank);
    cardMap[key] = newCard;
    return newCard;
}
