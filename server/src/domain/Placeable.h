#pragma once

#include "Coordinates.h"

class Placeable
{
public:
    virtual ~Placeable() = default;
    virtual void Place(const Coordinates& coordinates) = 0;
};
