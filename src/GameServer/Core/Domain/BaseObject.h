#pragma once

#include "Coordinates.h"
#include "Orientation.h"

#include <string>

class BaseObject
{
public:
    BaseObject() = default;

    explicit BaseObject(int id) : id_(id) {}

    virtual ~BaseObject() = default;

    int GetId() const { return id_; }
    
    void SetId(int id) { id_ = id; }

    void SetCurrentMapName(const std::string& mapName) { currentMapName_ = mapName; }

    void SetCoordinates(Coordinates coordinates) { coordinates_ = coordinates; }

    void SetOrientation(Orientation orientation) { orientation_ = orientation; }

    std::string GetCurrentMapName() const { return currentMapName_; }

    Coordinates GetCoordinates() const { return coordinates_; }

    Orientation GetOrientation() const { return orientation_; }


protected:
    int id_ = -1;
    std::string currentMapName_;
    Coordinates coordinates_;
    Orientation orientation_;

};
