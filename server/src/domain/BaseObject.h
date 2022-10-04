#pragma once

#include "Coordinates.h"
#include "Orientation.h"

#include <string>

class BaseObject
{
public:
    BaseObject() = default;
    BaseObject(int id, const Coordinates& coordinates, const Orientation& orientation)
        : id_(id), coordinates_(coordinates), orientation_(orientation) {}

    virtual ~BaseObject() = default;

    int GetId() const { return id_; }

    std::string GetCurrentMapName() const { return currentMapName_; }

    Coordinates GetCoordinates() const { return coordinates_; }

    Orientation GetOrientation() const { return orientation_; }


protected:
    int id_;
    std::string currentMapName_;
    Coordinates coordinates_;
    Orientation orientation_;

};
