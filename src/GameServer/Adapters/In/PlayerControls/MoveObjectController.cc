#include "MoveObjectController.h"

#include "MoveObjectCommand.h"

#include <iostream>
#include <string>


Response MoveObjectController::handleRequest(const Request& request) const {
    MoveObjectCommand command(
        request.GetParameterAsInt("id"),
        request.GetParameterAsInt("units"));

    this->moveObjectService_->MoveObject(command);

    return Response(ResponseCode::kSuccess);
}
