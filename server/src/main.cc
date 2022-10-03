
#include "MoveObjectController.h"
#include "PlaceObjectController.h"
#include "RotateObjectController.h"

#include "MoveObjectService.h"
#include "PlaceObjectService.h"
#include "RotateObjectService.h"
#include "GetObjectPositionService.h"
#include "ObjectRepository.h"
#include "ObjectPersistenceAdapter.h"
#include "Robot.h"

#include <iostream>
#include <memory>

int main(void)
{
    // initialize persistence
    std::shared_ptr<ObjectRepository> objectRepository(
        std::make_shared<ObjectPersistenceAdapter>()
    );
    // prepare and store test object
    std::unique_ptr<BaseObject> toyRobot(
        std::make_unique<Robot>()
    );
    objectRepository->storeObject(toyRobot);

    // initialize services
    std::unique_ptr<PlaceObjectUseCase> placeObjectService(
        std::make_unique<PlaceObjectService>(objectRepository)
    );
    PlaceObjectController placeObjectController(
        std::move(placeObjectService)
    );

    std::unique_ptr<MoveObjectUseCase> moveObjectService(
        std::make_unique<MoveObjectService>(objectRepository)
    );
    MoveObjectController moveObjectController(
        std::move(moveObjectService)
    );

    std::unique_ptr<RotateObjectUseCase> rotateObjectService(
        std::make_unique<RotateObjectService>(objectRepository)
    );
    RotateObjectController rotateObjectController(
        std::move(rotateObjectService)
    );

    BaseRequest request;
    moveObjectController.handleRequest(request);

    return 0;
}
