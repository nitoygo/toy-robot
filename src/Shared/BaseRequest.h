#pragma once

#include <string>

class BaseRequest
{
public:
    BaseRequest(std::string name) : name_(name) {}

    std::string GetName() { return name_; }

private:
    std::string name_;
};