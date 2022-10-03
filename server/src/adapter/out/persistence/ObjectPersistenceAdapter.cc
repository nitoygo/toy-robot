#include "ObjectPersistenceAdapter.h"
#include "ObjectType.h"
#include "Robot.h"

#include <iostream>
#include <memory>
#include <unordered_map>

std::unique_ptr<BaseObject>& ObjectPersistenceAdapter::loadObject(int id)
{
    auto itr = sessionMap_.find(id);
    if (itr == sessionMap_.end())
    {
        throw std::runtime_error("Object[" + std::to_string(id) + "] not found");
    }

    return itr->second;
}

void ObjectPersistenceAdapter::storeObject(std::unique_ptr<BaseObject>& object)
{
    sessionMap_[object->getId()] = std::move(object);
}

void ObjectPersistenceAdapter::updateObject(const std::unique_ptr<BaseObject>& object)
{

}
