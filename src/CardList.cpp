#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

#include "../include/CardList.h"
#include "../include/Card.h"

void CardList::addCard(Card *card) {
    cards.push_back(card);
}

void CardList::shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(std::time(nullptr)));
}

Card *CardList::getCardByIndex(uint8_t index) const {
    if (index < cards.size()) {
        return cards[index];
    }
    return nullptr;
}

Card *CardList::getTopCard() const {
    if (cards.empty()) {
        return nullptr;
    }
    return cards.back();
}

Card *CardList::removeLastCard() {
    if (cards.empty()) {
        return nullptr;
    }
    Card *card = cards.back();
    cards.pop_back();
    return card;
}

void CardList::removeCard(const Card &card) {
    // remove first instance of card from cards
    //cards.erase(std::remove(cards.begin(), cards.end(), card), cards.end());

    // remove all instances of card from cards
    //cards.erase(std::remove(cards.begin(), cards.end(), card), cards.end());
}

void CardList::removeCardByIndex(uint8_t index) {
    if (index < cards.size()) {
        cards.erase(cards.begin() + index);
    }
}

void CardList::clear() {
    cards.clear();
}

std::string CardList::toString(bool index = false) const {
    std::string str;
    for (int i = 0; i < cards.size(); i++) {
        if (index)
            str += std::to_string(i) + ": ";
        str += cards[i]->toString();
        if (i < cards.size() - 1) {
            str += ", ";
        }
    }
    return str;
}

uint8_t CardList::size() const {
    return cards.size();
}

void CardList::display() const {
    for (uint8_t i = 0; i < cards.size(); i++) {
        std::cout << static_cast<int>(i) << ": " << cards[i]->toString() << std::endl;
    }
}

CardList &CardList::operator+=(const CardList &other) {
    cards.insert(cards.end(), other.cards.begin(), other.cards.end());
    return *this;
}
