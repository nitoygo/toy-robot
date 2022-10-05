#pragma once

#include "Map.h"

#include <memory>
#include <string>

class MapRepository {

public:
    virtual ~MapRepository() = default;

    virtual std::unique_ptr<Map> const& LoadMap(std::string name) = 0;

    virtual void StoreMap(std::unique_ptr<Map>& map) = 0;

};
