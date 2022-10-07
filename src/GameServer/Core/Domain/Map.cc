#include "Map.h"

#include "Coordinates.h"
#include "InvalidCoordinatesException.h"

#include <iostream>

#define EMPTY (-1)

namespace MapHelper {
    unsigned int GetIndexOf(const Map& map, const Coordinates& coordinates) {
        return (coordinates.y * map.GetHeight()) + coordinates.x;
    }

    bool CoordinatesWithinRange(const Map& map, const Coordinates& coordinates) {
        return coordinates.x >= 0 && coordinates.x < map.GetWidth() &&
            coordinates.y >= 0 && coordinates.y < map.GetHeight();
    }
}


Map::Map(std::string name, int width, int height) : 
    name_(name), 
    width_(width), 
    height_(height), 
    area_(width * height, EMPTY) {}


void Map::PutObject(int objectId, const Coordinates& coordinates) {
    try {
        int index = MapHelper::GetIndexOf(*this, coordinates);
        this->area_[index] = objectId;
    }
    catch(const std::exception& e) {
        throw InvalidCoordinatesException(
            "x=" + std::to_string(coordinates.x) + ", y=" + std::to_string(coordinates.y));
    }
}

void Map::RemoveObjectAt(const Coordinates& oldCoordinates) {
    this->PutObject(EMPTY, oldCoordinates);
}

void Map::TransferObject(int objectId, const Coordinates& oldCoordinates, 
    const Coordinates& newCoordinates) {

    this->RemoveObjectAt(oldCoordinates);
    this->PutObject(objectId, newCoordinates);
}

bool Map::CoordinatesAvailable(const Coordinates& coordinates) {
    if (MapHelper::CoordinatesWithinRange(*this, coordinates)) {
        return this->GetObjectAt(coordinates) == EMPTY;
    }

    return false;
}

int Map::GetObjectAt(const Coordinates& coordinates) {
    try {
        int index = MapHelper::GetIndexOf(*this, coordinates);
        return this->area_.at(index);
    }
    catch(std::out_of_range e) {
        throw InvalidCoordinatesException(
            "x=" + std::to_string(coordinates.x) + ", y=" + std::to_string(coordinates.y));
    }
}
