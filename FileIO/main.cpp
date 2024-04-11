#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector> //vector is just like an arraylist in an object

using namespace std;

void question1();
void question2();
void question3();
void question4();
void question5();

struct MenuItem{
    string desc;
    double price;
};

int main() {
    //question1();
    //question2();
    //question3();
    //question4();
    question5();
    return 0;
}
void question1(){
    string name;
    ofstream fout; //opening file and store stuff into it  ofsteam means file out
    fout.open("names.txt", ios_base::app); //ios DOES NOT mean Iphone Operating System btw
    if(fout){
        cout << "Please enter your name. " << endl;
        getline(cin,name);
        fout << name << endl;
        fout.close();
    }
    else{
        cout << "Error opening file." << endl;
    }
}
void question2(){
    string name;
    ifstream fin("names.txt"); //ifstream file in
    if(fin){ //if exist, open, if not error
        while(!fin.eof()){
            getline(fin,name);
            string::size_type len = name.size();
            string top(len+4,'*');
            cout << top << endl;
            cout << "* " << name << " *" << endl;
            cout << top << endl;
        }
        fin.close();
    }
    else{
        cout << "Error opening file." << endl;
    }
}
void question3(){
    int num;
//    int total = 0; //must initialise total number = 0 else i might get funny number
    ifstream fin("num.txt");
    if(fin){
        double total=0;
        int count=0;
        while(!fin.eof()){
            fin >> num;
            cout << num << endl;
            count++;
            total += num;
        }
        double avg = total/(double)count;
        cout << "The average of the numbers in the file is: " << avg << endl;
    }
    else{
        cout << "Error opening file." << endl;
    }

}
void question4(){
    ifstream fin("Final Results.txt"); //read in data from a file
    ofstream fout("Final_final_results.txt");
    if(fin && fout){
        while(!fin.eof()){
            string name;
            getline(fin,name);
            if(name.size()>0){
                double ca,fe;
                fin >> ca >> fe;
                fin.ignore(1000,'\n');
                double overall = (ca*.4) + (fe*.6);
                fout <<setw(20) << left << name << " - " << overall << endl;
            }
        }
        fin.close();
        fout.close();
    }
    else{
        cout << "Error opening file." << endl;
    }
}
void question5(){
    ifstream fin("menu.txt");
    if(fin){
        vector<MenuItem> items;
        while(!fin.eof()){
            MenuItem item;
            getline(fin, item.desc);
            fin >> item.price;
            fin.ignore(1000,'\n');
            items.push_back(item); //pushing the items we created into the item vector
            //cout << item.desc << " - $" << item.price << endl;
        }
        fin.close();
        ofstream fout("new_menu.txt");
        if(fout){
            for(int i = 0; i < items.size(); i++){
                if(items[i].price < 5.00){
                    items[i].price += .50;
                }
                else{
                    items[i].price += 1.50;
                }
                fout << items[i].desc << " - " << items[i].price << endl;
            }
            fout.close();
        }
    }
    else{
        cout << "Error opening file." << endl;
    }
}