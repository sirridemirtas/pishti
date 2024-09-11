#include <iostream>

#include "../include/CardFactory.h"
#include "../include/CardList.h"
#include "../include/ComputerPlayer.h"
#include "../include/HumanPlayer.h"
#include "../include/Manager.h"
#include "../include/Pishti.h"

int main() {
    Manager manager;
    Pishti game;

    manager.setGame(&game);

    std::string playerName;
    std::cout << "Enter name: ";
    std::cin >> playerName;
    manager.addPlayer(new HumanPlayer(playerName));
    manager.addPlayer(new ComputerPlayer("Computer Player"));

    std::cout << "Number of players: " << static_cast<int>(manager.getNumPlayers()) << std::endl;

    manager.initGame();

    //while (!game.isGameOver()) {
        //manager.playRound();
    //}


    //std::cout << "Deck size: " << game.getDeckSize() << std::endl;

    /*while (game.getDeckSize() /*!manager.isGameOver()#1#) {
        manager.playRound();
    }*/


    /*// Access the singleton instance of CardFactory
    CardFactory &factory = CardFactory::getInstance();

    // Create a CardList and add cards to it
    CardList cardList;
    cardList.addCard(factory.getCard(Suit::HEARTS, Rank::ACE));
    cardList.addCard(factory.getCard(Suit::HEARTS, Rank::ACE)); // This will be the same instance
    cardList.addCard(factory.getCard(Suit::SPADES, Rank::TWO));

    // Display the card list
    std::cout << "CardList: \n" << cardList.toString() << std::endl;

    // Check if the two cards are the same instance
    Card *card1 = factory.getCard(Suit::HEARTS, Rank::ACE);
    Card *card2 = factory.getCard(Suit::HEARTS, Rank::ACE);

    if (card1 == card2) {
        std::cout << "Cards are the same instance." << std::endl;
    } else {
        std::cout << "Cards are different instances." << std::endl;
    }*/

    return 0;
}
