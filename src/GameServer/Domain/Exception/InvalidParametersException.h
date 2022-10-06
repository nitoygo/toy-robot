#pragma once

#include "BaseException.h"


class InvalidParametersException : public BaseException
{
public:
    InvalidParametersException(const std::string& message) : BaseException(message) {}
};
