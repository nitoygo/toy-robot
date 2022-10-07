#include "ApplicationContext.h"

#include "RequestRouter.h"
#include "ObjectRepository.h"
#include "MapRepository.h"

#include "BaseObject.h"
#include "Robot.h"
#include "Map.h"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>


#define DEMO_ROBOT_ID                (0)
#define DEMO_ROBOT_ID_STR            "0"
#define DEMO_ROBOT_MOVE_DISTANCE_STR "1"
#define DEMO_MAP_NAME                "Table"
#define DEMO_MAP_WIDTH               (5)
#define DEMO_MAP_HEIGHT              (5)


void RunDemoClient(const ApplicationContext& appContext);


int main()
{
    ApplicationContext appContext;
    appContext.initialize();

    std::shared_ptr<MapRepository> mapRepository = appContext.GetMapRepository();
    std::shared_ptr<ObjectRepository> objectRepository = appContext.GetObjectRepository();

    // prepare and store table as a map with an area of 5x5 units
    std::unique_ptr<Map> table(std::make_unique<Map>(
        DEMO_MAP_NAME, 
        DEMO_MAP_WIDTH, 
        DEMO_MAP_HEIGHT));
    mapRepository->StoreMap(table);

    // prepare and store toy robot object
    std::unique_ptr<BaseObject> toyRobot(std::make_unique<Robot>(
        DEMO_ROBOT_ID));
    objectRepository->StoreObject(toyRobot);

    // start listening for commands
    RunDemoClient(appContext);

    return 0;
}

void RunDemoClient(const ApplicationContext& appContext) {
    std::shared_ptr<RequestRouter> requestRouter = appContext.GetRequestRouter();

    Request request;

    while (1) {
        std::string requestName;
        std::string inputRequest;
        std::getline(std::cin >> std::ws, inputRequest);

        if (inputRequest.starts_with("PLACE")) {
            std::string requestParams, x, y, direction;

            std::stringstream requestStream(inputRequest);
            std::getline(requestStream, requestName, ' ');
            std::getline(requestStream, requestParams, ' ');

            std::stringstream paramStream(requestParams);
            std::getline(paramStream, x, ',');
            std::getline(paramStream, y, ',');
            std::getline(paramStream, direction, ',');

            request = Request("PLACE")
                .WithParameter("id", DEMO_ROBOT_ID_STR)
                .WithParameter("map", DEMO_MAP_NAME)
                .WithParameter("x", x)
                .WithParameter("y", y)
                .WithParameter("f", direction);
        }
        else if (inputRequest.starts_with("MOVE")) {
            request = Request("MOVE")
                .WithParameter("id", DEMO_ROBOT_ID_STR)
                .WithParameter("units", DEMO_ROBOT_MOVE_DISTANCE_STR);
        }
        else if (inputRequest.starts_with("LEFT")) { 
            request = Request("LEFT")
                .WithParameter("id", DEMO_ROBOT_ID_STR);
        }
        else if (inputRequest.starts_with("RIGHT")) { 
            request = Request("RIGHT")
                .WithParameter("id", DEMO_ROBOT_ID_STR);
        }
        else if (inputRequest.starts_with("REPORT")) { 
            request = Request("REPORT")
                .WithParameter("id", DEMO_ROBOT_ID_STR);
        }
        else if (inputRequest.starts_with("QUIT")) {
            break;
        }

        try {
            // send request to input adapter
            Response response = requestRouter->Route(request);

            // handle response
            if (response.GetCode() == ResponseCode::kSuccess) {
                if (request.GetName() == "REPORT") {
                    std::cout << "Output: " <<
                    response.GetData("x") << "," << 
                    response.GetData("y") << "," <<
                    response.GetData("f") << "\n"; 
                }
            }
            else {
                // uncomment and recompile to see error codes
                // std::cout << static_cast<std::underlying_type<ResponseCode>::type>(response.GetCode()) << "\n";
            }
        }
        catch(const std::exception& e) {
            // uncomment and recompile to see exceptions
            // std::cout << "Exception: " << e.what() << "\n";
        }
    }
}
