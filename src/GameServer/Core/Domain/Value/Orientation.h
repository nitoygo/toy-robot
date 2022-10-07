#pragma once

#include <string>

class Orientation {

public:
    static const std::string kNorthFacing;
    static const std::string kEastFacing;
    static const std::string kWestFacing;
    static const std::string kSouthFacing;

    Orientation() = default;
    explicit Orientation(std::string value) : value_(value) {}

    void RotateLeft();

    void RotateRight();

    const std::string& GetValue() { return value_; }

private:
    std::string value_;
};
