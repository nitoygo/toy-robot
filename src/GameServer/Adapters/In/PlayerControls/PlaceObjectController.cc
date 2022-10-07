#include "PlaceObjectController.h"

#include "PlaceObjectCommand.h"
#include "Coordinates.h"
#include "Orientation.h"

#include "InvalidParametersException.h"

#include <string>


Coordinates GetCoordinatesFromRequest(const Request& request) {
    try {
        return Coordinates(
            request.GetParameterAsInt("x"), 
            request.GetParameterAsInt("y"));
    } catch(const std::exception& e) {
        throw InvalidParametersException("Invalid x,y");
    }
}

Orientation GetOrientationFromRequest(const Request& request) {
    try {
        return Orientation(request.GetParameter("f"));
    } catch(const std::exception& e) {
        throw InvalidParametersException("Invalid f direction");
    }
}

Response PlaceObjectController::handleRequest(const Request& request) const {
    PlaceObjectCommand command(
        request.GetParameterAsInt("id"),
        request.GetParameter("map"),
        GetCoordinatesFromRequest(request),
        GetOrientationFromRequest(request)
    );

    this->placeObjectService_->PlaceObject(command);

    return Response(ResponseCode::kSuccess);
}
