//
// Created by USER on 21/4/2024.
//
#include "Bug.h"

#ifndef BUGCA_SUPER_BUG_H
#define BUGCA_SUPER_BUG_H


class Super_Bug: public Bug {

public:
    Super_Bug(char bug_type, int id, pair<int, int> position, Direction dir, int size);

    void move() override;
    bool isWayBlocked() override;
    void randomDir();
    void display_all_bug_details() const override;
    void ten_by_ten_constrain();
};


#endif //BUGCA_SUPER_BUG_H
