#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include <vector>
using namespace std;
using namespace sf;


int main() {
    vector<Bug*> bug_vector;

    cout << "Menu Items" << endl;
    cout << "1. Initialize Bug Board (load data from file)" << endl;
    cout << "2. Display all Bugs" << endl;
    cout << "3. Find a Bug (given an id)" << endl;
    cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
    cout << "5. Display Life History of all Bugs (path taken)" << endl;
    cout << "6. Display all Cells listing their Bugs" << endl;
    cout << "7. Run simulation (generates a Tap every second)" << endl;
    cout << "8. Exit (write Life History of all Bugs to file)" << endl;



    return 0;
}

