#pragma once

#include "ObjectRepository.h"
#include "Robot.h"

#include <memory>
#include <unordered_map>

class ObjectPersistenceAdapter : public ObjectRepository
{
public:
    std::unique_ptr<BaseObject>& loadObject(int id) override;
    void storeObject(std::unique_ptr<BaseObject>& object) override;
    void updateObject(const std::unique_ptr<BaseObject>& object) override;

private:
    std::unordered_map<int, std::unique_ptr<BaseObject>> sessionMap_;
};
