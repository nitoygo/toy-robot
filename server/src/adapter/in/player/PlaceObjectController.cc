#include "PlaceObjectController.h"

#include "PlaceObjectCommand.h"
#include "Coordinates.h"
#include "Orientation.h"

#include <string>


BaseResponse PlaceObjectController::handleRequest(const BaseRequest& request) {
    PlaceObjectCommand command(
        0, "table", Coordinates(1, 2), Orientation(Orientation::kEastFacing)
    );

    this->placeObjectService_->PlaceObject(command);

    BaseResponse response;
    return response;
}
