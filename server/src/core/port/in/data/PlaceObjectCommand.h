#pragma once

#include "Orientation.h"

struct PlaceObjectCommand
{
    int id;
    int x;
    int y;
    Orientation orient;

    PlaceObjectCommand(int id, int x, int y, Orientation orient)
        : id(id), x(x), y(y), orient(orient) {}
};
