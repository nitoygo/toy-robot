#include "GetObjectPositionController.h"

BaseResponse GetObjectPositionController::handleRequest(const BaseRequest& request) {
    QueryResponse queryResponse = this->getObjectPositionService_->GetObjectPosition(0);

    BaseResponse response;
    return response;
}