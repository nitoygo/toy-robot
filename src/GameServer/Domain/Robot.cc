#include "Robot.h"

#include <iostream>


void Robot::Place(
    const std::string& mapName, 
    const Coordinates& coordinates, 
    const Orientation& orientation) {

    currentMapName_ = mapName;
    coordinates_ = coordinates;
    orientation_ = orientation;
}

void Robot::Move(const Coordinates& coordinates) {
    coordinates_ = coordinates;
}

void Robot::RotateLeft() {
    orientation_.RotateLeft();
}

void Robot::RotateRight() {
    orientation_.RotateRight();
}
