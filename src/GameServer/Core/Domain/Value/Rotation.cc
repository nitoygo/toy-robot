#include "Rotation.h"

Rotation& Rotation::Left() {
    static Rotation rotation(kLeft);
    return rotation;
}

Rotation& Rotation::Right() {
    static Rotation rotation(kRight);
    return rotation;
}
