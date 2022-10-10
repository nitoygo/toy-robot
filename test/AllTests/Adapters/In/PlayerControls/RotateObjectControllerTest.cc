#include <iostream>
#include <string>
#include "RotateObjectController.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class MockRotateObjectService: public RotateObjectUseCase {
    inline void RotateObject(const RotateObjectCommand& command) {
        if (command.rotation.GetValue() == Rotation::kLeftward) {
            mock().actualCall("LEFT");
        }
        else if (command.rotation.GetValue() == Rotation::kRightward) {
            mock().actualCall("RIGHT");
        }
    }
};

TEST_GROUP(RotateObjectControllerTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(RotateObjectControllerTest, RotateObjectServiceExecutedWWithLeftRotation)
{
    RotateObjectController controller(
        std::make_unique<MockRotateObjectService>()
    );

    mock().expectOneCall("LEFT");

    Request request = Request("LEFT")
        .WithParameter("id", "0");

    Response response = controller.handleRequest(request);

    mock().checkExpectations();

    CHECK_TRUE(response.GetCode() == ResponseCode::kSuccess);
}

TEST(RotateObjectControllerTest, RotateObjectServiceExecutedWWithRightRotation)
{
    RotateObjectController controller(
        std::make_unique<MockRotateObjectService>()
    );

    mock().expectOneCall("RIGHT");

    Request request = Request("RIGHT")
        .WithParameter("id", "0");

    Response response = controller.handleRequest(request);

    mock().checkExpectations();

    CHECK_TRUE(response.GetCode() == ResponseCode::kSuccess);
}

TEST(RotateObjectControllerTest, ThrowsWhenParameterIsMissing)
{
    RotateObjectController controller(
        std::make_unique<MockRotateObjectService>()
    );

    mock().expectNoCall("LEFT");

    Request request = Request("LEFT"); // no id
    CHECK_THROWS(std::out_of_range, controller.handleRequest(request));

    mock().checkExpectations();
}
