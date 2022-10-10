#pragma once

#include <string>

class Orientation {

public:
    static const std::string kNorthFacing;
    static const std::string kEastFacing;
    static const std::string kWestFacing;
    static const std::string kSouthFacing;

    Orientation() : value_(kNorthFacing) {}

    explicit Orientation(const std::string& value) : value_(value) {}

    void RotateLeft();

    void RotateRight();

    const std::string& GetValue() const { return value_; }

    bool operator==(const Orientation& other) const {
        return value_ == other.value_;
    }

    bool operator!=(const Orientation& other) const {
        return !(value_ == other.value_);
    }

private:
    std::string value_;
};
