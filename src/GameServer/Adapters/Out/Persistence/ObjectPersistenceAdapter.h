#pragma once

#include "ObjectRepository.h"

#include <memory>
#include <unordered_map>

class ObjectPersistenceAdapter : public ObjectRepository {

public:
    std::unique_ptr<BaseObject> const& LoadObject(int id) override;

    void StoreObject(std::unique_ptr<BaseObject>& object) override;

private:
    std::unordered_map<int, std::unique_ptr<BaseObject>> repository_;

};
