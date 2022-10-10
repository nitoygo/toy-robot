#include "RotateObjectController.h"

#include "RotateObjectCommand.h"
#include "Rotation.h"

#include "InvalidActionException.h"


Rotation GetRotationFromRequest(const Request& request) {
    if (request.GetName() == "LEFT") {
        return Rotation::kLeftRotate;
    }
    else if (request.GetName() == "RIGHT") {
        return Rotation::kRightRotate;
    }
    else {
        throw InvalidActionException("Invalid rotation: " + request.GetName());
    }
}


Response RotateObjectController::handleRequest(const Request& request) const {
    int objectId = request.GetParameterAsInt("id");
    Rotation rotateDirection = GetRotationFromRequest(request);

    RotateObjectCommand command(objectId, rotateDirection);

    rotateObjectService_->RotateObject(command);

    return Response(ResponseCode::kSuccess);
}
