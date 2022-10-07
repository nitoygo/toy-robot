#pragma once

#include "BaseException.h"


class InvalidCoordinatesException : public BaseException
{
public:
    InvalidCoordinatesException(const std::string& message) : BaseException(message) {}
};
