//
// Created by USER on 11/4/2024.
//
#include "Bug.h"

#ifndef BUGCA_HOPPER_H
#define BUGCA_HOPPER_H


class Hopper: protected Bug{
private:
    int hopLength;

public:
    Hopper(unsigned int id = 0, pair<int, int> position = {0,0}, Direction dir = Direction::North, unsigned int size = 10, bool alive = true, list<pair<int,int>> path = {}, int hopLength = 0);

    void move();
    bool isWayBlocked();
};


#endif //BUGCA_HOPPER_H
