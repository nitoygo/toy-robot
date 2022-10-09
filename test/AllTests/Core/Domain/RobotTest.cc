#include <iostream>
#include "Robot.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(RobotTest)
{
    void setup() _override
    {
    }
    void teardown() _override
    {
        mock().clear();
    }
};

TEST(RobotTest, InitializedAsExpected)
{
    Robot robot(0);
    Coordinates coordinates = robot.GetCoordinates();
    Orientation orientation = robot.GetOrientation();

    CHECK_EQUAL(0, coordinates.x);
    CHECK_EQUAL(0, coordinates.y);
    CHECK_TRUE("NORTH" == orientation.GetValue());
}

TEST(RobotTest, PlaceUpdatesCoordinates)
{
    Robot robot(0);
    robot.Place("Table", Coordinates(1,1), Orientation(Orientation::kSouthFacing));
    Coordinates coordinates = robot.GetCoordinates();
    Orientation orientation = robot.GetOrientation();

    CHECK_EQUAL(1, coordinates.x);
    CHECK_EQUAL(1, coordinates.y);
    CHECK_TRUE("SOUTH" == orientation.GetValue());
}

TEST(RobotTest, MoveUpdatesCoordinates)
{
    Robot robot(0);
    robot.Place("Table", Coordinates(0,0), Orientation(Orientation::kNorthFacing));
    robot.Move(Coordinates(1,1));

    Coordinates coordinates = robot.GetCoordinates();

    CHECK_EQUAL(1, coordinates.x);
    CHECK_EQUAL(1, coordinates.y);
}

TEST(RobotTest, RotateLeftShiftsOrientation)
{
    Robot robot(0);
    Orientation orientation;

    robot.Place("Table", Coordinates(0,0), Orientation(Orientation::kNorthFacing));

    robot.RotateLeft();
    CHECK_TRUE(Orientation::kWestFacing == robot.GetOrientation().GetValue());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::kSouthFacing == robot.GetOrientation().GetValue());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::kEastFacing == robot.GetOrientation().GetValue());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::kNorthFacing == robot.GetOrientation().GetValue());
}

TEST(RobotTest, RotateRightShiftsOrientation)
{
    Robot robot(0);
    Orientation orientation;

    robot.Place("Table", Coordinates(0,0), Orientation(Orientation::kNorthFacing));

    robot.RotateRight();
    CHECK_TRUE(Orientation::kEastFacing == robot.GetOrientation().GetValue());

    robot.RotateRight();
    CHECK_TRUE(Orientation::kSouthFacing == robot.GetOrientation().GetValue());

    robot.RotateRight();
    CHECK_TRUE(Orientation::kWestFacing == robot.GetOrientation().GetValue());

    robot.RotateRight();
    CHECK_TRUE(Orientation::kNorthFacing == robot.GetOrientation().GetValue());
}