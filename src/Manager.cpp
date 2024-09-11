#include <iostream>

#include "../include/Manager.h"
#include "../include/ConsoleDisplay.h"

Manager::Manager() : game(nullptr), displayStrategy(nullptr) {
    std::cout << "Manager created." << std::endl;
}

void Manager::addPlayer(Player *player) {
    game->players.push_back(player);
    std::cout << "Player added: " << player->getName() << std::endl;
}

void Manager::removePlayer(Player *player) {
    game->players.erase(std::remove(game->players.begin(), game->players.end(), player), game->players.end());
    std::cout << "Player removed: " << player->getName() << std::endl;
}

size_t Manager::getNumPlayers() const {
    return game->players.size();
}

void Manager::subscribeToEvent(PishtiEvent event, PishtiObserver *player) {
    eventSubscribers[event].push_back(player);
    //std::cout << player->getName() << " subscribed to " << eventToString(event) << std::endl;
}

void Manager::setGame(Pishti *gameInstance) {
    this->game = gameInstance;
    std::cout << "Game set." << std::endl;
}

void Manager::initGame() {
    if (game == nullptr) {
        std::cerr << "Game not set." << std::endl;
        return;
    }
    if (getNumPlayers() != 2 && getNumPlayers() != 4) {
        std::cerr << "Invalid number of players. This game is played with 2 or 4 players. Current number of players: "
                << static_cast<int>(getNumPlayers()) << std::endl;
        return;
    }

    // Players subscribe to events
    for (Player *player: game->players) {
        subscribeToEvent(PishtiEvent::THROWN_CARD, player);
        subscribeToEvent(PishtiEvent::CARDS_COLLECTED, player);
    }

    // set display strategy
    displayStrategy = new ConsoleDisplay();

    // displayStrategy subscribes to events
    subscribeToEvent(PishtiEvent::ROUND_START, displayStrategy);


    game->deck.shuffle();
    std::cout << "Deck shuffled." << std::endl;

    setupTableCards();
    std::cout << "Four cards have been placed on the table." << std::endl;

    dealCards();
    std::cout << "Four cards have been dealt to each player." << std::endl;

    for (const Player *player: game->players) {
        std::cout << player->getName() << " has " << static_cast<int>(player->hand.size()) << " cards." << std::endl;
    }
    std::cout << "Deck size: " << static_cast<int>(game->deck.size()) << std::endl;

    notifyObservers(PishtiEvent::GAME_START, nullptr);

    //while (!game->gameOver) {
        playRound();
        //updateScores();
    //}
}

void Manager::notifyObservers(PishtiEvent event, void *payload) {
    for (PishtiObserver *observer: eventSubscribers[event]) {
        observer->update(event, payload);
    }
    //std::cout << "All players notified for " << eventToString(event) << std::endl;
}

void Manager::setupTableCards() {
    // add 4 cards to the table
    for (int i = 0; i < 4; i++) {
        game->pile.addCard(game->deck.removeLastCard());
    }
}

void Manager::dealCards() {
    // deal 4 cards to each player
    for (Player *player: game->players) {
        for (int i = 0; i < 4; i++) {
            player->addCard(game->deck.removeLastCard());
        }
    }
}

void Manager::playRound() {
    game->round++;
    std::cout << "Round " << game->round << " start" <<std::endl;

    // notify players of the round start
    notifyObservers(PishtiEvent::ROUND_START, nullptr);

    // play the round
    while (!game->gameOver) {
        for (Player *player: game->players) {
            if (player->hand.size() == 0 && game->deck.size() > 0) {
                dealCards();
            } else if (player->hand.size() == 0 && game->deck.size() == 0) {
                std::cout << "Deck is empty." << std::endl;
                game->gameOver = true;
                notifyObservers(PishtiEvent::GAME_OVER, nullptr);
                break;
            }

            Card *topCard = game->pile.getTopCard();
            std::cout << "Top card: " << topCard->toString() << std::endl;

            std::cout << player->getName() << "'s turn." << std::endl;
            Card *playedCard = player->playCard();

            game->playedCards.push_back(playedCard);
            std::cout<<"playedCards: " << static_cast<int>(game->playedCards.size()) << std::endl;

            if (playedCard->getRank() == topCard->getRank()) {
                player->collectPile(game->pile);
            } else {
                game->pile.addCard(playedCard);
            }
        }
    }

    std::cout << "Round " << game->round << " end" <<std::endl;
    // notify players of the round end
    notifyObservers(PishtiEvent::ROUND_END, nullptr);
}

void Manager::updateScores() {
    // game->playedCards contains the cards played in the round
    // Check for Pishti
    for (Player *player: game->players) {
        for (Card *card: game->playedCards) {
            if (card->getRank() == Rank::JACK && card->getSuit() == Suit::DIAMONDS) {
                //player->setScore(player->getScore() + 10);
            }
        }
    }
}
