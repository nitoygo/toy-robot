#pragma once

#include "Coordinates.h"
#include "Orientation.h"

#include <string>

struct PlaceObjectCommand {
    int id;
    std::string mapName;
    Coordinates coordinates;
    Orientation orientation;

    PlaceObjectCommand(int id, std::string mapName, Coordinates coordinates, Orientation orientation) 
        : id(id), mapName(mapName), coordinates(coordinates), orientation(orientation) {}

};
