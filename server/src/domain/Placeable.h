#pragma once

#include "Coordinates.h"

class Placeable
{
public:
    virtual ~Placeable() = default;

    virtual void Place(
        const std::string& mapName, 
        const Coordinates& coordinates, 
        const Orientation& orientation) = 0;

};
