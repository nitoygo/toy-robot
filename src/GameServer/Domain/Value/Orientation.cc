#include "Orientation.h"

const std::string Orientation::kNorthFacing = "NORTH";
const std::string Orientation::kEastFacing = "EAST";
const std::string Orientation::kWestFacing = "WEST";
const std::string Orientation::kSouthFacing = "SOUTH";

void Orientation::RotateLeft() {
    if (value_ == kNorthFacing) {
        value_ = kWestFacing;
    }
    else if (value_ == kWestFacing) {
        value_ = kSouthFacing;
    }
    else if (value_ == kSouthFacing) {
        value_ = kEastFacing;
    }
    else if (value_ == kEastFacing) {
        value_ = kNorthFacing;
    }
}

void Orientation::RotateRight() {
    if (value_ == kNorthFacing) {
        value_ = kEastFacing;
    }
    else if (value_ == kEastFacing) {
        value_ = kSouthFacing;
    }
    else if (value_ == kSouthFacing) {
        value_ = kWestFacing;
    }
    else if (value_ == kWestFacing) {
        value_ = kNorthFacing;
    }
}
