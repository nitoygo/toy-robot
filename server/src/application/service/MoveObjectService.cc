#include "MoveObjectService.h"

#include "ObjectRepository.h"

#include "Movable.h"
#include "Orientation.h"
#include "Map.h"
#include "InvalidCoordinatesException.h"
#include "InvalidActionException.h"

#include <iostream>

Movable& AsMovableObject(BaseObject* object) {
    Movable* movableObject = dynamic_cast<Movable *>(object);
    if (movableObject == nullptr) {
        throw InvalidActionException("Object[" + std::to_string(object->GetId()) + "] is not movable");
    }

    return *movableObject;
}

std::unique_ptr<Map> const&  GetObjectCurrentMap(
    std::unique_ptr<BaseObject> const& object,
    std::shared_ptr<MapRepository> const& mapRepository) {

    std::string currentMapName = object->GetCurrentMapName();
    if (!currentMapName.empty()) {
        return mapRepository->LoadMap(currentMapName);
    }
    else {
        throw InvalidActionException("Object[" + std::to_string(object->GetId()) + "] is not yet placed to a map");
    }
}

Coordinates GetMoveCoordinates(std::unique_ptr<BaseObject> const& object, int units) {
    Coordinates current = object->GetCoordinates();
    Orientation orientation = object->GetOrientation();

    unsigned int x = current.x;
    unsigned int y = current.y;

    if (orientation.GetValue() == Orientation::kNorthFacing) {
        y += units;
    }
    else if (orientation.GetValue() == Orientation::kEastFacing) {
        x += units;
    }
    else if (orientation.GetValue() == Orientation::kSouthFacing && (y - units) >= 0) {
        y -= units;
    }
    else if (orientation.GetValue() == Orientation::kWestFacing && (x - units) >= 0) {
        x -= units;
    }

    return Coordinates(x, y);
}

void MoveObjectService::MoveObject(const MoveObjectCommand& command) {
    std::unique_ptr<BaseObject> const& object = objectRepository_->LoadObject(command.id);
    std::unique_ptr<Map> const& map = GetObjectCurrentMap(object, mapRepository_);

    Coordinates moveCoordinates = GetMoveCoordinates(object, command.units);
    if (map->CoordinatesAvailable(moveCoordinates)) {
        map->TransferObject(command.id, moveCoordinates);

        Movable& moveableObject = AsMovableObject(object.get());
        moveableObject.Move(moveCoordinates);
    }
}
