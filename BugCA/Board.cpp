//
// Created by USER on 15/4/2024.
//

#include "Board.h"
#include <fstream>
#include <iomanip>
#include <thread> // for std::this_thread::sleep_for
#include <chrono> // for std::chrono::seconds

Board::Board(const vector<Bug*> &bugs) {
    bug_vector = bugs;
}

// 10 rows
Board::Board()
{
    for (int j = 0; j < 10; ++j)
    {
        boardVec10.push_back(vector<Bug*>());
    }
}

//Occupy the 10x10 board with Bugs from bug_vector
void Board::initialize_board(vector<Bug *> &bugVec) {
    bug_vector = bugVec;   //prob
    if(bug_vector.empty()){
        cout << "bug board not initialized" << endl;
    }
}



void Board::display_bugs(){
    if(bug_vector.size()<=0){
        cout << "Empty" << endl;
    }
    for (int i = 0; i < bug_vector.size(); i++)
    {
        cout << "\n";
        bug_vector.at(i) -> display_all_bug_details();
    }
    cout << endl;
}

void Board::tap_board(){
    cout << "Tap" << endl;
    //For every Column
    for(int i = 0; i < bug_vector.size(); i++){
        //For every Row
        for(int j = i + 1; j < bug_vector.size(); j++){
            //If 2 bugs are on the same Cell
            if(bug_vector.at(i) -> getPosition().first == bug_vector.at(j) -> getPosition().first &&
               bug_vector.at(i) -> getPosition().second == bug_vector.at(j) -> getPosition().second){

                //If 2 bugs are alive
                if(bug_vector.at(i) -> isAlive() && bug_vector.at(j) -> isAlive()){
                    //if i > j
                    if(bug_vector.at(i) -> getSize() > bug_vector.at(j) -> getSize()){
                        bug_vector.at(j) ->setAlive(false);
                        unsigned int size_bug = bug_vector.at(i) -> getSize();
                        unsigned int size_bug2 = bug_vector.at(j) -> getSize();
                        bug_vector.at(i) ->setSize(size_bug + size_bug2);
                        cout << "Bug Id " + to_string(bug_vector.at(i)->getId()) + " ate Bug Id " + to_string(bug_vector.at(j)->getId()) << endl;
                        bug_vector.at(j) -> setEatenBy(bug_vector.at(i) -> getId());
                    }
                    //if j > i
                    else if(bug_vector.at(j) -> getSize() > bug_vector.at(i) -> getSize()){
                        bug_vector.at(i) ->setAlive(false);
                        unsigned int size_bug = bug_vector.at(j) -> getSize();
                        unsigned int size_bug2 = bug_vector.at(i) -> getSize();
                        bug_vector.at(j) ->setSize(size_bug + size_bug2);
                        cout << "Bug Id " + to_string(bug_vector.at(j)->getId()) + " ate Bug Id " + to_string(bug_vector.at(i)->getId()) << endl;
                        bug_vector.at(i) -> setEatenBy(bug_vector.at(j) -> getId());
                    }
                    // if both are the same
                    else {
                        // Both bugs are of equal size, select one at random and handle collision resolution
                        if (rand() % 2 == 0) {
                            // Randomly select bug i to survive
                            unsigned int size_bug = bug_vector.at(i)->getSize();
                            unsigned int size_bug2 = bug_vector.at(j) -> getSize();
                            bug_vector.at(i)->setSize(size_bug + size_bug2);
                            bug_vector.at(j)->setAlive(false); // Mark bug j as not alive
                            cout << "Bug Id " + to_string(bug_vector.at(i)->getId()) + " ate Bug Id " + to_string(bug_vector.at(j)->getId()) << endl;
                            bug_vector.at(j) -> setEatenBy(bug_vector.at(i) -> getId());
                        } else {
                            // Randomly select bug j to survive
                            unsigned int size_bug = bug_vector.at(j)->getSize();
                            unsigned int size_bug2 = bug_vector.at(i) -> getSize();
                            bug_vector.at(j)->setSize(size_bug + size_bug2); // Double the size of bug j
                            bug_vector.at(i)->setAlive(false); // Mark bug i as not alive
                            cout << "Bug Id " + to_string(bug_vector.at(j)->getId()) + " ate Bug Id " + to_string(bug_vector.at(i)->getId()) << endl;
                            bug_vector.at(i) -> setEatenBy(bug_vector.at(j) -> getId());
                        }
                    }
                }
            }
        }

        //To exclude and prevent Dead bugs from moving
        if(bug_vector.at(i) -> isAlive()){
            cout << "Before: " << endl;
            bug_vector.at(i) -> display_all_bug_details();
            cout << "\n" << endl;
            bug_vector.at(i) -> move();
            cout << "After: " << endl;
            bug_vector.at(i) -> display_all_bug_details();
            cout << "\n" << endl;
            cout << "\n" << endl;
            cout << "\n" << endl;
        }

    }
}

void Board::display_life_history_of_all_bugs(){
    for(int i = 0; i<bug_vector.size(); i++){
        cout << "Bug ID " << bug_vector.at(i) -> getId() << ": ";
        for (auto it = bug_vector.at(i) -> getPath().begin(); it != bug_vector.at(i) -> getPath().end(); ++it){
            cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << "\n" << endl;
    }
}

void Board::exit() {
    time_t now = time(0); // Get current date/time with respect to system

    struct tm* timeinfo = localtime(&now);

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d_%H-%M-%S", timeinfo); // Formats date and time

    ofstream fout("bugs_life_history_" + string(buffer) + ".out.txt");
    if(fout.is_open()){
        //For every Bug
        for(int i = 0; i<bug_vector.size(); i++){
            string header, path_desc, status, new_line;
            header = "Bug ID " + to_string(bug_vector.at(i)->getId()) + ": ";
            for (auto it = bug_vector.at(i) -> getPath().begin(); it != bug_vector.at(i) -> getPath().end(); ++it) {
                path_desc += "(" + to_string(it->first) + ", " + to_string(it->second) + ") ";
            }
            if(bug_vector.at(i) -> isAlive()){
                status = " Alive ";
            }
            else {
                status = "Has been eaten by Bug Id " + to_string(bug_vector.at(i) -> getEatenBy());
            }
            new_line += "\n";
            fout << setw(10) << left << header << path_desc << status << new_line << endl;
        }
        fout.close();
        cout << "Data has been written to the file." << endl;
    }
    else{
        cout <<"Error opening the file." << endl;
    }

}

void Board::display_all_cells(){
    for(int i = 1; i <= 10; ++i){ //Which is 0 to 9, each row X-axis
        for(int j = 1; j <= 10; ++j){ // Y-axis
            cout << "(" << i << "," << j << "):"; // Outputs cell id
            bool empty = true;

            for(auto & b : bug_vector){
                if(b -> getPosition().first == i && b -> getPosition().second == j){
                    cout << " ["<< b->getId() << "] " << endl;
                    empty = false;
                }
            }
            if (empty == true){
                cout << "--" << endl;
            }
        }
        cout<<"\n"<<endl;
    }
}

void Board::run_simulation() {
    bool last_bug_standing = false;

    do{
        int num_bugs = 0; //Refresh every cycle
        tap_board();

        // Pause the execution for 1 second
        this_thread::sleep_for(chrono::seconds(1));

        for(auto & b: bug_vector){
            if(b->isAlive()){
                num_bugs += 1;
            }
        }
        if(num_bugs <= 1){
            last_bug_standing = true;
        }
    }while(!last_bug_standing);

    cout << "Simulation end." << endl;
    cout << "\n" << endl;

}