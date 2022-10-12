#include <iostream>
#include <string>
#include <memory>
#include "MoveObjectService.h"
#include "InvalidStateException.h"
#include "InvalidActionException.h"
#include "Robot.h"
#include "Coordinates.h"
#include "Orientation.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class ImmovableObject : public BaseObject {
public:
    explicit ImmovableObject(int id) : BaseObject(id) {}
};

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
    inline std::unique_ptr<Map> const& LoadMap(const std::string& name) {
        return map_;
    }

    inline void StoreMap(std::unique_ptr<Map>& map) {
        map_ = std::move(map);
    }

private:
    std::unique_ptr<Map> map_;
};

TEST_GROUP(MoveObjectServiceTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(MoveObjectServiceTest, MoveUpdatesObjectCoordinatesWhenInsideBounds)
{
    Coordinates prevCoordinates(2,3);

    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0));
    robot->SetCoordinates(prevCoordinates);
    robot->SetOrientation(Orientation::South());
    robot->SetCurrentMapName("Table");
    objectRepo->StoreObject(robot);

    std::shared_ptr<MapRepository> mapRepo = std::make_shared<MockMapRepository>();
    std::unique_ptr<Map> table(std::make_unique<Map>("Table", 5, 5));
    mapRepo->StoreMap(table);

    MoveObjectService service(objectRepo, mapRepo);

    MoveObjectCommand command(0, 1);
    service.MoveObject(command);

    std::unique_ptr<BaseObject> const& persistedRobot = objectRepo->LoadObject(0);
    CHECK_TRUE(persistedRobot->GetCoordinates() != prevCoordinates);
}

TEST(MoveObjectServiceTest, MoveDoNotUpdatesObjectCoordinatesWhenOutOfBounds)
{
    Coordinates prevCoordinates(0,0);

    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0));
    robot->SetCoordinates(prevCoordinates);
    robot->SetOrientation(Orientation::West());
    robot->SetCurrentMapName("Table");
    objectRepo->StoreObject(robot);

    std::shared_ptr<MapRepository> mapRepo = std::make_shared<MockMapRepository>();
    std::unique_ptr<Map> table(std::make_unique<Map>("Table", 5, 5));
    mapRepo->StoreMap(table);

    std::unique_ptr<BaseObject> const& persistedRobot = objectRepo->LoadObject(0);

    MoveObjectService service(objectRepo, mapRepo);

    MoveObjectCommand command(0, 1);
    service.MoveObject(command);
    CHECK_TRUE(persistedRobot->GetCoordinates() == prevCoordinates); // assert did not move

    persistedRobot->SetOrientation(Orientation::South());
    service.MoveObject(command);
    CHECK_TRUE(persistedRobot->GetCoordinates() == prevCoordinates); // assert did not move

    prevCoordinates = Coordinates(4,4);
    persistedRobot->SetCoordinates(prevCoordinates);
    persistedRobot->SetOrientation(Orientation::North());
    service.MoveObject(command);
    CHECK_TRUE(persistedRobot->GetCoordinates() == prevCoordinates); // assert did not move

    persistedRobot->SetOrientation(Orientation::East());
    service.MoveObject(command);
    CHECK_TRUE(persistedRobot->GetCoordinates() == prevCoordinates); // assert did not move
}

TEST(MoveObjectServiceTest, ThrowsWhenObjectIsImmovable)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::shared_ptr<MapRepository> mapRepo = std::make_shared<MockMapRepository>();
    MoveObjectService service(objectRepo, mapRepo);

    std::unique_ptr<Map> table(std::make_unique<Map>("Table", 5, 5));
    mapRepo->StoreMap(table);

    std::unique_ptr<BaseObject> immovable(std::make_unique<ImmovableObject>(0));
    immovable->SetCurrentMapName("Table");
    objectRepo->StoreObject(immovable);

    MoveObjectCommand command(0, 1);
    CHECK_THROWS(InvalidActionException, service.MoveObject(command));
}

TEST(MoveObjectServiceTest, ThrowsWhenObjectHasNoCurrentMap)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::shared_ptr<MapRepository> mapRepo = std::make_shared<MockMapRepository>();
    MoveObjectService service(objectRepo, mapRepo);

    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0));
    robot->SetCoordinates(Coordinates(0,0));
    robot->SetOrientation(Orientation::North());
    objectRepo->StoreObject(robot);

    MoveObjectCommand command(0, 1);
    CHECK_THROWS(InvalidStateException, service.MoveObject(command));
}
