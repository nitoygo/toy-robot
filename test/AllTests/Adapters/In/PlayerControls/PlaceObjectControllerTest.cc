#include <iostream>
#include <string>
#include "PlaceObjectController.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class MockPlaceObjectService: public PlaceObjectUseCase {
    inline void PlaceObject(const PlaceObjectCommand& command) {
        mock().actualCall("PlaceObject");
    }
};

TEST_GROUP(PlaceObjectControllerTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(PlaceObjectControllerTest, PlaceObjectServiceExecuted)
{
    PlaceObjectController controller(
        std::make_unique<MockPlaceObjectService>()
    );

    mock().expectOneCall("PlaceObject");

    Request request = Request("PLACE")
        .WithParameter("id", "0")
        .WithParameter("map", "Table")
        .WithParameter("x", "3")
        .WithParameter("y", "3")
        .WithParameter("f", "SOUTH");

    Response response = controller.handleRequest(request);

    mock().checkExpectations();

    CHECK_TRUE(response.GetCode() == ResponseCode::kSuccess);
}

TEST(PlaceObjectControllerTest, ThrowsWhenParameterIsMissing)
{
    PlaceObjectController controller(
        std::make_unique<MockPlaceObjectService>()
    );

    mock().expectNoCall("PlaceObject");

    Request request = Request("Place"); // no id / map / coordinates
    CHECK_THROWS(std::out_of_range, controller.handleRequest(request));

    mock().checkExpectations();
}
