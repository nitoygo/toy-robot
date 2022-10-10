#include "MoveObjectController.h"

#include "MoveObjectCommand.h"

#include <iostream>
#include <string>


Response MoveObjectController::handleRequest(const Request& request) const {
    int objectId = request.GetParameterAsInt("id");
    int moveDistance = request.GetParameterAsInt("units");

    MoveObjectCommand command(objectId, moveDistance);

    this->moveObjectService_->MoveObject(command);

    return Response(ResponseCode::kSuccess);
}
