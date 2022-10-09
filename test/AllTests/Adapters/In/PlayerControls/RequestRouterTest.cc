#include <iostream>
#include "RequestRouter.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

class MockController : public BaseController {
    inline Response handleRequest(const Request& request) const {
        mock().actualCall("handleRequest");
        return Response(ResponseCode::kSuccess);
    }
};

TEST_GROUP(RequestRouterTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(RequestRouterTest, RequestRouterCallsExpectedController)
{
    RequestRouter router;
    router.RegisterController("TEST", std::make_shared<MockController>());

    mock().expectOneCall("handleRequest");

    Request request("TEST");
    Response response = router.Route(request);

    mock().checkExpectations();
    CHECK_TRUE(ResponseCode::kSuccess == response.GetCode());
}

TEST(RequestRouterTest, RequestRouterReturnsErrorOnUnknownRequest)
{
    RequestRouter router;

    Request request("UNKNOWN");
    Response response = router.Route(request);

    CHECK_TRUE(ResponseCode::kGeneralError == response.GetCode());
}
