#pragma once

#include "BaseController.h"
#include "RotateObjectRequest.h"
#include "RotateObjectUseCase.h"

#include <memory>

class RotateObjectController : public BaseController {

public:
    explicit RotateObjectController(std::unique_ptr<RotateObjectUseCase> &&rotateObjectService) : 
        rotateObjectService_(std::move(rotateObjectService)){}

    BaseResponse handleRequest(const BaseRequest& request);

private:
    std::unique_ptr<RotateObjectUseCase> rotateObjectService_;

};
