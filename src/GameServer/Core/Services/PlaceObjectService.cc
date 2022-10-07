#include "PlaceObjectService.h"

#include "MapRepository.h"
#include "ObjectRepository.h"

#include "Map.h"
#include "Placeable.h"
#include "InvalidCoordinatesException.h"
#include "InvalidActionException.h"

#include <iostream>
#include <memory>


Placeable& AsPlaceableObject(BaseObject* object) {
    Placeable* placeableObject = dynamic_cast<Placeable*>(object);
    if (placeableObject == nullptr) {
        throw InvalidActionException("Object[" + std::to_string(object->GetId()) + "] is not placeable");
    }

    return *placeableObject;
}

void PlaceObjectService::PlaceObject(const PlaceObjectCommand& command) {
    std::unique_ptr<BaseObject> const& object = objectRepository_->LoadObject(command.id);
    std::unique_ptr<Map> const& map = mapRepository_->LoadMap(command.mapName);

    if (map->CoordinatesAvailable(command.coordinates)) {
        map->PutObject(object->GetId(), command.coordinates);

        Placeable& placeableObject = AsPlaceableObject(object.get());
        placeableObject.Place(command.mapName, command.coordinates, command.orientation);
    }
    else {
        throw InvalidCoordinatesException(
            "x=" + std::to_string(command.coordinates.x) + ", " +
            "y=" + std::to_string(command.coordinates.y));
    }
}
