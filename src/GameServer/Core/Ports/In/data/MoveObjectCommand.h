#pragma once

struct MoveObjectCommand {
    int id;
    int units;

    MoveObjectCommand(int id, int units) : id(id), units(units) {}
};
