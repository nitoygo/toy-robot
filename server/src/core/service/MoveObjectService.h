#pragma once

#include "MoveObjectUseCase.h"
#include "ObjectRepository.h"

#include <memory>


class MoveObjectService : public MoveObjectUseCase
{
public:
    explicit MoveObjectService(std::shared_ptr<ObjectRepository> objectRepository)
        : objectRepository_(objectRepository) {}

    void MoveObject(const MoveObjectCommand& command) override;

private:
    std::shared_ptr<ObjectRepository> objectRepository_;
};
