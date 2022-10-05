#include "RequestRouter.h"

#include <string>


BaseResponse RequestRouter::Route(BaseRequest request) {
    return controllerMap_[request.GetName()]->handleRequest(request);
}

void RequestRouter::RegisterController(
    const std::string &requestName, 
    std::shared_ptr<BaseController> controller) {

    controllerMap_[requestName] = controller;
}
