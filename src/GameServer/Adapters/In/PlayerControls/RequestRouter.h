#pragma once

#include "BaseController.h"
#include "Request.h"
#include "Response.h"

#include <memory>
#include <unordered_map>
#include <string>


class RequestRouter {

public:
    Response Route(const Request& requestParams) const;

    void RegisterController(const std::string &requestName, 
        std::shared_ptr<BaseController> controller);

private:
    std::unordered_map<std::string, std::shared_ptr<BaseController>> controllerMap_;

};
