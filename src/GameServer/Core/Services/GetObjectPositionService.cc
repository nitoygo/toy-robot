#include "GetObjectPositionService.h"

#include "ObjectRepository.h"


QueryResponse GetObjectPositionService::GetObjectPosition(int id) {
    std::unique_ptr<BaseObject> const& object = objectRepository_->LoadObject(id);

    Coordinates coordinates = object->GetCoordinates();
    std::cout << coordinates.x << "," << coordinates.y << "\n";

    Orientation orientation = object->GetOrientation();
    std::cout << orientation.GetValue() << "\n";

    QueryResponse response;
    return response;
}
