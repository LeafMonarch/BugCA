//
// Created by USER on 17/4/2024.
//

#include "Leaf_Hopper.h"

Leaf_Hopper::Leaf_Hopper(int id, pair<int, int> position, Direction dir, int size) {
    this->id = id;
    this->position = position;
    this->dir = dir;
    this->size = size;
}

void Leaf_Hopper::move() { //diagonally to the right
    if(isWayBlocked()) { //if blocked, then switch direction
        randomDir();
    }
    else if(!isWayBlocked()){ //if not blocked, move
        switch (dir) {
            case Direction::North:
                position.second++;
                position.first++;
                ten_by_ten_constrain();
                break;
            case Direction::East:
                position.first++;
                position.second--;
                ten_by_ten_constrain();
                break;
            case Direction::South:
                position.second--;
                position.first--;
                ten_by_ten_constrain();
                break;
            case Direction::West:
                position.first--;
                position.second++;
                ten_by_ten_constrain();
                break;
        }
    }
}

void Leaf_Hopper::ten_by_ten_constrain(){
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

bool Leaf_Hopper::isWayBlocked(){
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

void Leaf_Hopper::randomDir() {
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

void Leaf_Hopper::display_all_bug_details() const {

//    cout << "\n";
    cout << "Leaf_Hopper, ID: " + to_string(id) + ", Position (" +to_string(position.first) + ", "
            +to_string(position.second) + ")" + ", Size: " + to_string(size) + ", Direction: " +
            Direction_string(dir);
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