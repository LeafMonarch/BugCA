//
// Created by USER on 15/4/2024.
//

#ifndef BUGCA_DIRECTION_H
#define BUGCA_DIRECTION_H

#include <string>
#include <list>
enum class Direction {North = 1, East = 2, South = 3, West = 4};

inline std::string Direction_string(Direction direction) {
    switch (direction) {
        case Direction::North:
            return "NORTH";
        case Direction::East:
            return "EAST";
        case Direction::South:
            return "SOUTH";
        case Direction::West:
            return "WEST";
        default:
            return "No Direction";
    }
}

#endif //BUGCA_DIRECTION_H
