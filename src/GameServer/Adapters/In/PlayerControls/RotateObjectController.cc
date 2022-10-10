#include "RotateObjectController.h"

#include "RotateObjectCommand.h"
#include "Rotation.h"


Response RotateObjectController::handleRequest(const Request& request) const {
    int objectId = request.GetParameterAsInt("id");
    Rotation rotation(request.GetName());

    RotateObjectCommand command(objectId, rotation);

    rotateObjectService_->RotateObject(command);

    return Response(ResponseCode::kSuccess);
}
