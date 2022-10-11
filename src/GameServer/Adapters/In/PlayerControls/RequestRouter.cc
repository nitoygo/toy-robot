#include "RequestRouter.h"

#include "InvalidActionException.h"
#include "InvalidParametersException.h"
#include "InvalidObjectIdException.h"

#include <string>
#include <iostream>
#include <stdexcept>


Response RequestRouter::Route(const Request& request) const {
    try {
        return controllerMap_.at(request.GetName())->handleRequest(request);
    }
    catch(const InvalidObjectIdException& ioe) {
        return Response(ResponseCode::kInvalidParameterError)
            .WithData("message", ioe.what());
    }
    catch(const InvalidParametersException& ipe) {
        return Response(ResponseCode::kInvalidParameterError)
            .WithData("message", ipe.what());
    }
    catch(const std::exception& e) {
        return Response(ResponseCode::kGeneralError)
            .WithData("message", e.what());
    }
}

void RequestRouter::RegisterController(
    const std::string &requestName, 
    std::shared_ptr<BaseController> controller) {

    controllerMap_[requestName] = controller;
}
