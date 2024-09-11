#pragma once

#include <map>
#include <vector>

#include "Pishti.h"
#include "Player.h"

// This class is responsible for managing the game
class Manager {
    Pishti *game;

    std::map<PishtiEvent, std::vector<Player *> > eventSubscribers;

    void subscribeToEvent(PishtiEvent event, Player *player);

    void notifyPlayers(PishtiEvent event, void *payload);

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
