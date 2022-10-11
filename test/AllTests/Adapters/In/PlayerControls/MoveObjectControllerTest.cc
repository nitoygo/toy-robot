#include <iostream>
#include <string>
#include "MoveObjectController.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class MockMoveObjectService: public MoveObjectUseCase {
    inline void MoveObject(const MoveObjectCommand& command) {
        mock().actualCall("MoveObject");
    }
};

TEST_GROUP(MoveObjectControllerTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(MoveObjectControllerTest, MoveObjectServiceExecuted)
{
    MoveObjectController controller(
        std::make_unique<MockMoveObjectService>()
    );

    mock().expectOneCall("MoveObject");

    Request request = Request("MOVE")
        .WithParameter("id", "0")
        .WithParameter("units", "1");

    Response response = controller.handleRequest(request);

    mock().checkExpectations();

    CHECK_TRUE(response.GetCode() == ResponseCode::kSuccess);
}

TEST(MoveObjectControllerTest, ThrowsWhenParameterIsMissing)
{
    MoveObjectController controller(
        std::make_unique<MockMoveObjectService>()
    );

    mock().expectNoCall("MoveObject");

    Request request = Request("MOVE"); // no id or units
    CHECK_THROWS(std::out_of_range, controller.handleRequest(request));

    mock().checkExpectations();
}
