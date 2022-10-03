#pragma once

struct Coordinates
{
    int x;
    int y;

    Coordinates() : x(0), y(0) {}
    Coordinates(int x, int y) : x(x), y(y) {}

    bool operator==(const Coordinates& other) const 
    {
        return x == other.x && y == other.y;
    }

};
