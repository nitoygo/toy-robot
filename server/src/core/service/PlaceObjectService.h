#pragma once

#include "PlaceObjectUseCase.h"
#include "ObjectRepository.h"

#include <memory>


class PlaceObjectService : public PlaceObjectUseCase
{
public:
    explicit PlaceObjectService(std::shared_ptr<ObjectRepository> objectRepository)
        : objectRepository_(objectRepository) {}

    void PlaceObject(const PlaceObjectCommand& command) override;

private:
    std::shared_ptr<ObjectRepository> objectRepository_;
};
