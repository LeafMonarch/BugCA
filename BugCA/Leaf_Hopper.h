//
// Created by USER on 17/4/2024.
//
#include "Bug.h"

#ifndef BUGCA_LEAF_HOPPER_H
#define BUGCA_LEAF_HOPPER_H


class Leaf_Hopper: public Bug {

public:
    Leaf_Hopper(int id, pair<int, int> position, Direction dir, int size);

    void move() override;
    bool isWayBlocked() override;
    void randomDir();
    void display_all_bug_details() const override;
    void ten_by_ten_constrain();
};


#endif //BUGCA_LEAF_HOPPER_H
