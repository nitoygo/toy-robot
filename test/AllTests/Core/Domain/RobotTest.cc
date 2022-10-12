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
    CHECK_TRUE("" == orientation.GetValue());
}

TEST(RobotTest, PlaceUpdatesCoordinates)
{
    Robot robot(0);
    robot.Place("Table", Coordinates(1,1), Orientation::South());
    Coordinates coordinates = robot.GetCoordinates();
    Orientation orientation = robot.GetOrientation();

    CHECK_EQUAL(1, coordinates.x);
    CHECK_EQUAL(1, coordinates.y);
    CHECK_TRUE(Orientation::South() == orientation);
}

TEST(RobotTest, MoveUpdatesCoordinates)
{
    Robot robot(0);
    robot.Place("Table", Coordinates(0,0), Orientation::North());
    robot.Move(Coordinates(1,1));

    Coordinates coordinates = robot.GetCoordinates();

    CHECK_EQUAL(1, coordinates.x);
    CHECK_EQUAL(1, coordinates.y);
}

TEST(RobotTest, RotateLeftShiftsOrientation)
{
    Robot robot(0);
    Orientation orientation;

    robot.Place("Table", Coordinates(0,0), Orientation::North());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::West() == robot.GetOrientation());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::South() == robot.GetOrientation());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::East() == robot.GetOrientation());

    robot.RotateLeft();
    CHECK_TRUE(Orientation::North() == robot.GetOrientation());
}

TEST(RobotTest, RotateRightShiftsOrientation)
{
    Robot robot(0);
    Orientation orientation;

    robot.Place("Table", Coordinates(0,0), Orientation::North());

    robot.RotateRight();
    CHECK_TRUE(Orientation::East() == robot.GetOrientation());

    robot.RotateRight();
    CHECK_TRUE(Orientation::South() == robot.GetOrientation());

    robot.RotateRight();
    CHECK_TRUE(Orientation::West() == robot.GetOrientation());

    robot.RotateRight();
    CHECK_TRUE(Orientation::North() == robot.GetOrientation());
}