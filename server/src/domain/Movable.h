#pragma once

#include "Coordinates.h"

class Movable
{
public:
    virtual ~Movable() = default;

    virtual void Move(const Coordinates& coordinates) = 0;

};
