#pragma once

#include "BaseException.h"


class InvalidObjectIdException : public BaseException
{
public:
    InvalidObjectIdException(const std::string& message) : BaseException(message) {}
};
