#include <iostream>
using namespace std;



void question2();
void question3();
void question5();
void question6();
void question7();


int main() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(NULL));
    question2();
    question3();
    question5();
    question6();
    question7();


    return 0;
}




void density(double width, double height, double depth, double mass, double &density){
    density = mass/(width*height*depth);
}
void question2(){
    double w,h,d,m, den;
    cout << "Width: " << endl;
    cin >> w;
    cout << "Height: " << endl;
    cin >> h;
    cout << "Depth: " << endl;
    cin >> d;
    cout << "Mass: " << endl;
    cin >> m;

    density(w,h,d,m,den);
    cout << "The Density is: " << den << endl;
}
int charToDecimal(char c){
    return c;
}
void question3(){
    for(int i=0;i<26;i++){
        char c = 'A' + i;
        int charVal = charToDecimal(c);
        cout << c << " has a value of " << charVal << endl;
    }

}
void increment(int &x){
    x++;
}
void question5(){
    int x;
    cout << "Enter an Integer: " << endl;
    cin >> x;

    increment(x);
    cout << "New Value: " << x << endl;
}
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void question6(){
    int x,y;
    x=1;
    y=2;
    cout << "Before swap: " << x << ", " << y << endl;
    swap(x,y);
    cout << "After swap: " << x << ", " << y << endl;
}
int sumRandom(int start, int end){
    int sum=0;
    for(int i=0;i<100;i++){
        int num = start+rand()%(end-start);
        sum += num;
    }
    return sum;
}
void question7(){
    int start, end, total;
    start = 20;
    end = 40;
    total = 0;
    total = sumRandom(start, end);
    cout << "The sum is: " << total << endl;
}

