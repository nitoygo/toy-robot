
#include "PlaceObjectController.h"
#include "MoveObjectController.h"
#include "RotateObjectController.h"

#include "MoveObjectService.h"
#include "PlaceObjectService.h"
#include "RotateObjectService.h"
#include "GetObjectPositionService.h"
#include "ObjectRepository.h"
#include "ObjectPersistenceAdapter.h"
#include "MapRepository.h"
#include "MapPersistenceAdapter.h"
#include "Robot.h"

#include <iostream>
#include <memory>

int main(void)
{
    // initialize persistence layer
    std::shared_ptr<MapRepository> mapRepository(
        std::make_shared<MapPersistenceAdapter>()
    );
    std::shared_ptr<ObjectRepository> objectRepository(
        std::make_shared<ObjectPersistenceAdapter>()
    );

    // prepare and store table play area
    std::unique_ptr<Map> table(
        std::make_unique<Map>("table", 5, 5)
    );
    mapRepository->StoreMap(table);

    // prepare and store toy robot object
    std::unique_ptr<BaseObject> toyRobot(
        std::make_unique<Robot>()
    );
    objectRepository->StoreObject(toyRobot);

    // initialize services
    std::unique_ptr<PlaceObjectUseCase> placeObjectService(
        std::make_unique<PlaceObjectService>(objectRepository, mapRepository)
    );
    std::unique_ptr<MoveObjectUseCase> moveObjectService(
        std::make_unique<MoveObjectService>(objectRepository, mapRepository)
    );
    std::unique_ptr<RotateObjectUseCase> rotateObjectService(
        std::make_unique<RotateObjectService>(objectRepository)
    );

    // initialize client controllers
    PlaceObjectController placeObjectController(
        std::move(placeObjectService)
    );
    MoveObjectController moveObjectController(
        std::move(moveObjectService)
    );
    RotateObjectController rotateObjectController(
        std::move(rotateObjectService)
    );

    BaseRequest request;
    placeObjectController.handleRequest(request);
    moveObjectController.handleRequest(request);
    moveObjectController.handleRequest(request);
    rotateObjectController.handleRequest(request);
    moveObjectController.handleRequest(request);

    std::unique_ptr<BaseObject> const& toy = objectRepository->LoadObject(0);
    Coordinates coordinates = toy->GetCoordinates();
    std::cout << coordinates.x << "," << coordinates.y << "\n";

    Orientation orientation = toy->GetOrientation();
    std::cout << orientation.GetValue() << "\n";

    return 0;
}
