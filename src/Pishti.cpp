#include <iostream>

#include "../include/Pishti.h"

void Pishti::setScore(Player *player, int score) {
    for (auto &p: scores) {
        if (p.first == player) {
            p.second = score;
            break;
        }
    }
}

int Pishti::getScore(Player *player) const {
    for (auto &p: scores) {
        if (p.first == player) {
            return p.second;
        }
    }
    return -1;
}

bool Pishti::isGameOver() const {
    return this->gameOver;
}

uint8_t Pishti::getDeckSize() const {
    return deck.size();
}

Pishti::~Pishti() = default;
