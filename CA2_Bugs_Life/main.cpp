#include <iostream>

using namespace std;

struct 

void menu();

int main() {

    menu();
    return 0;
}

void menu() {
    cout << "\t\t\tMenu Items:" << endl;
    cout << "==================================================================" << endl;
    cout << "||\t" << "1. Initialize Bug Board (load data from file)" << "\t\t||" << endl;
    cout << "||\t" << "2. Display all Bugs" << "\t\t\t\t\t||" << endl;
    cout << "||\t" << "3. Find a Bug (given an id)" << "\t\t\t\t||" << endl;
    cout << "||\t" << "4. Tap the Bug Board (causes move all, then fight/eat)" << "\t||" << endl;
    cout << "||\t" << "5. Display Life History of all Bugs (path taken)" << "\t||" << endl;
    cout << "||\t" << "6. Display all Cells listing their Bugs" << "\t\t\t||" << endl;
    cout << "||\t" << "7. Run simulation (generates a Tap every second)" << "\t||" << endl;
    cout << "||\t" << "8. Exit (write Life History of all Bugs to file)" << "\t||" << endl;
    cout << "==================================================================" << endl;
}