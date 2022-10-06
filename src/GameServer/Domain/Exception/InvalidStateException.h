#pragma once

#include "BaseException.h"


class InvalidStateException : public BaseException
{
public:
    InvalidStateException(const std::string& message) : BaseException(message) {}
};
