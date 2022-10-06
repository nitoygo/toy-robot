#pragma once

#include "BaseController.h"
#include "MoveObjectUseCase.h"

#include <memory>

class MoveObjectController : public BaseController {

public:
    explicit MoveObjectController(std::unique_ptr<MoveObjectUseCase> moveObjectService) 
        : moveObjectService_(std::move(moveObjectService)) {}

    Response handleRequest(const Request& request) const override;

private:
    std::unique_ptr<MoveObjectUseCase> moveObjectService_;

};
