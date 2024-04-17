//
// Created by USER on 11/4/2024.
//
#include "Bug.h"

#ifndef BUGCA_HOPPER_H
#define BUGCA_HOPPER_H


class Hopper: public Bug{
    int hop_length;

public:
//    Hopper(unsigned int id = 0, pair<int, int> position = {0,0}, Direction dir = Direction::North, unsigned int size = 10, bool alive = true, list<pair<int,int>> path = {}, int hopLength = 0);
    Hopper(int id, pair<int, int> position, Direction dir, int size, int hop_length);

    void move() override;
    bool isWayBlocked() override;
    void randomDir();
    void display_all_bug_details() const override;

    int getHopLength() const;

    void setHopLength(int hopLength);
};


#endif //BUGCA_HOPPER_H
