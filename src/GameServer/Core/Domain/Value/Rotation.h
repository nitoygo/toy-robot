#pragma once

#include "InvalidActionException.h"


class Rotation {

public:
    static const std::string kLeftward;
    static const std::string kRightward;

    Rotation() = delete;

    explicit Rotation(const std::string& direction) {
        if (direction != kLeftward && direction != kRightward) {
            throw InvalidActionException("Invalid rotation: " + direction); 
        }
        direction_ = direction;
    }

    const std::string& GetValue() const { return direction_; }

    bool operator==(const Rotation& other) const {
        return direction_ == other.direction_;
    }

    bool operator!=(const Rotation& other) const {
        return !(direction_ == other.direction_);
    }

protected:
    std::string direction_;
};
