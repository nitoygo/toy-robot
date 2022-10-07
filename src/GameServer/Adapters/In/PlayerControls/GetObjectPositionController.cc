#include "GetObjectPositionController.h"

#include <iostream>


Response GetObjectPositionController::handleRequest(const Request& request) const {
    int objectId = request.GetParameterAsInt("id");

    QueryResponse queryResponse = this->getObjectPositionService_->GetObjectPosition(objectId);

    Response response = Response(ResponseCode::kSuccess)
        .WithData("map", queryResponse.GetData("map"))
        .WithData("x", queryResponse.GetData("x"))
        .WithData("y", queryResponse.GetData("y"))
        .WithData("f", queryResponse.GetData("f"));

    return response;
}
