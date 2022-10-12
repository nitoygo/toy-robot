#include "ApplicationContext.h"

#include "PlaceObjectController.h"
#include "MoveObjectController.h"
#include "RotateObjectController.h"
#include "GetObjectPositionController.h"

#include "PlaceObjectUseCase.h"
#include "PlaceObjectService.h"
#include "MoveObjectUseCase.h"
#include "MoveObjectService.h"
#include "RotateObjectUseCase.h"
#include "RotateObjectService.h"
#include "GetObjectPositionUseCase.h"
#include "GetObjectPositionService.h"

#include "ObjectRepository.h"
#include "ObjectPersistenceAdapter.h"
#include "MapRepository.h"
#include "MapPersistenceAdapter.h"

#include <iostream>
#include <memory>
#include <mutex>


ApplicationContext &ApplicationContext::instance()
{
    static ApplicationContext instance;
    instance.initialize();

    return instance;
}

void ApplicationContext::initialize() {
    static std::once_flag once;
    std::call_once(once, [this] {
        // initialize request router as entry point of incoming ports / controllers
        requestRouter_ = std::make_shared<RequestRouter>();

        // initialize persistence layers as outgoing ports
        mapRepository_ = std::make_shared<MapPersistenceAdapter>();
        objectRepository_ = std::make_shared<ObjectPersistenceAdapter>();

        // initialize services
        std::unique_ptr<PlaceObjectUseCase> placeObjectService(
            std::make_unique<PlaceObjectService>(objectRepository_, mapRepository_)
        );
        std::unique_ptr<MoveObjectUseCase> moveObjectService(
            std::make_unique<MoveObjectService>(objectRepository_, mapRepository_)
        );
        std::unique_ptr<RotateObjectUseCase> rotateObjectService(
            std::make_unique<RotateObjectService>(objectRepository_)
        );
        std::unique_ptr<GetObjectPositionUseCase> getObjectPositionService(
            std::make_unique<GetObjectPositionService>(objectRepository_)
        );

        // register player action request handlers
        std::shared_ptr<PlaceObjectController> placeObjectController(
            std::make_shared<PlaceObjectController>(std::move(placeObjectService))
        );
        std::shared_ptr<MoveObjectController> moveObjectController(
            std::make_shared<MoveObjectController>(std::move(moveObjectService))
        );
        std::shared_ptr<RotateObjectController> rotateObjectController(
            std::make_shared<RotateObjectController>(std::move(rotateObjectService))
        );
        std::shared_ptr<GetObjectPositionController> getObjectPositionController(
            std::make_shared<GetObjectPositionController>(std::move(getObjectPositionService))
        );

        // register known routes
        requestRouter_->RegisterController("PLACE", placeObjectController);
        requestRouter_->RegisterController("MOVE", moveObjectController);
        requestRouter_->RegisterController("LEFT", rotateObjectController);
        requestRouter_->RegisterController("RIGHT", rotateObjectController);
        requestRouter_->RegisterController("REPORT", getObjectPositionController);
    });
}
