#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

#include "ObjectPersistenceAdapter.h"
#include "BaseObject.h"
#include "Robot.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(ObjectPersistenceAdapterTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(ObjectPersistenceAdapterTest, MapIsPersistedWhenStored)
{
    ObjectPersistenceAdapter objectRepository = ObjectPersistenceAdapter();
    std::unique_ptr<BaseObject> robot = std::make_unique<Robot>(1);
    objectRepository.StoreObject(robot);

    std::unique_ptr<BaseObject> const& persistedObject = objectRepository.LoadObject(1);
    CHECK_TRUE(persistedObject->GetId() == 1);
}

TEST(ObjectPersistenceAdapterTest, ThrowsWhenMapNameNotFound)
{
    ObjectPersistenceAdapter objectRepository = ObjectPersistenceAdapter();
    std::unique_ptr<BaseObject> robot = std::make_unique<Robot>(1);
    objectRepository.StoreObject(robot);

    CHECK_THROWS(std::runtime_error, objectRepository.LoadObject(999));
}
