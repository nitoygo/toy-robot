#include "Map.h"

#include "Coordinates.h"
#include "InvalidCoordinatesException.h"

#include <iostream>


namespace MapHelper {
    unsigned int GetIndexOf(const Map& map, const Coordinates& coordinates) {
        return (coordinates.y * map.GetHeight()) + coordinates.x;
    }

    bool CoordinatesWithinRange(const Map& map, const Coordinates& coordinates) {
        return coordinates.x >= 0 && coordinates.x < map.GetWidth() &&
            coordinates.y >= 0 && coordinates.y < map.GetHeight();
    }
}

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

void Map::RemoveObject(int objectId) {
    auto iterator = find(this->area_.begin(), this->area_.end(), objectId);
    if (iterator != this->area_.end())
    {
        *(iterator) = 0;
    }
}

void Map::TransferObject(int objectId, const Coordinates& coordinates) {
    this->RemoveObject(objectId);
    this->PutObject(objectId, coordinates);
}

bool Map::CoordinatesAvailable(const Coordinates& coordinates) {
    if (MapHelper::CoordinatesWithinRange(*this, coordinates)) {
        return !this->GetObjectAt(coordinates);
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
