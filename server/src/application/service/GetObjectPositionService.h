#pragma once

#include "GetObjectPositionUseCase.h"
#include "ObjectRepository.h"

#include <memory>


class GetObjectPositionService : public GetObjectPositionUseCase {

public:
    explicit GetObjectPositionService(std::shared_ptr<ObjectRepository> objectRepository)
        : objectRepository_(objectRepository) {}

    QueryResponse GetObjectPosition(int id) override;

private:
    std::shared_ptr<ObjectRepository> objectRepository_;

};
