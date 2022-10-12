#pragma once

#include "MapRepository.h"

#include <memory>
#include <string>
#include <unordered_map>


class MapPersistenceAdapter : public MapRepository {

public:
    std::unique_ptr<Map> const& LoadMap(const std::string& name) override;

    void StoreMap(std::unique_ptr<Map>& map) override;

private:
    std::unordered_map<std::string, std::unique_ptr<Map>> repository_;

};
