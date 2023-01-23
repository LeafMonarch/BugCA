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
    void move();
    bool isWayBlocked();
};


#endif //BUGCA_HOPPER_H
