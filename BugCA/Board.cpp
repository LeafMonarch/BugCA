//
// Created by USER on 15/4/2024.
//

#include "Board.h"


Board::Board(const vector<Bug*> &bugs) {
    bug_vector = bugs;
}


//Board::Board(){
//    board.resize(10); //column
//    for(int i=0; i<10; i++){
//        board[i].resize(10);
//    }
//}

Board::Board()
{
    for (int j = 0; j < 10; ++j)
    {
        boardVec10.push_back(vector<Bug*>());
    }
}


void Board::initialize_board(vector<Bug *> &bugVec) {
    bug_vector = bugVec;   //prob
    if(bug_vector.empty()){
        cout << "empty" << endl;
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
}
