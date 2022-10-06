#include "RequestRouter.h"

#include "InvalidActionException.h"
#include "InvalidParametersException.h"
#include "InvalidObjectIdException.h"

#include <string>
#include <iostream>


Response RequestRouter::Route(const Request& request) const {
    try {
        return controllerMap_.at(request.GetName())->handleRequest(request);
    }
    catch(const InvalidObjectIdException& ioe) {
        return Response(ResponseCode::kInvalidParameterError);
    }
    catch(const InvalidParametersException& ipe) {
        return Response(ResponseCode::kInvalidParameterError);
    }
    catch(const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
        return Response(ResponseCode::kGeneralError);
    }
}

void RequestRouter::RegisterController(
    const std::string &requestName, 
    std::shared_ptr<BaseController> controller) {

    controllerMap_[requestName] = controller;
}
