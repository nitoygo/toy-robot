#pragma once

#include "Coordinates.h"

#include <string>
#include <vector>


class Map
{
public:
    Map() = default;

    explicit Map(std::string name, int width, int height)
        : name_(name), width_(width), height_(height), area_(width * height) {}

    virtual ~Map() = default;


    void PutObject(int objectId, const Coordinates& coordinates);

    void RemoveObject(int objectId);

    void TransferObject(int objectId, const Coordinates& coordinates);

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
