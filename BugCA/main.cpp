#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
using namespace sf;

void loadDataFromFile();

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

    cout << "test" << endl;

    return 0;
}

void loadDataFromFile(){
    vector<Bug*> bug_vector;
    ifstream fin("bugs.txt");
    if(fin){
        while(!fin.eof()){ // do I need eof?
            string input_line; //declare
            while(getline(fin, input_line)){
                stringstream string_stream1(input_line);
                string token; // eg: Crawler, 2, 3, ...

                vector<string> tokens;
                while(getline(string_stream1,token, ';')){
                    tokens.push_back(token);
                }
                char bug_type = '\0';
                if(tokens.size() == 6 || tokens.size() == 7){ //  6 = Crawler, 7 = Hopper
                    bug_type = tokens[0][0]; // Assuming bug type is a single character

                    int id = stoi(tokens[1]); // stoi stands for string to integer
                    int x = stoi(tokens[2]);
                    int y = stoi(tokens[3]);
                    int dir = stoi(tokens[4]);
                    int size = stoi(tokens[5]);
                    if(tokens.size()==7){
                        int hope_length = stoi(tokens[6]);
                    }

                    // Create Bug object based on bug_type
                    Bug* bug = nullptr;
                    switch (bug_type) {
                        case 'H': { // Hopper
                            int hopLength = stoi(tokens[6]); // Assuming hop length is provided
                            bug = new Hopper(id, make_pair(x, y), static_cast<Direction>(dir), size, true, {}, hopLength);
                            break;
                        }
                        case 'C': { // Crawler
                            bug = new Crawler(id, make_pair(x, y), static_cast<Direction>(dir), size, true, {});
                            break;
                        }
                        default:
                            cout << "Invalid bug type: " << bug_type << endl;
                            break;
                    }
                }



                if (bug != nullptr) {
                    bug_vector.push_back(bug);
                }
            }
        }
        fin.close();
    }
}

void loadDataFromFile2(vector<Bug *> &bug_vector, const string &file_name, board &board){
    vector<Bug*> bug_vector;
    ifstream fin("bugs.txt");
    if(fin){
        while(!fin.eof()){ // do I need eof?
            string input_line; //declare
            while(getline(fin, input_line)){
                stringstream string_stream1(input_line);
                string token; // eg: Crawler, 2, 3, ...

                vector<string> tokens;
                while(getline(string_stream1,token, ';')){
                    tokens.push_back(token);
                }
                char bug_type = '\0';
                if(tokens.size() == 6 || tokens.size() == 7){ //  6 = Crawler, 7 = Hopper
                    bug_type = tokens[0][0]; // Assuming bug type is a single character

                    int id = stoi(tokens[1]); // stoi stands for string to integer
                    int x = stoi(tokens[2]);
                    int y = stoi(tokens[3]);
                    int dir = stoi(tokens[4]);
                    int size = stoi(tokens[5]);
                    if(tokens.size()==7){
                        int hope_length = stoi(tokens[6]);
                    }

                    // Create Bug object based on bug_type
                    Bug* bug = nullptr;
                    switch (bug_type) {
                        case 'H': { // Hopper
                            int hopLength = stoi(tokens[6]); // Assuming hop length is provided
                            bug = new Hopper(id, make_pair(x, y), static_cast<Direction>(dir), size, true, {}, hopLength);
                            break;
                        }
                        case 'C': { // Crawler
                            bug = new Crawler(id, make_pair(x, y), static_cast<Direction>(dir), size, true, {});
                            break;
                        }
                        default:
                            cout << "Invalid bug type: " << bug_type << endl;
                            break;
                    }
                }



                if (bug != nullptr) {
                    bug_vector.push_back(bug);
                }
            }
        }
        fin.close();
    }
}
