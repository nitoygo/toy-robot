#pragma once

#include "BaseController.h"
#include "BaseRequest.h"
#include "BaseResponse.h"

#include <memory>
#include <unordered_map>
#include <string>


class RequestRouter {

public:
    BaseResponse Route(BaseRequest requestParams);

    void RegisterController(const std::string &requestName, 
        std::shared_ptr<BaseController> controller);

private:
    std::unordered_map<std::string, std::shared_ptr<BaseController>> controllerMap_;

};
