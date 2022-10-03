#pragma once

#include "Rotation.h"

struct RotateObjectCommand
{
    int id;
    Rotation rotation;

    RotateObjectCommand(int id, Rotation rotation)
        : id(id), rotation(rotation) {}
};
