//
// Created by USER on 21/4/2024.
//

#include "Super_Bug.h"
#include <iomanip> // e.g. setw(2)

Super_Bug::Super_Bug(char bug_type, int id, pair<int, int> position, Direction dir, int size) {
    this-> bug_type = bug_type;
    this->id = id;
    this->position = position;
    this->dir = dir;
    this->size = size;
}


//User Event::KeyPressed to move =============================================================================
void Super_Bug::move() {
    if(isWayBlocked()) { //If Blocked, then switch Direction
        randomDir();
    }
    else if(!isWayBlocked()){ //If not Blocked, Move
        switch (dir) {
            case Direction::North:
                position.second--;
                ten_by_ten_constrain();
                break;
            case Direction::East:
                position.first++;
                ten_by_ten_constrain();
                break;
            case Direction::South:
                position.second++;
                ten_by_ten_constrain();
                break;
            case Direction::West:
                position.first--;
                ten_by_ten_constrain();
                break;
        }
    }
}

//Make sure the Bug does not go out of bound (10x10)
void Super_Bug::ten_by_ten_constrain(){
//    position.second = position.second++;
//    position.first = position.first++;
    if(position.second > 10){
        position.second = 10;
        path.push_back(getPosition());
        randomDir();
    }
    if(position.first > 10){
        position.first = 10;
        path.push_back(getPosition());
        randomDir();
    }
    if(position.second <= 0){
        position.second = 1;
        path.push_back(getPosition());
        randomDir();
    }
    if(position.first <= 0){
        position.first = 1;
        path.push_back(getPosition());
        randomDir();
    }
    path.push_back(getPosition());
}

//Checks if Bugs are blocked by a wall
bool Super_Bug::isWayBlocked(){
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
void Super_Bug::randomDir() {
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

void Super_Bug::display_all_bug_details() const {
    cout << setw(17) << "Super_Bug, ID: " << setw(3) << id << ", Position (" << setw(2) << position.first
         << ", " << setw(2) << position.second << "), Size: " << setw(2) << size << ", Direction: "
         << setw(5) << Direction_string(dir);
    if (alive)
    {
        cout << ", Alive.";
    }
    else
    {
        cout << ", Dead.";
    }
}