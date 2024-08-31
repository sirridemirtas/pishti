#pragma once

#include <string>

enum class Suit : uint8_t {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum class Rank : uint8_t {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

// Represents a playing card
class Card {
    Suit suit;
    Rank rank;

    // Private constructor prevents direct instantiation of Card objects
    // The private constructor is only accessible by the CardFactory class
    Card(Suit s, Rank r);

    // The CardFactory class is declared as a friend to access the private members of this class
    friend class CardFactory;

public:
    Suit getSuit() const;

    Rank getRank() const;

    std::string suitToString() const;

    std::string rankToString() const;

    std::string toString() const;
};
