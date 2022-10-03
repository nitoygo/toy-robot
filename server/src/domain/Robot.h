#pragma once

#include "BaseObject.h"
#include "Movable.h"
#include "Rotatable.h"
#include "Placeable.h"
#include "Coordinates.h"

class Robot : public BaseObject, 
    public Movable,
    public Rotatable,
    public Placeable
{
public:
    void Move(int units) const override;
    void RotateLeft() override;
    void RotateRight() override;
    void Place(const Coordinates& coordinates) override;
};
