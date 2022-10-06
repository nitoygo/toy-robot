#include "RequestRouter.h"

#include "PlaceObjectController.h"
#include "MoveObjectController.h"
#include "RotateObjectController.h"
#include "GetObjectPositionController.h"

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
    std::unique_ptr<GetObjectPositionUseCase> getObjectPositionService(
        std::make_unique<GetObjectPositionService>(objectRepository)
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

    RequestRouter router;
    router.RegisterController("PLACE", placeObjectController);
    router.RegisterController("MOVE", moveObjectController);
    router.RegisterController("LEFT", rotateObjectController);
    router.RegisterController("RIGHT", rotateObjectController);
    router.RegisterController("REPORT", getObjectPositionController);

    Request placeRequest("PLACE");
    placeRequest.AddParameter("id", "0");
    placeRequest.AddParameter("map", "table");
    placeRequest.AddParameter("x", "0");
    placeRequest.AddParameter("y", "0");
    placeRequest.AddParameter("f", "NORTH");

    Request moveRequest("MOVE");
    moveRequest.AddParameter("id", "0");
    moveRequest.AddParameter("units", "1");

    Request leftRequest("LEFT");
    leftRequest.AddParameter("id", "0");

    Request rightRequest("RIGHT");
    rightRequest.AddParameter("id", "0");

    Request reportRequest("REPORT");
    reportRequest.AddParameter("id", "0");

    Response response;
    response = router.Route(placeRequest);
    response = router.Route(moveRequest);
    response = router.Route(moveRequest);
    response = router.Route(leftRequest);
    response = router.Route(moveRequest);
    response = router.Route(reportRequest);

    std::cout << response.GetData("map") << "[" <<
        response.GetData("x") << "," << 
        response.GetData("y") << "], " <<
        response.GetData("f") << "\n";

    return 0;
}
