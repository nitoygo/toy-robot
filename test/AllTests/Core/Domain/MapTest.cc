#include <iostream>
#include "Map.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(MapTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(MapTest, InitializedAsEmpty)
{
    int width = 5;
    int height = 5;
    bool isEmpty = true;

    Map map("Table", width, width);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            isEmpty = isEmpty && map.CoordinatesAvailable(Coordinates(x, y));
        }
    }

    CHECK_TRUE(isEmpty);
}

TEST(MapTest, PuttingObjectMakesCoordinatesUnavailable)
{
    int width = 5;
    int height = 5;

    Map map("Table", width, width);
    map.PutObject(0, Coordinates(0,0));

    CHECK_FALSE(map.CoordinatesAvailable(Coordinates(0,0)));
}

TEST(MapTest, RemovingObjectMakesCoordinatesAvailable)
{
    int width = 5;
    int height = 5;

    Map map("Table", width, width);
    map.PutObject(1, Coordinates(0,0));
    CHECK_FALSE(map.CoordinatesAvailable(Coordinates(0,0)));
    CHECK_EQUAL(1, map.GetObjectAt(Coordinates(0,0)));

    map.RemoveObjectAt(Coordinates(0,0));
    CHECK_TRUE(map.CoordinatesAvailable(Coordinates(0,0)));
    CHECK_EQUAL(-1, map.GetObjectAt(Coordinates(0,0)));
}

TEST(MapTest, TransferringObjectMovesTheTakenCoordinates)
{
    int width = 5;
    int height = 5;

    Map map("Table", width, width);
    map.PutObject(1, Coordinates(0,0));
    map.TransferObject(1, Coordinates(0,0), Coordinates(4,4));

    CHECK_TRUE(map.CoordinatesAvailable(Coordinates(0,0)));
    CHECK_EQUAL(-1, map.GetObjectAt(Coordinates(0,0)));

    CHECK_FALSE(map.CoordinatesAvailable(Coordinates(4,4)));
    CHECK_EQUAL(1, map.GetObjectAt(Coordinates(4,4)));
}
