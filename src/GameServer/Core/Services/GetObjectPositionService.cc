#include "GetObjectPositionService.h"

#include "InvalidStateException.h"

#include "ObjectRepository.h"


QueryResponse GetObjectPositionService::GetObjectPosition(int id) {
    std::unique_ptr<BaseObject> const& object = objectRepository_->LoadObject(id);

    std::string currentMapName = object->GetCurrentMapName();
    if (currentMapName.empty()) {
        throw InvalidStateException("Object[" + std::to_string(object->GetId()) + "] is not yet placed to a map");
    }

    Coordinates coordinates = object->GetCoordinates();
    Orientation orientation = object->GetOrientation();

    return QueryResponse({
        std::make_pair("map", currentMapName),
        std::make_pair("x", std::to_string(coordinates.x)),
        std::make_pair("y", std::to_string(coordinates.y)),
        std::make_pair("f", orientation.GetValue())
    });
}
