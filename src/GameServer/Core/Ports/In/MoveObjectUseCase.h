#pragma once

#include "MoveObjectCommand.h"

class MoveObjectUseCase {

public:
    virtual ~MoveObjectUseCase() = default;

    virtual void MoveObject(const MoveObjectCommand& command) = 0;

};
