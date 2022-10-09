#pragma once

#include "BaseObject.h"
#include "Movable.h"
#include "Rotatable.h"
#include "Placeable.h"
#include "Coordinates.h"

class Robot : public BaseObject, 
    public Placeable,
    public Movable,
    public Rotatable
{
public:
    explicit Robot(int id) : BaseObject(id) {}
    explicit Robot(int id, const Coordinates& coordinates, const Orientation& orientation)
        : BaseObject(id, coordinates, orientation) {}

    void Place(
        const std::string& mapName, 
        const Coordinates& coordinates, 
        const Orientation& orientation) override;

    void Move(const Coordinates& coordinates) override;

    void RotateLeft() override;

    void RotateRight() override;


};
