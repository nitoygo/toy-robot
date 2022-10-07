#pragma once

#include "RequestRouter.h"
#include "ObjectRepository.h"
#include "MapRepository.h"

#include <memory>

class ApplicationContext {

public:
    void initialize();

    std::shared_ptr<RequestRouter> GetRequestRouter() const {
        return requestRouter_;
    }

    std::shared_ptr<ObjectRepository> GetObjectRepository() const {
        return objectRepository_;
    }

    std::shared_ptr<MapRepository> GetMapRepository() const {
        return mapRepository_;
    }

private:
    std::shared_ptr<RequestRouter> requestRouter_;
    std::shared_ptr<ObjectRepository> objectRepository_;
    std::shared_ptr<MapRepository> mapRepository_;

};
