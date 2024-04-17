//
// Created by USER on 11/4/2024.
//

#include "Hopper.h"

//Hopper::Hopper(unsigned int id, pair<int, int> position, Direction dir, unsigned int size, bool alive, list<pair<int,int>> path, int hopLength)
//        : Bug(id, position, dir, size, alive, path), hopLength(hopLength) {
//    // Additional initialization for Hopper specific members
//}

Hopper::Hopper(int id, pair<int, int> position, Direction dir, int size, int hop_length) {
    this->id = id;
    this->position = position;
    this->dir = dir;
    this->size = size;
    this->hop_length = hop_length;
}

int Hopper::getHopLength() const {
    return hop_length;
}

void Hopper::setHopLength(int hopLength) {
    hop_length = hopLength;
}
//Hopper::Hopper(int id, pair<int, int> position, Direction dir, int size, int hop_length):Bug(id, {x,y}, dir,size,hop_length) {
//
//}

//Hopper::Hopper(int id, pair<int, int> position, Direction dir, int size, int hop_length) {
//
//}


void Hopper::move() {
    if(isWayBlocked()) { //if blocked, then switch direction
        randomDir();
    }
    else if(!isWayBlocked()){ //if not blocked, move
        switch (dir) {
            case Direction::North:
                position.second = position.second + hop_length;
                if(position.second > 10){
                    position.second = 10;
                    path.push_back(getPosition());
                    randomDir();
                }
                else if(position.second <= 0){
                    position.second = 1;
                    path.push_back(getPosition());
                    randomDir();
                }
                path.push_back(getPosition());
                break;
            case Direction::East:
                position.first = position.first + hop_length;
                if(position.first > 10){
                    position.first = 10;
                    path.push_back(getPosition());
                    randomDir();
                }
                else if(position.first <= 0){
                    position.first = 1;
                    path.push_back(getPosition());
                    randomDir();
                }
                path.push_back(getPosition());
                break;
            case Direction::South:
                position.second = position.second - hop_length;
                if(position.second > 10){
                    position.second = 10;
                    path.push_back(getPosition());
                    randomDir();
                }
                else if(position.second <= 0){
                    position.second = 1;
                    path.push_back(getPosition());
                    randomDir();
                }
                path.push_back(getPosition());
                break;
            case Direction::West:
                position.first = position.first - hop_length;
                if(position.first > 10){
                    position.first = 10;
                    path.push_back(getPosition());
                    randomDir();
                }
                else if(position.first <= 0){
                    position.first = 1;
                    path.push_back(getPosition());
                    randomDir();
                }
                path.push_back(getPosition());
                break;
        }
    }
}

bool Hopper::isWayBlocked(){
    int x = this->getPosition().first;
    int y = this->getPosition().second;

    if(this->getDir() == Direction::North || this->getDir() == Direction::South){
        if(y <= 0 || y > 10){
            return true;
        }
    }
    else if(this->getDir() == Direction::East || this->getDir() == Direction::West){
        if(x <= 0 || x > 10){
            return true;
        }
    }
    else{
        return false;
    }
    return false;
}

void Hopper::randomDir() {
    srand(time(nullptr)); // Seed for rand() function
    int randDir = rand() % 4 + 1; // Generate a random number between 1 and 4

    // Update the bug's direction based on the random direction
    switch (randDir) {
        case 1:
            dir = Direction::North;
            setDir(dir);
            break;
        case 2:
            dir = Direction::East;
            setDir(dir);
            break;
        case 3:
            dir = Direction::South;
            setDir(dir);
            break;
        case 4:
            dir = Direction::West;
            setDir(dir);
            break;
    }
}

void Hopper::display_all_bug_details() const {

//    cout << "\n";
    cout << "Hopper, ID: " + to_string(id) + ", Position (" +to_string(position.first) + ", "
            +to_string(position.second) + ")" + ", Size: " + to_string(size) + ", Direction: " +
            Direction_string(dir) + ", Hop Length: " + to_string(hop_length);
    if (alive)
    {
        cout << ", Alive.";
    }
    else
    {
        cout << ", Dead.";
    }
//    cout << "\n";
}


