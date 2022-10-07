#pragma once

#include "Coordinates.h"

#include <string>
#include <vector>


class Map
{
public:
    explicit Map(const std::string& name, int width, int height);

    virtual ~Map() = default;

    void PutObject(int objectId, const Coordinates& coordinates);

    void RemoveObjectAt(const Coordinates& oldCoordinates);

    void TransferObject(int objectId, const Coordinates& oldCoordinates, 
        const Coordinates& newCoordinates);

    int GetObjectAt(const Coordinates& coordinates);

    bool CoordinatesAvailable(const Coordinates& coordinates);

    std::string GetName() const { return name_; }

    unsigned int GetWidth() const { return width_; }

    unsigned int GetHeight() const { return height_; }

    unsigned int GetTotalArea() const { return area_.size(); }

private:
    std::string name_;
    unsigned int width_;
    unsigned int height_;
    std::vector<unsigned int> area_;
};
