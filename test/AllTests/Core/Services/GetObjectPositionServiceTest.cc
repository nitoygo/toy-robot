#include <iostream>
#include <string>
#include <memory>
#include "GetObjectPositionService.h"
#include "InvalidStateException.h"
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

TEST_GROUP(GetObjectPositionServiceTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(GetObjectPositionServiceTest, ResponseCorrespondsToObjectState)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    GetObjectPositionService service(objectRepo);

    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0, Coordinates(2,3), Orientation(Orientation::kSouthFacing)));
    robot->SetCurrentMapName("Table");
    objectRepo->StoreObject(robot);

    QueryResponse response = service.GetObjectPosition(0);
    CHECK_TRUE(response.GetData("x") == "2");
    CHECK_TRUE(response.GetData("y") == "3");
    CHECK_TRUE(response.GetData("f") == "SOUTH");
}

TEST(GetObjectPositionServiceTest, ThrowsWhenObjectHasNoCurrentMap)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    GetObjectPositionService service(objectRepo);

    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0, Coordinates(2,3), Orientation(Orientation::kSouthFacing)));
    objectRepo->StoreObject(robot);

    CHECK_THROWS(InvalidStateException, service.GetObjectPosition(0));
}

TEST(GetObjectPositionServiceTest, ThrowsWhenObjectIsNotMovable)
{

    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    GetObjectPositionService service(objectRepo);

    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0, Coordinates(2,3), Orientation(Orientation::kSouthFacing)));
    objectRepo->StoreObject(robot);

    CHECK_THROWS(InvalidStateException, service.GetObjectPosition(0));
}
