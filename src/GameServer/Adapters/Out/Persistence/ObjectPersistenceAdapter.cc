#include "ObjectPersistenceAdapter.h"
#include "ObjectType.h"

#include "InvalidObjectIdException.h"

#include <iostream>
#include <memory>
#include <unordered_map>


std::unique_ptr<BaseObject> const& ObjectPersistenceAdapter::LoadObject(int id) {
    auto iterator = repository_.find(id);
    if (iterator == repository_.end()) {
        throw InvalidObjectIdException("Object[" + std::to_string(id) + "] not found");
    }

    return iterator->second;
}

void ObjectPersistenceAdapter::StoreObject(std::unique_ptr<BaseObject>& object) {
    repository_[object->GetId()] = std::move(object);
}
