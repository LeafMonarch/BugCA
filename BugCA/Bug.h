//
// Created by USER on 11/4/2024.
//
#include <iostream>
#include <utility>
#include <list>

using namespace std;

#ifndef BUGCA_BUG_H
#define BUGCA_BUG_H

enum class Direction {North, East, South, West};

struct position
{
    int x, y;
};

class Bug {
protected:
    unsigned int id;
    pair<int, int>position;
    Direction dir;
    unsigned int size;
    bool alive;
    list<pair<int,int>> path;
public:
    Bug(unsigned int id = 0, pair<int, int> position = {0,0}, Direction dir = Direction::North, unsigned int size = 10, bool alive = true, list<pair<int,int>> path = {});

    virtual void move() = 0;
    bool isWayBlocked();

    unsigned int getId() const;
    void setId(unsigned int id);
    const pair<int, int> &getPosition() const;
    void setPosition(const pair<int, int> &position);
    Direction getDir() const;
    void setDir(Direction dir);
    unsigned int getSize() const;
    void setSize(unsigned int size);
    bool isAlive() const;
    void setAlive(bool alive);
    const list<pair<int, int>> &getPath() const;
    void setPath(const list<pair<int, int>> &path);
};


#endif //BUGCA_BUG_H
