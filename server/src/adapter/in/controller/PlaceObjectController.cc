#include "PlaceObjectController.h"

#include "PlaceObjectCommand.h"
#include "Orientation.h"


BaseResponse PlaceObjectController::handleRequest(const BaseRequest& request)
{
    PlaceObjectCommand command(
        0, 0, 0, kNorthFacing
    );

    this->placeObjectService_->PlaceObject(command);

    BaseResponse response;
    return response;
}
