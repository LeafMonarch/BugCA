//
// Created by USER on 11/4/2024.
//

#include "Hopper.h"

Hopper::Hopper(unsigned int id, pair<int, int> position, Direction dir, unsigned int size, bool alive, list<pair<int,int>> path, int hopLength)
        : Bug(id, position, dir, size, alive, path), hopLength(hopLength) {
    // Additional initialization for Hopper specific members
}

void Hopper::move() {
    if(isWayBlocked()) {
        srand(time(nullptr)); // Seed for rand() function
        int randDir = rand() % 4 + 1; // Generate a random number between 1 and 4

        // Update the bug's direction based on the random direction
        switch (randDir) {
            case 1:
                dir = Direction::North;
                break;
            case 2:
                dir = Direction::East;
                break;
            case 3:
                dir = Direction::South;
                break;
            case 4:
                dir = Direction::West;
                break;
        }
    }
    else{
        switch (dir) {
            case Direction::North:
                position.second--;
                break;
            case Direction::East:
                position.first++;
                break;
            case Direction::South:
                position.second++;
                break;
            case Direction::West:
                position.first--;
                break;
        }
    }
}

bool Hopper::isWayBlocked(){
    int x = this->getPosition().first;
    int y = this->getPosition().second;

    if(this->getDir() == Direction::North || this->getDir() == Direction::South){
        if(y == 1 || y >= 10){
            return true;
        }
    }
    else if(this->getDir() == Direction::East || this->getDir() == Direction::West){
        if(x == 1 || x >= 10){
            return true;
        }
    }
    else{
        return false;
    }
}