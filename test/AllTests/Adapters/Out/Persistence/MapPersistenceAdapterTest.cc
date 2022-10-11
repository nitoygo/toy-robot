#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

#include "MapPersistenceAdapter.h"
#include "Map.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(MapPersistenceAdapterTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(MapPersistenceAdapterTest, MapIsPersistedWhenStored)
{
    MapPersistenceAdapter mapRepository = MapPersistenceAdapter();
    std::unique_ptr<Map> table = std::make_unique<Map>("Table", 5, 5);
    mapRepository.StoreMap(table);

    std::unique_ptr<Map> const& persistedMap = mapRepository.LoadMap("Table");
    CHECK_TRUE(persistedMap->GetName() == "Table");
    CHECK_TRUE(persistedMap->GetTotalArea() == 25);
}

TEST(MapPersistenceAdapterTest, ThrowsWhenMapNameNotFound)
{
    MapPersistenceAdapter mapRepository = MapPersistenceAdapter();
    std::unique_ptr<Map> table = std::make_unique<Map>("Table", 5, 5);
    mapRepository.StoreMap(table);

    CHECK_THROWS(std::runtime_error, mapRepository.LoadMap("Chair"));
}
