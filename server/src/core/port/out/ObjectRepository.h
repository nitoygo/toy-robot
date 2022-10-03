#pragma once

#include "BaseObject.h"
#include "Robot.h"

#include <memory>

class ObjectRepository
{
public:
    virtual ~ObjectRepository() = default;

    virtual std::unique_ptr<BaseObject>& loadObject(int id) = 0;
    virtual void storeObject(std::unique_ptr<BaseObject>& object) = 0;
    virtual void updateObject(const std::unique_ptr<BaseObject>& object) = 0;
};
