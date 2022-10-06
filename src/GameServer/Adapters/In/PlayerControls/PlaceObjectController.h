#pragma once

#include "BaseController.h"
#include "PlaceObjectUseCase.h"

#include <memory>

class PlaceObjectController : public BaseController {

public:
    explicit PlaceObjectController(std::unique_ptr<PlaceObjectUseCase> &&placeObjectService) : 
        placeObjectService_(std::move(placeObjectService)){}

    Response handleRequest(const Request& request) const override;

private:
    std::unique_ptr<PlaceObjectUseCase> placeObjectService_;

};
