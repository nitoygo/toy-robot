#pragma once

#include "MoveObjectUseCase.h"

#include "ObjectRepository.h"
#include "MapRepository.h"

#include <memory>


class MoveObjectService : public MoveObjectUseCase {

public:
    explicit MoveObjectService(
        std::shared_ptr<ObjectRepository> objectRepository,
        std::shared_ptr<MapRepository> mapRepository) : 
        objectRepository_(objectRepository),
        mapRepository_(mapRepository) {}

    void MoveObject(const MoveObjectCommand& command) override;

private:
    std::shared_ptr<ObjectRepository> objectRepository_;
    std::shared_ptr<MapRepository> mapRepository_;

};
