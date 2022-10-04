#pragma once

#include <iostream>

struct Coordinates {
    unsigned int x;
    unsigned int y;

    Coordinates() : x(0), y(0) {}
    Coordinates(unsigned int x, unsigned int y) : x(x), y(y) {}

    bool operator==(const Coordinates& other) const {
        return x == other.x && y == other.y;
    }
};
