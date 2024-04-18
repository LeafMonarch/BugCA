//
// Created by USER on 11/4/2024.
//

#include "Bug.h"
#include <vector>
#include <cstdlib>
#include <ctime>

Bug::Bug(unsigned int id, pair<int, int>position, Direction dir, unsigned int size, bool alive, list<pair<int,int>> path, unsigned int eaten_by){
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

//  I hashed out get & set for position for now
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
//void Bug::move(){
//////    isWayBlocked();
////    if(isWayBlocked()) {
////        srand(time(nullptr)); // Seed for rand() function
////        int randDir = rand() % 4 + 1; // Generate a random number between 1 and 4
////
////        // Update the bug's direction based on the random direction
////        switch (randDir) {
////            case 1:
////                dir = Direction::North;
////                break;
////            case 2:
////                dir = Direction::East;
////                break;
////            case 3:
////                dir = Direction::South;
////                break;
////            case 4:
////                dir = Direction::West;
////                break;
////        }
////    }
////    else{
////        switch (dir) {
////            case Direction::North:
////                position.second--;
////                break;
////            case Direction::East:
////                position.first++;
////                break;
////            case Direction::South:
////                position.second++;
////                break;
////            case Direction::West:
////                position.first--;
////                break;
////        }
////    }
//
//}
//
//bool Bug::isWayBlocked(){
////    int x = this->getPosition().first;
////    int y = this->getPosition().second;
////
////    if(this->getDir() == Direction::North || this->getDir() == Direction::South){
////        if(y == 1 || y >= 10){
////            return true;
////        }
////    }
////    else if(this->getDir() == Direction::East || this->getDir() == Direction::West){
////        if(x == 1 || x >= 10){
////            return true;
////        }
////    }
////    else{
////        return false;
////    }
//}


