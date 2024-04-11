#include <iostream>
using namespace std;

struct Rgb
{
    float r, g, b;
    Rgb() : r(0), g(0), b(0) {} // default values (0,0,0)
    Rgb(float rr, float gg, float bb) : r(rr), g(gg), b(bb) {}
};


struct geolocation{
    double lat; //8 bytes
    double lng; //8 bytes
};
struct tweet{
    int id; //4 bytes
    unsigned long int timestamp; //4 bytes
    string author; //32 bytes
    string msg; // 32 bytes
    geolocation location;
};
void display_tweet_by_value(tweet tweet1);
void display_tweet_by_reference(const tweet &tweet1);
void display_tweet_by_pointer(tweet *tweet1);
void moveNext();
void display_tweet_array_notation(const tweet arr[], int size);
void question1();
void question2();
void display_pixel_channels(const Rgb &pixel, const string &name);
Rgb getRgb(int red, int green, int blue);
void redFilter(Rgb &ref);

int main() {
    question2();
    return 0;
}
void display_pixel_channels(const Rgb &pixel, const string &name){
    int r, g, b;
    r = pixel.r * 255;
    g = pixel.g * 255;
    b = pixel.b * 255;

    cout << name << "\tRGB Value(" << r << "," << g << "," << b << ")" << endl;
}
Rgb getRgb(int red, int green, int blue){
    return Rgb(red/255.0f, green/255.0f, blue/255.0f);
}
void redFilter(Rgb &ref){
    int r, g, b;
    g = 0;
    b = 0;
    cout << "Red Filter\tRGB Value(" << r << "," << g << "," << b << ")" << endl;
}
void question2(){
    Rgb blackPixel;
    Rgb redPixel(1,0,0);
    Rgb greenPixel(0,1,0);
    Rgb bluePixel(0,0,1);
    Rgb pinkPixel(1,0.7,0.85);
    Rgb magentaPixel(1,0,1);

    display_pixel_channels(blackPixel, "Black");
    display_pixel_channels(redPixel, "Red");
    display_pixel_channels(greenPixel, "Green");
    display_pixel_channels(bluePixel, "Blue");
    display_pixel_channels(pinkPixel, "Pink");
    display_pixel_channels(magentaPixel, "Magenta");

    Rgb pixel = getRgb(128,128,128); //from 255 to 1
    cout << pixel.r << ", " << pixel.g << ", " << pixel.b << endl;
    display_pixel_channels(pixel, "Grey");

    redFilter(pixel);

}
void question1(){
    geolocation geo;
    geo.lat = 59.366996;
    geo.lng = 1.369852;
    cout << "Your current location is " << geo.lat << ", " << geo.lng << endl;
    geolocation newlocation = geo;
    cout << "Your current location is " << newlocation.lat << ", " << newlocation.lng << endl;

    cout << "Hello" << endl;
    tweet tweet1;
    cout << "Size of tweet: " << sizeof(tweet1) << endl;
    tweet1.id = 1;
    tweet1.author = "AC Doyle";
    tweet1.msg  = "Elementary!";
    tweet1.timestamp = 167987523;
    tweet1.location.lat = 59.366996; 
    tweet1.location.lng = 60.3669;
    display_tweet_by_value(tweet1);
   // moveNext();
    display_tweet_by_reference(tweet1);
 //   moveNext();
    display_tweet_by_pointer(&tweet1);
    //moveNext();

    cout << "============================ Tweets Array ============================" << endl;
    tweet *tweets = new tweet[3];
    tweets[0] = tweet1;

    tweets[1].id = 2;
    tweets[1].author = "Harry Potter";
    tweets[1].msg  = "Expecto Patronum!!!";
    tweets[1].timestamp = 167987523;
    tweets[1].location.lat = 29.366996;
    tweets[1].location.lng = 5.3669;

    tweets[2].id = 3;
    tweets[2].author = "Yee Chean";
    tweets[2].msg  = "When life gives you lemon!!!";
    tweets[2].timestamp = 167987523;
    tweets[2].location.lat = 252.366996;
    tweets[2].location.lng = 523.3669;

    for(int i=0; i<3; i++){
        display_tweet_by_reference(tweets[i]);
    }

    cout << "============================ Tweets Array Notation============================" << endl;
    display_tweet_array_notation(tweets, 3);

    delete[] tweets;
    tweets = nullptr;


}
void display_tweet_by_value(tweet tweet1){
    cout << string(14,'*') << " " << tweet1.id << " " << string(14,'*') << endl;
    cout << tweet1.msg << endl;
    cout << tweet1.author << "\t(" << tweet1.timestamp << ")" << endl;
    cout << "(" << tweet1.location.lng << ", " << tweet1.location.lat << ")" << endl;
    cout << "By Value\n\n\n";
}

void display_tweet_by_reference(const tweet &tweet1){
    cout << string(14,'*') << " " << tweet1.id << " " << string(14,'*') << endl;
    cout << tweet1.msg << endl;
    cout << tweet1.author << "\t(" << tweet1.timestamp << ")" << endl;
    cout << "(" << tweet1.location.lng << ", " << tweet1.location.lat << ")" << endl;
    cout << "By Reference\n\n\n";
}

void display_tweet_by_pointer(tweet *tweet1){
    //*tweet1.id; doesnt work because . has a higher precedence than the *, so . will be read first
    // therefore (*tweet1).id   but a little hard to see, so tweet1->id
    cout << string(14,'*') << " " << tweet1->id << " " << string(14,'*') << endl;
    cout << tweet1->msg << endl;
    cout << tweet1->author << "\t(" << tweet1->timestamp << ")" << endl;
    cout << "(" << tweet1->location.lng << ", " << tweet1->location.lat << ")" << endl;
    cout << "By Pointer\n\n\n";

    //the arrow dereference the tweet1 first, then call the operator
}
void moveNext(){
    string temp;
    cout << "Please enter to continue: " << endl;
    getline(cin,temp);
    system("cls");
}

void display_tweet_array_notation(const tweet arr[], int size){
    for(int i=0; i<size; i++){
        display_tweet_by_reference(arr[i]);
    }
}