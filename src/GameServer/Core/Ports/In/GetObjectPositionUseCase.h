#pragma once

#include "QueryResponse.h"

class GetObjectPositionUseCase {

public:
    virtual ~GetObjectPositionUseCase() = default;

    virtual QueryResponse GetObjectPosition(int id) = 0;

};
