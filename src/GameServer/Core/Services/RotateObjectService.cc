#include "RotateObjectService.h"

#include "ObjectRepository.h"

#include "Rotatable.h"
#include "Rotation.h"
#include "InvalidActionException.h"

Rotatable& AsRotatableObject(BaseObject* object) {
    Rotatable* rotatableObject = dynamic_cast<Rotatable *>(object);
    if (rotatableObject == nullptr) {
        throw InvalidActionException("Object[" + std::to_string(object->GetId()) + "] is not rotatable");
    }

    return *rotatableObject;
}

void RotateObjectService::RotateObject(const RotateObjectCommand& command) {
    std::unique_ptr<BaseObject> const& object = objectRepository_->LoadObject(command.id);
    Rotatable& rotatableObject = AsRotatableObject(object.get());

    if (command.rotation == kLeftRotate) {
        rotatableObject.RotateLeft();
    }
    else if (command.rotation == kRightRotate) {
        rotatableObject.RotateRight();
    }
}
