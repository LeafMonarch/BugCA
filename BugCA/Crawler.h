//
// Created by USER on 11/4/2024.
//
#include "Bug.h"


#ifndef BUGCA_CRAWLER_H
#define BUGCA_CRAWLER_H


class Crawler: public Bug{


public:
    Crawler(int id, pair<int, int> position, Direction dir, int size);

    void move() override;
    bool isWayBlocked() override;
    void randomDir();
    void display_all_bug_details() const override;
};


#endif //BUGCA_CRAWLER_H
