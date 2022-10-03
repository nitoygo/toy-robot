#include "Robot.h"

#include <iostream>

void Robot::Move(int units) const
{
    std::cout << "Robot[" + std::to_string(this->id_) + "] moved by: " + std::to_string(units) << std::endl;
}

void Robot::RotateLeft()
{
    std::cout << "Robot[" + std::to_string(this->id_) + "] rotated left" << std::endl;
}

void Robot::RotateRight()
{
    std::cout << "Robot[" + std::to_string(this->id_) + "] rotated right" << std::endl;
}

void Robot::Place(const Coordinates& coordinates)
{
    std::cout << "Robot[" + std::to_string(this->id_) + "] placed" << std::endl;
}
