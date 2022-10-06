#include "GetObjectPositionController.h"

#include <iostream>


Response GetObjectPositionController::handleRequest(const Request& request) const {
    int objectId = request.GetParameterAsInt("id");

    QueryResponse queryResponse = this->getObjectPositionService_->GetObjectPosition(objectId);

    Response response(ResponseCode::kSuccess);

    response.AddData("map", queryResponse.GetData("map"));
    response.AddData("x", queryResponse.GetData("x"));
    response.AddData("y", queryResponse.GetData("y"));
    response.AddData("f", queryResponse.GetData("f"));

    return response;
}
