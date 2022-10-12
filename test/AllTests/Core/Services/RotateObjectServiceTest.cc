#include <iostream>
#include <string>
#include <memory>
#include "RotateObjectService.h"
#include "InvalidActionException.h"
#include "Robot.h"
#include "Orientation.h"
#include "Rotation.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class NonRotatableObject : public BaseObject {
public:
    explicit NonRotatableObject(int id) : BaseObject(id) {}
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

TEST_GROUP(RotateObjectServiceTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(RotateObjectServiceTest, RotateUpdatesObjectOrientation)
{
    std::shared_ptr<ObjectRepository> objectRepo = std::make_shared<MockObjectRepository>();
    std::unique_ptr<BaseObject> robot(std::make_unique<Robot>(0));
    robot->SetCoordinates(Coordinates(0,0));
    robot->SetOrientation(Orientation::North());
    objectRepo->StoreObject(robot);

    RotateObjectService service(objectRepo);

    std::unique_ptr<BaseObject> const& persistedRobot = objectRepo->LoadObject(0);
    Orientation prevOrientation = persistedRobot->GetOrientation();

    RotateObjectCommand command = RotateObjectCommand(0, Rotation(Rotation::Left()));
    service.RotateObject(command);
    CHECK_TRUE(persistedRobot->GetOrientation() != prevOrientation);

    command = RotateObjectCommand(0, Rotation(Rotation::Right()));
    service.RotateObject(command);
    CHECK_TRUE(persistedRobot->GetOrientation() == prevOrientation);
}

TEST(RotateObjectServiceTest, ThrowsWhenObjectIsNonRotatable)
{
    std::shared_ptr<ObjectRepository> objectRepo(std::make_shared<MockObjectRepository>());
    std::unique_ptr<BaseObject> nonrotating(std::make_unique<NonRotatableObject>(0));
    objectRepo->StoreObject(nonrotating);

    RotateObjectService service(objectRepo);

    std::unique_ptr<BaseObject> const& persistedObject = objectRepo->LoadObject(0);

    RotateObjectCommand command = RotateObjectCommand(0, Rotation(Rotation::Left()));
    CHECK_THROWS(InvalidActionException, service.RotateObject(command));
}
