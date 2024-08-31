#pragma once

#include "Player.h"

class ComputerPlayer final : public Player {
    void update(PishtiEvent, void *) override;

    Card *playCard() override;

public:
    explicit ComputerPlayer(std::string name);
};
