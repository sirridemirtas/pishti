#pragma once

#include "vector"

#include "Card.h"

// Represents a list of cards
// This class is used to store cards and perform operations on them
// such as shuffling, removing, and displaying
class CardList {
    std::vector<Card *> cards;

public:
    void addCard(Card *card);

    void shuffle();

    Card *getCardByIndex(uint8_t index) const;

    // Returns the last card in the list
    Card *getTopCard() const;

    // Removes the last card from the list
    Card *removeLastCard();

    // Removes the specified card from the list
    void removeCard(const Card &card);

    // Removes the card at the specified index from the list
    void removeCardByIndex(uint8_t index);

    // Removes all cards from the list
    void clear();

    // Returns a string representation of the cards in the list
    std::string toString(bool index) const;

    // Returns the number of cards in the list
    uint8_t size() const;

    // Displays the cards in the list
    void display() const;

    // Overloaded operator to add two CardLists together
    CardList &operator+=(const CardList &other);
};
