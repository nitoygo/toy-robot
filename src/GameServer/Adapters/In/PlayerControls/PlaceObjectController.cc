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
    int objectId = request.GetParameterAsInt("id");
    std::string mapName = request.GetParameter("map");
    Coordinates coordinates = GetCoordinatesFromRequest(request);
    Orientation orientation = GetOrientationFromRequest(request);

    PlaceObjectCommand command(objectId, mapName, coordinates, orientation);

    this->placeObjectService_->PlaceObject(command);

    return Response(ResponseCode::kSuccess);
}
