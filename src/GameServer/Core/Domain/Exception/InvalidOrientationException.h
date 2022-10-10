#pragma once

#include "BaseException.h"


class InvalidOrientationException : public BaseException
{
public:
    InvalidOrientationException(const std::string& message) : BaseException(message) {}
};
