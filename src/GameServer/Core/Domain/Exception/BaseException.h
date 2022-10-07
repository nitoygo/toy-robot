#pragma once

#include <string>


class BaseException : public std::runtime_error
{
public:
    BaseException(const std::string& message) : std::runtime_error(message) {}
};