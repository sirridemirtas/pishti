#pragma once

#include <map>
#include <vector>

#include "DisplayStrategy.h"
#include "Pishti.h"
#include "Player.h"

// This class is responsible for managing the game
class Manager {
    Pishti *game;

    std::map<PishtiEvent, std::vector<PishtiObserver *> > eventSubscribers;

    DisplayStrategy *displayStrategy;

    void subscribeToEvent(PishtiEvent event, PishtiObserver *player);

    void notifyObservers(PishtiEvent event, void *payload);

    void setupTableCards();

    void dealCards();

    void updateScores();

    void playRound();

public:
    Manager();

    void addPlayer(Player *player);

    void removePlayer(Player *player);

    size_t getNumPlayers() const;

    void setGame(Pishti *game);

    void initGame();

    void endGame();

    void resetGame();
};
