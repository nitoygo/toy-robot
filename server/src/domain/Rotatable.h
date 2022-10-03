#pragma once

class Rotatable
{
public:
    virtual ~Rotatable() = default;
    virtual void RotateLeft() = 0;
    virtual void RotateRight() = 0;
};
