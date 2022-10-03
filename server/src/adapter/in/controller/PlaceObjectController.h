#pragma once

#include "BaseController.h"
#include "PlaceObjectRequest.h"
#include "PlaceObjectUseCase.h"

#include <memory>

class PlaceObjectController : public BaseController
{
private:
    std::unique_ptr<PlaceObjectUseCase> placeObjectService_;

public:
    explicit PlaceObjectController(std::unique_ptr<PlaceObjectUseCase> &&placeObjectService) : 
        placeObjectService_(std::move(placeObjectService)){}

    BaseResponse handleRequest(const BaseRequest& request);
};
