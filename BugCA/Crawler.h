//
// Created by USER on 11/4/2024.
//
#include "Bug.h"


#ifndef BUGCA_CRAWLER_H
#define BUGCA_CRAWLER_H


class Crawler: protected  Bug{


public:
    void move();
    bool isWayBlocked();
};


#endif //BUGCA_CRAWLER_H
