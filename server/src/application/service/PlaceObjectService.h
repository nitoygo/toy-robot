#pragma once

#include "PlaceObjectUseCase.h"

#include "ObjectRepository.h"
#include "MapRepository.h"

#include <memory>


class PlaceObjectService : public PlaceObjectUseCase {

public:
    explicit PlaceObjectService(
        std::shared_ptr<ObjectRepository> objectRepository,
        std::shared_ptr<MapRepository> mapRepository) : 
        objectRepository_(objectRepository),
        mapRepository_(mapRepository) {}

    void PlaceObject(const PlaceObjectCommand& command) override;

private:
    std::shared_ptr<ObjectRepository> objectRepository_;
    std::shared_ptr<MapRepository> mapRepository_;

};
