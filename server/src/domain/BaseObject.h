#pragma once

#include "Coordinates.h"
#include "Orientation.h"

class BaseObject
{
public:
    BaseObject() = default;

    BaseObject(int id, const Coordinates& coordinates, const Orientation& orientation)
        : id_(id), coordinates_(coordinates), orientation_(orientation) {}

    virtual ~BaseObject() = default;

    int getId() const { return id_; }

    Coordinates getCoordinates() const { return coordinates_; }

    Orientation getOrientation() const { return orientation_; }


protected:
    int id_;
    Coordinates coordinates_;
    Orientation orientation_;

};
