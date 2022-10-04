#include "MapPersistenceAdapter.h"

#include <iostream>
#include <memory>
#include <unordered_map>

std::unique_ptr<Map> const& MapPersistenceAdapter::LoadMap(std::string name) {
    auto iterator = repository_.find(name);
    if (iterator == repository_.end())
    {
        throw std::runtime_error("Map[" + name + "] not found");
    }

    return iterator->second;
}

void MapPersistenceAdapter::StoreMap(std::unique_ptr<Map>& map) {
    repository_[map->GetName()] = std::move(map);
}

void MapPersistenceAdapter::UpdateMap(const std::unique_ptr<Map>& map) {

}
