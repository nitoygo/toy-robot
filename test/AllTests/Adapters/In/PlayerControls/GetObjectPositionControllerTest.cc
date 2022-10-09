#include <iostream>
#include <string>
#include "GetObjectPositionController.h"
#include "Coordinates.h"
#include "Orientation.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class MockGetObjectPositionService: public GetObjectPositionUseCase {
    inline QueryResponse GetObjectPosition(int id) {
        mock().actualCall("GetObjectPosition");

        QueryResponse *returnValue = 
            (QueryResponse *) mock().getData("queryResponse").getObjectPointer();

        return *returnValue;
    }
};

TEST_GROUP(GetObjectPositionControllerTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(GetObjectPositionControllerTest, ResponseCorrespondsToQueryResult)
{
    GetObjectPositionController controller(
        std::make_unique<MockGetObjectPositionService>()
    );

    QueryResponse queryResponse({
        std::make_pair("map", "Table"),
        std::make_pair("x", "2"),
        std::make_pair("y", "4"),
        std::make_pair("f", "NORTH")
    }); 
    mock().setDataObject("queryResponse", "GetObjectPosition", &queryResponse);
    mock().expectOneCall("GetObjectPosition");

    Request request = Request("REPORT").WithParameter("id", "0");
    Response response = controller.handleRequest(request);

    mock().checkExpectations();

    CHECK_TRUE(response.GetData("x") == "2");
    CHECK_TRUE(response.GetData("y") == "4");
    CHECK_TRUE(response.GetData("f") == "NORTH");
}

TEST(GetObjectPositionControllerTest, ThrowsWhenParameterIsIncomplete)
{
    GetObjectPositionController controller(
        std::make_unique<MockGetObjectPositionService>()
    );

    mock().expectNoCall("GetObjectPosition");

    Request request = Request("REPORT"); //.WithParameter("id", "0");
    CHECK_THROWS(std::out_of_range, controller.handleRequest(request));

    mock().checkExpectations();
}

TEST(GetObjectPositionControllerTest, ThrowsWhenResponseDataIsIncomplete)
{
    GetObjectPositionController controller(
        std::make_unique<MockGetObjectPositionService>()
    );

    // no 'f' (facing) value
    QueryResponse queryResponse({
        std::make_pair("map", "Table"),
        std::make_pair("x", "2"),
        std::make_pair("y", "4"),
    }); 
    mock().setDataObject("queryResponse", "GetObjectPosition", &queryResponse);
    mock().expectOneCall("GetObjectPosition");

    Request request = Request("REPORT").WithParameter("id", "0");
    CHECK_THROWS(std::out_of_range, controller.handleRequest(request));

    mock().checkExpectations();
}
