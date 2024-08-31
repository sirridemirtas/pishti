#include <iostream>

#include "../include/ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(std::string name) : Player(std::move(name)) {
}

void ComputerPlayer::update(PishtiEvent event, void *payload) {
    std::cout << this->getName() << " notified for " << eventToString(event) << std::endl;
}

Card *ComputerPlayer::playCard() {
    int index = 0;
    Card *playedCard = hand.getCardByIndex(index); // Get the card
    hand.removeCardByIndex(index); // Remove the card from hand
    std::cout << this->getName() << " played: " << playedCard->toString() << std::endl;
    return playedCard; // Return the played card
}
