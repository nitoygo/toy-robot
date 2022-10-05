#pragma once

#include "BaseRequest.h"
#include "BaseResponse.h"

class BaseController {

public:
    virtual ~BaseController() = default;
    virtual BaseResponse handleRequest(const BaseRequest& request) = 0;

};
