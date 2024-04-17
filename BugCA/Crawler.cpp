//
// Created by USER on 11/4/2024.
//

#include "Crawler.h"

//Crawler::Crawler(int id, pair<int, int> position, Direction dir, int size):Bug(id, {x,y}, dir,size){
//
//}

Crawler::Crawler(int id, pair<int, int> position, Direction dir, int size){
    this->id = id;
    this->position = position;
    this->dir = dir;
    this->size = size;
}


void Crawler::move() {
    if(isWayBlocked()) { //if blocked, then switch direction
        randomDir();
    }
    else if(!isWayBlocked()){ //if not blocked, move
        switch (dir) {
            case Direction::North:
                position.second++;
                if(position.second > 10){
                    position.second = 10;
                    path.push_back(getPosition());
                    randomDir();
                }
                else if(position.second <=0){
                    position.second = 1;
                    path.push_back(getPosition());
                    randomDir();
                }
                path.push_back(getPosition());
                break;
            case Direction::East:
                position.first++;
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
                position.second--;
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
                position.first--;
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

bool Crawler::isWayBlocked(){
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

void Crawler::randomDir() {
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

void Crawler::display_all_bug_details() const {

//        cout << "\n";
        cout << "Crawler, ID: " + to_string(id) + ", Position (" +to_string(position.first) + ", "
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

//void Crawler::one_or_more_bug() {
//    if(alive){
//        getPosition() ;
//
//        for(int i = 0; i < bug.vector)
//    }
//}
