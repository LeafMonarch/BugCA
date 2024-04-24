//
// Created by USER on 11/4/2024.
//

#include "Hopper.h"
#include <iomanip> // e.g. setw(2)


Hopper::Hopper(char bug_type, int id, pair<int, int> position, Direction dir, int size, int hop_length) {
    this->bug_type = bug_type;
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


void Hopper::move() {
    if(isWayBlocked()) { //If Blocked, then switch Direction
        randomDir();
    }
    else if(!isWayBlocked()){ //If not Blocked, Move
        switch (dir) {
            case Direction::North:
                position.second = position.second - hop_length;
                ten_by_ten_constrain();
                break;
            case Direction::East:
                position.first = position.first + hop_length;
                ten_by_ten_constrain();
                break;
            case Direction::South:
                position.second = position.second + hop_length;
                ten_by_ten_constrain();
                break;
            case Direction::West:
                position.first = position.first - hop_length;
                ten_by_ten_constrain();
                break;
        }
    }
}

//Make sure the Bug does not go out of bound (10x10)
void Hopper::ten_by_ten_constrain(){
    if(position.second > 10){   //Y > 10
        position.second = 10;   //Y = 10
        path.push_back(getPosition());
        randomDir();
    }
    if(position.first > 10){    //X > 10
        position.first = 10;    //X = 10
        path.push_back(getPosition());
        randomDir();
    }
    if(position.second <= 0){   //Y <= 0
        position.second = 1;    //Y = 1
        path.push_back(getPosition());
        randomDir();
    }
    if(position.first <= 0){    //X <= 0
        position.first = 1;     //X = 1
        path.push_back(getPosition());
        randomDir();
    }
    path.push_back(getPosition());
}

//Checks if Bugs are blocked by a wall
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

//If blocked by a wall, turn to a random direction (May face the wall again)
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
    cout << setw(17) << "Hopper, ID: " << setw(3) << id << ", Position (" << setw(2) << position.first
         << ", " << setw(2) << position.second << "), Size: " << setw(2) << size << ", Direction: "
         << setw(5) << Direction_string(dir) << ", Hop Length: " << setw(2) << hop_length;
    if (alive)
    {
        cout << ", Alive.";
    }
    else{
        cout << ", Dead.";
    }
}


