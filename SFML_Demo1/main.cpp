// Sample program main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

struct tile
{
    CircleShape shape;
    bool isSelected = false;
    tile()
    {
        shape.setRadius(20);
    }

    bool contains(int x, int y)
    {
        int shapeX = ((int)shape.getPosition().x/50) * 50;
        int shapeY = ((int)shape.getPosition().y/50) * 50;
        return x == shapeX && y == shapeY;
    }
    Vector2f  getPosition(){
        int shapeX = ((int)shape.getPosition().x/50) * 50;
        int shapeY = ((int)shape.getPosition().y/50) * 50;
        return Vector2f(shapeX, shapeY);
    }
};

void mouseReleased(int x, int y);
void createTile();
vector<tile> tiles;
tile *selectedTile=nullptr;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
//    sf::CircleShape shape(25.f);   moved outside


//    sf::RectangleShape btn1;
//    btn1.setSize(sf::Vector2f(100, 25));
//    btn1.setPosition(sf::Vector2f(290, 5));
//    btn1.setFillColor(sf::Color::Red);
    vector<sf::RectangleShape> bg;
    for(int r=0; r<8; r++){
        for(int c=0; c<8; c++){
            sf::RectangleShape shape;
            shape.setPosition(r*50, c*50); //set position of individual squares on the background
            shape.setSize(Vector2f(50,50)); //set size of the individual square
            shape.setFillColor((r+c)%2==0?Color::Black:Color::White); //tenary operator    the r and c referes to the r and c from the for loop
            bg.push_back(shape);
        }
    }

//    shape.setFillColor(sf::Color::Green);
//    shape.setPosition(100,0);

    createTile();

    int i = 0;
    int dir = 0; //moving down 1 pixel per frame
    window.setFramerateLimit(40);
    bool isSelected = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonPressed)
            {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;

//                if(mouseX >= shape.getPosition().x && mouseX <= shape.getPosition().x + 50
//                && mouseY >= shape.getPosition().y && mouseY <= shape.getPosition().y + 50){
//                    isSelected = true;
//                    shape.setFillColor(sf::Color::Blue);
//                    shape.setPosition(mouseX-25,mouseY-25);
//                }
//                else{
//                    isSelected = false;
//                    shape.setFillColor(sf::Color::Green);
//                }
            }
            else if(event.type == sf::Event::MouseButtonReleased){
                if(isSelected){
                    isSelected = false;
                    //shape.setFillColor(sf::Color::Green);
                }
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                mouseReleased(mouseX, mouseY);
            }
            else if(event.type == sf::Event::MouseMoved){
                if(isSelected){
                  //  shape.setPosition(event.mouseMove.x-25, event.mouseMove.y-25);
                }
            }

//            if(event.type == sf::Event::MouseButtonEvent){
//                shape.setFillColor(sf::Color::Green);
//            }

        }

//        if(shape.getPosition().y >= 200 || shape.getPosition().y == 0)
//            dir *= -1;
////            shape.setPosition(shape.getPosition().x, 0);
//        if(i%20 == 0)
//            shape.setPosition(shape.getPosition().x, shape.getPosition().y+dir);


        window.clear();
        for(RectangleShape &s: bg){
            window.draw(s);
        }
        for(tile &s: tiles){
            window.draw(s.shape);
        }

        window.display();
    }

    return 0;
}
bool tileEmpty(int x, int y){
    for(tile &t: tiles){
        if(t.contains(x,y)){
            return false;
        }
    }
    return true;
}

void mouseReleased(int x, int y){
    int tileX = (x/50)*50;
    int tileY = (y/50)*50;
    if(selectedTile == nullptr){
        for(tile &t: tiles){
            if(t.contains(tileX, tileY)){
                selectedTile = &t;
                selectedTile->shape.setOutlineColor(Color::Blue);
            }
        }
    }
    else{
        Vector2f pos = selectedTile->getPosition();
        if(abs(tileX-pos.x)==50 && abs(tileY-pos.y)==50 && tileEmpty(tileX, tileY)){
            selectedTile->shape.setPosition(tileX+5, tileY+5);
        }
        else if(abs(tileX-pos.x)==100 && abs(tileY-pos.y)==100  && tileEmpty(tileX, tileY)){
            int midX = pos.x + (tileX-pos.x)/2;
            int midY = pos.y + (tileY-pos.y)/2;

            if(!tileEmpty(midX,midY)){
                for(auto t = tiles.begin(); t != tiles.end(); t++){
                    if(t->contains(midX,midY)){
                        selectedTile->shape.setPosition(tileX+5, tileY+5);
                        selectedTile->shape.setOutlineColor(Color::Black);
                        selectedTile= nullptr;
                        tiles.erase(t);
                    }
                }
            }
        }
        if(selectedTile!=nullptr){
            selectedTile->shape.setOutlineColor(Color::White);
            selectedTile=nullptr;
        }

    }

}

void createTile(){
    int st=0;
    for(int r=0; r<=2; r++){
        for(int c=st; c<8; c+=2){
            tile t;
            t.shape.setFillColor(Color::Magenta);
            t.shape.setPosition((c*50)+5,(r*50)+5);
            t.shape.setOutlineThickness(2);
            tiles.push_back(t);
        }
        st = (st==0?1:0);
    }

    for(int r=5; r<=7; r++){
        for(int c=st; c<8; c+=2){
            tile t;
            t.shape.setFillColor(Color::Cyan);
            t.shape.setPosition((c*50)+5,(r*50)+5);
            t.shape.setOutlineThickness(2);
            tiles.push_back(t);
        }
        st = (st==0?1:0);
    }
}