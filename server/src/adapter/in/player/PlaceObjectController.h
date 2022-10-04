#pragma once

#include "BaseController.h"
#include "PlaceObjectRequest.h"
#include "PlaceObjectUseCase.h"

#include <memory>

class PlaceObjectController : public BaseController {

public:
    explicit PlaceObjectController(std::unique_ptr<PlaceObjectUseCase> &&placeObjectService) : 
        placeObjectService_(std::move(placeObjectService)){}

    BaseResponse handleRequest(const BaseRequest& request) override;

private:
    std::unique_ptr<PlaceObjectUseCase> placeObjectService_;

};
