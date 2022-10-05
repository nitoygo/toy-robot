#pragma once

#include "BaseController.h"
#include "GetObjectPositionUseCase.h"

#include <memory>


class GetObjectPositionController : public BaseController {

public:
    explicit GetObjectPositionController(
        std::unique_ptr<GetObjectPositionUseCase> getObjectPositionService
    ) : getObjectPositionService_(std::move(getObjectPositionService)) {}

    BaseResponse handleRequest(const BaseRequest& request) override;

private:
    std::unique_ptr<GetObjectPositionUseCase> getObjectPositionService_;
};
