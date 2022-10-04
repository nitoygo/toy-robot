#pragma once

#include "BaseException.h"


class InvalidActionException : public BaseException
{
public:
    InvalidActionException(const std::string& message) : BaseException(message) {}
};
