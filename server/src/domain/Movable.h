#pragma once

class Movable
{
public:
    virtual ~Movable() = default;
    virtual void Move(int units) const = 0;
};
