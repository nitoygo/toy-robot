#pragma once

#include "InvalidActionException.h"

#include <string>
#include <string_view>

class Rotation {

public:
    static constexpr auto kLeft = std::string_view("LEFT");
    static constexpr auto kRight = std::string_view("RIGHT");

    explicit Rotation(const std::string_view direction) {
        if (direction != kLeft && direction != kRight) {
            throw InvalidActionException("Invalid rotation");
        }
        direction_ = direction;
    }

    Rotation() = delete;
    ~Rotation() = default;

    static Rotation& Left();
    static Rotation& Right();

    const std::string GetValue() const { return std::string(direction_); }

    bool operator==(const Rotation& other) const {
        return direction_ == other.direction_;
    }

    bool operator!=(const Rotation& other) const {
        return !(direction_ == other.direction_);
    }

private:
    std::string_view direction_;
};
