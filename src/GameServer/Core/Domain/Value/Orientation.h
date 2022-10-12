#pragma once

#include "InvalidOrientationException.h"

#include <string>
#include <string_view>


class Orientation {

public:
    static constexpr auto kNorth = std::string_view("NORTH");
    static constexpr auto kEast = std::string_view("EAST");
    static constexpr auto kWest = std::string_view("WEST");
    static constexpr auto kSouth = std::string_view("SOUTH");

    explicit Orientation(const std::string_view value) {
        if (value != kNorth && value != kEast && 
            value != kWest && value != kSouth) {
            throw InvalidOrientationException("Invalid orientation");
        }
        value_ = value;
    }

    Orientation() = default;
    ~Orientation() = default;

    static Orientation& North();
    static Orientation& East();
    static Orientation& West();
    static Orientation& South();

    void RotateLeft();

    void RotateRight();

    const std::string GetValue() const { return std::string(value_); }

    bool operator==(const Orientation& other) const {
        return value_ == other.value_;
    }

    bool operator!=(const Orientation& other) const {
        return !(value_ == other.value_);
    }

private:
    std::string_view value_;
};
