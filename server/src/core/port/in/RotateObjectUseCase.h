#pragma once

#include "RotateObjectCommand.h"

class RotateObjectUseCase
{
public:
    virtual ~RotateObjectUseCase() = default;

    virtual void RotateObject(const RotateObjectCommand& command) = 0;
};
