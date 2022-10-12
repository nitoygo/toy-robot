#include "Orientation.h"

Orientation& Orientation::North() {
    static Orientation north(kNorth);
    return north;
}

Orientation& Orientation::East() {
    static Orientation east(kEast);
    return east;
}

Orientation& Orientation::West() {
    static Orientation west(kWest);
    return west;
}

Orientation& Orientation::South() {
    static Orientation south(kSouth);
    return south;
}

void Orientation::RotateLeft() {
    if (value_ == kNorth) {
        value_ = kWest;
    }
    else if (value_ == kWest) {
        value_ = kSouth;
    }
    else if (value_ == kSouth) {
        value_ = kEast;
    }
    else if (value_ == kEast) {
        value_ = kNorth;
    }
}

void Orientation::RotateRight() {
    if (value_ == kNorth) {
        value_ = kEast;
    }
    else if (value_ == kEast) {
        value_ = kSouth;
    }
    else if (value_ == kSouth) {
        value_ = kWest;
    }
    else if (value_ == kWest) {
        value_ = kNorth;
    }
}
