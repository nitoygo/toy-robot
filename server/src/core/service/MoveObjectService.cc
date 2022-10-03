#include "MoveObjectService.h"
#include "ObjectRepository.h"

#include "Movable.h"
#include "Robot.h"

#include <iostream>

const Movable& asMovableObject(const BaseObject* object)
{
    const Movable* movableObject = dynamic_cast<const Movable*>(object);
    if (movableObject == nullptr) 
    {
        throw std::runtime_error("Object[" + std::to_string(object->getId()) + "] is not movable");
    }

    return *movableObject;
}

void MoveObjectService::MoveObject(const MoveObjectCommand& moveCommand)
{
    std::unique_ptr<BaseObject>& object = objectRepository_->loadObject(moveCommand.id);
    const Movable& moveableObject = asMovableObject(object.get());

    moveableObject.Move(moveCommand.units);
}
