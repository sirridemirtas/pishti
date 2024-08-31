#include "../include/Player.h"
#include <iostream>

Player::Player(std::string name) : name(std::move(name)) {
}

std::string Player::getName() const {
    return name;
}

void Player::addCard(Card *card) {
    hand.addCard(card);
}

void Player::displayHand() const {
    hand.display();
}

// Collect the pile of cards
void Player::collectPile(CardList &collectedPile) {
    pile += collectedPile; // Append the collected pile to the player's pile
}


/*Player::Player() : score(0) {
}

void Player::addCard(Card *card) {
    hand.addCard(card);
}

// Play a card from the hand
Card *Player::playCard(int index) {
    if (index == -1) {
        std::cout << "Enter the index of the card you want to play: ";
        std::cin >> index;
    }
    Card *playedCard = hand.getCardByIndex(index); // Get the card
    hand.removeCardByIndex(index); // Remove the card from hand
    return playedCard; // Return the played card
}

void Player::displayHand() const {
    hand.display();
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int newScore) {
    score = newScore;
}

void Player::clearHand() {
    hand.clear();
}
*/
