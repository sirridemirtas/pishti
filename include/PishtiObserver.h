#pragma once

#include "PishtiEvent.h"

class PishtiObserver {
public:
    virtual ~PishtiObserver() = default;

    virtual void update(PishtiEvent type, void *payload) = 0;
};
