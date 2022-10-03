#include "RotateObjectController.h"

#include "RotateObjectCommand.h"
#include "Rotation.h"

BaseResponse RotateObjectController::handleRequest(const BaseRequest& request)
{
    RotateObjectCommand command(
        0,
        kLeftRotate
    );
    rotateObjectService_->RotateObject(command);

    BaseResponse response;
    return response;
}
