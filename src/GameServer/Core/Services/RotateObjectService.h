#pragma once

#include "RotateObjectUseCase.h"
#include "ObjectRepository.h"

#include <memory>


class RotateObjectService : public RotateObjectUseCase {

public:
    explicit RotateObjectService(std::shared_ptr<ObjectRepository> objectRepository)
        : objectRepository_(objectRepository) {}

    void RotateObject(const RotateObjectCommand& command) override; 

private:
    std::shared_ptr<ObjectRepository> objectRepository_;

};
