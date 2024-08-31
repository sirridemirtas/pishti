#include "../include/Card.h"

#include <sstream>

Card::Card(Suit s, Rank r) : suit(s), rank(r) {
}

Suit Card::getSuit() const { return suit; }
Rank Card::getRank() const { return rank; }

std::string Card::suitToString() const {
    static const std::string suitSymbols[] = {
        "♥", "♦", "♣", "♠"
    };
    return suitSymbols[static_cast<int>(suit)];
}

std::string Card::rankToString() const {
    static const std::string rankSymbols[] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };
    return rankSymbols[static_cast<int>(rank)];
}

std::string Card::toString() const {
    std::ostringstream oss;
    oss << rankToString() << ' ' << suitToString();
    return oss.str();
}
