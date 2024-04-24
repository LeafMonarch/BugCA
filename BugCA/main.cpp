#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Bug.h"
#include "Hopper.h"
#include "Crawler.h"
#include "Leaf_Hopper.h"
#include "Super_Bug.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
using namespace sf;

//read in bugs.txt and create bugs objects accordingly
void load_data_from_file(vector<Bug *> &bug_vector, const string &file_name, Board *board);
//finds bug via id
void find_bug_by_id(vector<Bug *> &bug_vector);
//initiate SMFL
void graphic_user_interface(vector<Bug *> &bug_vector);

//Textures for different png icons
Texture crawlerTexture;
Texture hopperTexture;
Texture leafHopperTexture;
Texture superBugTexture;
Texture deadBugTexture;

void loadTextures() {
    crawlerTexture.loadFromFile("cmake-build-debug/Crawler.png");
    hopperTexture.loadFromFile("cmake-build-debug/Hopper.png");
    leafHopperTexture.loadFromFile("cmake-build-debug/Leaf_Hopper.png");
    superBugTexture.loadFromFile("cmake-build-debug/Super_Bug.png");
    deadBugTexture.loadFromFile("cmake-build-debug/Dead.png");
}
//Tile refers to individual Bug on the SFML board
struct tile
{
    Sprite sprite;
    bool isSelected = false;
    tile(Texture texture) // Pass texture by reference to avoid unnecessary copying
    {
        sprite.setTexture(texture); // Set the texture of the sprite
        // Set other sprite properties as needed, e.g., position, scale, etc.
        float height = 50.0f;
        float scaleFactor = height / sprite.getLocalBounds().height;
        sprite.setScale(scaleFactor, scaleFactor);
    }

    bool contains(int x, int y)
    {
        int shapeX = ((int)sprite.getPosition().x/80) * 80;
        int shapeY = ((int)sprite.getPosition().y/80) * 80;
        return x == shapeX && y == shapeY;
    }
    Vector2f  getPosition(){
        int shapeX = ((int)sprite.getPosition().x/80) * 80;
        int shapeY = ((int)sprite.getPosition().y/80) * 80;
        return Vector2f(shapeX, shapeY);
    }
};

//A vector of Bugs on the Board (10x10)
vector<tile> tiles;
//Initiate and populate SFML board with bugs read in from the bugs.txt
void initializeBug(vector<Bug *> &bug_vector);
//SFML Tap to move all bugs
void gui_tap_move(vector<Bug *> &bug_vector);


int main() {
    vector<Bug*> bug_vector;
    auto *board = new Board();
    bool end = false;
    int menu_option;
    load_data_from_file(bug_vector, "bugs.txt", board);


    do {
        cout << "Menu Items" << endl;
        cout << "1. Initialize Bug Board (load data from file)" << endl;
        cout << "2. Display all Bugs" << endl;
        cout << "3. Find a Bug (given an id)" << endl;
        cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
        cout << "5. Display Life History of all Bugs (path taken)" << endl;
        cout << "6. Exit" << endl;
        cout << "7. Display all Cells" << endl;
        cout << "8. Run Simulation" << endl;
        cout << "9. Implement a GUI for the project using the SFML library." << endl;

        cout << "Please select an option . . . " << endl;
        cin >> menu_option;

        switch(menu_option) {
            case 1:
                board -> initialize_board(bug_vector);
                break;
            case 2:
                board -> display_bugs();
                break;

            case 3:
                find_bug_by_id(bug_vector);
                break;

            case 4:
                board -> tap_board();
                break;

            case 5:
                board -> display_life_history_of_all_bugs();
                break;

            case 6:
                board -> exit();
                break;

            case 7:
                board -> display_all_cells();
                break;

            case 8:
                board -> run_simulation();
                break;

            case 9:
                graphic_user_interface(bug_vector);
                break;

            case 11:
                end = true;
                break;
        }
    }while(!end);
    return 0;
}

//Load data from bugs.txt and create bugs objects accordingly
void load_data_from_file(vector<Bug *> &bug_vector, const string &file_name, Board *board){
    ifstream fin(file_name);
    if(fin){
        cout << "File opened successfully" << endl;
        while(!fin.eof()){
            string input_line; // Stores each line of bugs.txt
            while(getline(fin, input_line)){
                stringstream string_stream1(input_line); //stringstream reads in a line of data as if it's a string
                string token; // eg: Crawler, 2, 3, ...

                vector<string> tokens;
                while(getline(string_stream1,token, ';')){
                    tokens.push_back(token);
                }
                char bug_type = '\0';
                //  6 = Crawler/Leaf_Hopper/Super_Bug, 7 = Hopper
                if(tokens.size() == 6 || tokens.size() == 7){
                    bug_type = tokens[0][0]; // Assuming bug type is a single character

                    int id = stoi(tokens[1]); // stoi stands for string to integer
                    int x = stoi(tokens[2]);
                    int y = stoi(tokens[3]);
                    int dir = stoi(tokens[4]);
                    int size = stoi(tokens[5]);
                    int hop_length;
                    if(tokens.size()==7){
                        hop_length = stoi(tokens[6]);
                    }

                    // Create Bug object based on bug_type
                    Bug* bug = nullptr;
                    switch (bug_type) {
                        case 'H': { // Hopper
                            bug = new Hopper(bug_type, id, make_pair(x, y), static_cast<Direction>(dir), size, hop_length);
                            break;
                        }
                        case 'C': { // Crawler
                            bug = new Crawler(bug_type, id, make_pair(x, y), static_cast<Direction>(dir), size);
                            break;
                        }
                        case 'L': { // Leaf_Hopper
                            bug = new Leaf_Hopper(bug_type, id, make_pair(x, y), static_cast<Direction>(dir), size);
                            break;
                        }
                        case 'S': { // Super_Bug
                            bug = new Super_Bug(bug_type, id, make_pair(x, y), static_cast<Direction>(dir), size);
                            break;
                        }
                        default:
                            cout << "Invalid bug type: " << bug_type << endl;
                            break;
                    }
                    if (bug != nullptr) {
                        bug_vector.push_back(bug);
                    }
                }
            }
        }
        fin.close();
    } else {
        cout << "Failed to open file." << endl;
    }
}

