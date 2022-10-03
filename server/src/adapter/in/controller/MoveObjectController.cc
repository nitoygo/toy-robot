#include "MoveObjectController.h"

#include "MoveObjectCommand.h"

#include <iostream>


BaseResponse MoveObjectController::handleRequest(const BaseRequest& request)
{
    MoveObjectCommand command(
        0, 2
    );

    this->moveObjectService_->MoveObject(command);

    BaseResponse response;
    return response;
}
