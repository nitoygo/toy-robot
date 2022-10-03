#pragma once

#include "PlaceObjectCommand.h"

class PlaceObjectUseCase
{
public:
    virtual ~PlaceObjectUseCase() = default;

    virtual void PlaceObject(const PlaceObjectCommand& command) = 0;
};
