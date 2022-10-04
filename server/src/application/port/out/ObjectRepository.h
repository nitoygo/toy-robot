#pragma once

#include "BaseObject.h"

#include <memory>

class ObjectRepository {

public:
    virtual ~ObjectRepository() = default;

    virtual std::unique_ptr<BaseObject> const& LoadObject(int id) = 0;

    virtual void StoreObject(std::unique_ptr<BaseObject>& object) = 0;

    virtual void UpdateObject(const std::unique_ptr<BaseObject>& object) = 0;

};
