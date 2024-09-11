#include <ostream>

#include "../include/ConsoleDisplay.h"

ConsoleDisplay::ConsoleDisplay() : roundNumber(0), tableCardsCount(0), playedCardsCount(0), playerCount(0) {
}

void ConsoleDisplay::displayPlayedCards(const CardList& cards) const {
}

void ConsoleDisplay::displayTableCards(const CardList& cards) const {
}

void ConsoleDisplay::displayScores(const std::vector<Player*>& players) const {
}

void ConsoleDisplay::displayGameState() const {
}

void ConsoleDisplay::update(PishtiEvent type, void *payload) {
}


/*
Round: 1, Played Cards: 0, Table Cards: 4
Score: Player: 0, Computer Player: 0
Player throws Ace of Hearts, Turn: ComputerPlayer

***********
* A       *
*         *
*    ♥    *
*         *
*       A *
***********

Cards on the table: 4

*/