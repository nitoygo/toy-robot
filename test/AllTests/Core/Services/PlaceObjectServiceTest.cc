#include <iostream>
#include <string>
#include <memory>
#include "PlaceObjectService.h"
#include "InvalidCoordinatesException.h"
#include "Robot.h"
#include "Coordinates.h"
#include "Orientation.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class MockObjectRepository : public ObjectRepository {
public:
    inline std::unique_ptr<BaseObject> const& LoadObject(int id) {
        return object_;
    }

    inline void StoreObject(std::unique_ptr<BaseObject>& object) {
        object_ = std::move(object);
    }

private:
    std::unique_ptr<BaseObject> object_;
};

class MockMapRepository : public MapRepository {
public:
    inline std::unique_ptr<Map> const& LoadMap(std::string name) {
        return map_;
    }

    inline void StoreMap(std::unique_ptr<Map>& map) {
        map_ = std::move(map);
    }

private:
    std::unique_ptr<Map> map_;
};

TEST_GROUP(PlaceObjectServiceTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(PlaceObjectServiceTest, PlaceObjectUpdatesObjectPositionAttributes)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0));
    objectRepo->StoreObject(robot);

    std::shared_ptr<MapRepository> mapRepo = std::make_shared<MockMapRepository>();
    std::unique_ptr<Map> table(std::make_unique<Map>("Table", 5, 5));
    mapRepo->StoreMap(table);

    PlaceObjectService service(objectRepo, mapRepo);

    PlaceObjectCommand command(0, "Table", Coordinates(4,4), Orientation(Orientation::kSouthFacing));
    service.PlaceObject(command);

    std::unique_ptr<BaseObject> const& persistedRobot = objectRepo->LoadObject(0);
    CHECK_TRUE("Table" == persistedRobot->GetCurrentMapName());
    CHECK_TRUE(Coordinates(4,4) == persistedRobot->GetCoordinates());
    CHECK_TRUE(Orientation(Orientation::kSouthFacing) == persistedRobot->GetOrientation());
}

TEST(PlaceObjectServiceTest, ThrowsWhenPlacedOutOfBounds)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0));
    objectRepo->StoreObject(robot);

    std::shared_ptr<MapRepository> mapRepo = std::make_shared<MockMapRepository>();
    std::unique_ptr<Map> table(std::make_unique<Map>("Table", 5, 5));
    mapRepo->StoreMap(table);

    PlaceObjectService service(objectRepo, mapRepo);

    PlaceObjectCommand command(0, "Table", Coordinates(5,5), Orientation(Orientation::kSouthFacing));
    CHECK_THROWS(InvalidCoordinatesException, service.PlaceObject(command));

    // should stay as defaults
    std::unique_ptr<BaseObject> const& persistedRobot = objectRepo->LoadObject(0);
    CHECK_TRUE("" == persistedRobot->GetCurrentMapName());
    CHECK_TRUE(Coordinates(0,0) == persistedRobot->GetCoordinates());
    CHECK_TRUE(Orientation(Orientation::kNorthFacing) == persistedRobot->GetOrientation());
}
