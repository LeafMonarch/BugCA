//
// Created by USER on 15/4/2024.
//
#include <iostream>
#include <vector>
#include "Bug.h"
using namespace std;

#ifndef BUGCA_BOARD_H
#define BUGCA_BOARD_H


class Board {
    vector<vector<Bug*>> boardVec10;

    vector<Bug*> bug_vector;

    Board(const vector<Bug *> &bugs);

public:
    Board();
    void initialize_board(vector<Bug*> &bug_vector);
    void display_bugs();
    void tap_board();
    void display_life_history_of_all_bugs();
    void exit();
    void display_all_cells();
    void run_simulation();
};


#endif //BUGCA_BOARD_H
