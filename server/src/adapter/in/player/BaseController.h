#pragma once

#include "BaseRequest.h"
#include "BaseResponse.h"

class BaseController {

public:
    virtual BaseResponse handleRequest(const BaseRequest& request) = 0;

};
