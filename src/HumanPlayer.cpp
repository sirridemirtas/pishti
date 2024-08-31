#include <utility>
#include <string>
#include <iostream>

#include "../include/HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string name) : Player(std::move(name)) {
}

void HumanPlayer::update(PishtiEvent event, void *payload) {
    std::cout << this->getName() << " notified for " << eventToString(event) << std::endl;

    if (event == PishtiEvent::THROWN_CARD) {
        //std::cout << "Thrown card: " << static_cast<Card *>(payload)->toString() << std::endl;
        return;
    }
    if (event == PishtiEvent::CARDS_COLLECTED) {
        //std::cout << "Cards collected." << std::endl;
        return;
    }
    if (event == PishtiEvent::GAME_OVER) {
        //std::cout << "Game over." << std::endl;
        return;
    }
}

Card *HumanPlayer::playCard() {
    int index = -1;

    while (index < 0 || index >= hand.size()) {
        std::cout << "Enter the index of the card you want to play(" << hand.toString(true) << "): ";
        std::cin >> index;
    }

    Card *playedCard = hand.getCardByIndex(index);
    hand.removeCardByIndex(index);
    std::cout << this->getName() << " played: " << playedCard->toString() << std::endl;
    return playedCard;
}
