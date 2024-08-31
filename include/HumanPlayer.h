#pragma once

#include "Player.h"

class HumanPlayer final : public Player {
    void update(PishtiEvent, void *) override;

    Card *playCard() override;

public:
    explicit HumanPlayer(std::string name);
};
