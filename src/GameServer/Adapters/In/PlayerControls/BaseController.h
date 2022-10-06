#pragma once

#include "Request.h"
#include "Response.h"

class BaseController {

public:
    virtual ~BaseController() = default;

    virtual Response handleRequest(const Request& request) const = 0;

};