void find_bug_by_id(vector<Bug *> &bug_vector){
    int bug_id;
    cout << "Please enter a bug id: " << endl;
    cin >> bug_id;
    for(auto b: bug_vector){
        if(bug_id == b->getId()){
            b->display_all_bug_details();
        }
    }
    cout << "\n";
    cout << "\n";
}

void graphic_user_interface(vector<Bug *> &bug_vector) {
    sf::RenderWindow window(sf::VideoMode(960, 960), "SFML works!");

    vector<sf::RectangleShape> bg;  //Creating Board
    for (int r = 0; r <= 11; ++r) {
        for (int c = 0; c <= 11; ++c) {
            sf::RectangleShape shape;
            //The four sides of the 10x10 Board
            if (r == 0 || c == 0 || r == 11 || c == 11) {
                shape.setFillColor(Color::Black);
            }
            //The 10x10 Board
            else {
                shape.setPosition(r * 80-5, c * 80-5); //set position of individual squares on the background
                shape.setSize(Vector2f(80, 80)); //set size of the individual square
                shape.setFillColor((r + c) % 2 == 0 ? Color(181, 230, 29): Color::White); //Tenary Operator
            }
            bg.push_back(shape);
        }
    }
    initializeBug(bug_vector); //Populate the Board with Bugs

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {//The Close Window Button
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {//If Tap on SFML window
                gui_tap_move(bug_vector);
                initializeBug(bug_vector);
            }
            //If Keys are pressed
            else if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    // Handle W key press, Super Bug Moves Up/North
                    for(auto & b : bug_vector){
                        if(b -> getBugType()=='S'){
                            b ->setDir(Direction::North);
                        }
                    }
                    gui_tap_move(bug_vector);
                    initializeBug(bug_vector);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    // Handle A key press, Super Bug Moves Left/West
                    for(auto & b : bug_vector){
                        if(b -> getBugType()=='S'){
                            b ->setDir(Direction::West);
                        }
                    }
                    gui_tap_move(bug_vector);
                    initializeBug(bug_vector);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    // Handle S key press, Super Bug Moves Down/South
                    for(auto & b : bug_vector){
                        if(b -> getBugType()=='S'){
                            b ->setDir(Direction::South);
                        }
                    }
                    gui_tap_move(bug_vector);
                    initializeBug(bug_vector);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    // Handle D key press, Super Bug Moves Right/East
                    for(auto & b : bug_vector){
                        if(b -> getBugType()=='S'){
                            b ->setDir(Direction::East);
                        }
                    }
                    gui_tap_move(bug_vector);
                    initializeBug(bug_vector);
                }
            }
            window.clear();
            //Draws the Board
            for (RectangleShape &s: bg) {
                window.draw(s);
            }
            //Draws the Bug Sprites
            for (tile &s: tiles) {
                window.draw(s.sprite);
            }
            window.display();
        }
    }
}

void initializeBug(vector<Bug *> &bug_vector){
    for(int r = 0; r <= 11; ++r){
        for(int c = 0; c <= 11; ++c){
            for(auto & b : bug_vector){
                tile t(crawlerTexture); // Create a tile with the bug texture
                string bugTextureString;

                //If Bug is Dead, display Skull/Dead Png
                if(b -> getPosition().first == c && b -> getPosition().second == r && !b->isAlive()){
//                    t.shape.setFillColor(Color::Red);
//                    t.shape.setPosition((c*80)+8,(r*80)+8);
                    t.sprite.setTexture(deadBugTexture);
                    t.sprite.setPosition((c*80)+8,(r*80)+8);
                    tiles.push_back(t);
                }
                //if Bug is Alive, display pngs respective to their bug_type
                else if(b -> getPosition().first == c && b -> getPosition().second == r){

                    if (b->getBugType() == 'C') {
                        loadTextures();
                        t.sprite.setTexture(crawlerTexture);
                    } else if (b->getBugType() == 'H') {
                        loadTextures();
                        t.sprite.setTexture(hopperTexture);
                    } else if (b->getBugType() == 'L') {
                        loadTextures();
                        t.sprite.setTexture(leafHopperTexture);
                    } else if (b->getBugType() == 'S') {
                        loadTextures();
                        t.sprite.setTexture(superBugTexture);
                    }
                    t.sprite.setPosition((c*80)+8,(r*80)+8);
                    tiles.push_back(t);
                }
            }
        }
    }
}

void gui_tap_move(vector<Bug *> &bug_vector){
    tiles.clear();
    auto *board = new Board();
    board -> initialize_board(bug_vector);
    board -> tap_board();
}