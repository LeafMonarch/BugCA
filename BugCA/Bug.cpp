//
// Created by USER on 11/4/2024.
//

#include "Bug.h"
#include <vector>
#include <cstdlib>
#include <ctime>

Bug::Bug(char bug_type, unsigned int id, pair<int, int>position, Direction dir, unsigned int size, bool alive, list<pair<int,int>> path, unsigned int eaten_by){
    this->bug_type = bug_type;
    this->id = id;
    this->position = position;
    this->dir = dir;
    this->size = size;
    this->alive = alive;
    this->path = path;
    this->eaten_by = eaten_by;
}

unsigned int Bug::getId() const {
    return id;
}

void Bug::setId(unsigned int id) {
    Bug::id = id;
}

const pair<int, int> &Bug::getPosition() const {
    return position;
}

void Bug::setPosition(const pair<int, int> &position) {
    Bug::position = position;
}

Direction Bug::getDir() const {
    return dir;
}

void Bug::setDir(Direction dir) {
    Bug::dir = dir;
}

unsigned int Bug::getSize() const {
    return size;
}

void Bug::setSize(unsigned int size) {
    Bug::size = size;
}

bool Bug::isAlive() const {
    return alive;
}

void Bug::setAlive(bool alive) {
    Bug::alive = alive;
}

const list<pair<int, int>> &Bug::getPath() const {
    return path;
}

void Bug::setPath(const list<pair<int, int>> &path) {
    Bug::path = path;
}

unsigned int Bug::getEatenBy() const {
    return eaten_by;
}

void Bug::setEatenBy(unsigned int eatenBy) {
    eaten_by = eatenBy;
}

char Bug::getBugType() const {
    return bug_type;
}

void Bug::setBugType(char bugType) {
    bug_type = bugType;
}



