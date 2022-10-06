#pragma once

#include "BaseController.h"
#include "RotateObjectUseCase.h"

#include <memory>

class RotateObjectController : public BaseController {

public:
    explicit RotateObjectController(std::unique_ptr<RotateObjectUseCase> &&rotateObjectService) : 
        rotateObjectService_(std::move(rotateObjectService)){}

    Response handleRequest(const Request& request) const ;

private:
    std::unique_ptr<RotateObjectUseCase> rotateObjectService_;

};
