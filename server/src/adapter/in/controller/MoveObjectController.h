#pragma once

#include "BaseController.h"
#include "MoveObjectRequest.h"
#include "MoveObjectUseCase.h"

#include <memory>

class MoveObjectController : public BaseController
{
public:
    explicit MoveObjectController(std::unique_ptr<MoveObjectUseCase> moveObjectService) 
        : moveObjectService_(std::move(moveObjectService)) {}

    BaseResponse handleRequest(const BaseRequest& request);

private:
    std::unique_ptr<MoveObjectUseCase> moveObjectService_;

};
