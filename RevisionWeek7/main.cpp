#include <iostream>
#include <list>
#include <fstream>
#include <time.h>

using namespace std;

bool contains(const list<string> &words, string word);

string clean(string &str){
    string st = "";
    for(char c:str){
        if((c >= 65 && c <= 90 || (c >= 97 && c <= 122))){
            st += c;
        }
    }
}
void readData(list<string> &uniqueWords, string filename){
    ifstream fin(filename);
    if(fin){
        string word;
        while(!fin.eof()){
            fin >> word;
            if(!contains(uniqueWords, word));
        }
        fin.close();
    }
    else{
        cout << "Error opening file. " << endl;
    }
}

bool contains(const list<string> &words, string word){
    list<string>::const_iterator it;
    for(it = words.cbegin(); it != words.cend(); it++){
        if(word == *it){
            return true;
        }
    }
}
void write_data(list<string> &uniqueWords, string outputFile){

    //sort(uniqueWords.begin(), uniqueWords.end());
    ofstream fout(outputFile);
    if(fout){
        list<string> ::iterator iter = uniqueWords.begin();
        for(;iter!=uniqueWords.end(); iter++){
            cout << *iter << endl;
        }

    }
    else {
        cout << "Error opening file. " << endl;
    }
}
void display(int arr[], int size){
    cout << "[";
    for(int i=0; i<size;i++){
        if(i!=0){
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << "]" << endl;
}
void reverse(int *arr, int size){
    int *st = arr;
    int *end = arr + (size-1);
    while(st < end){
        {
            int temp = *st;
            *st = *end;
            *end = temp;
            *st++;
            end--;
        }
    }
}
int main() {
    int *nums = new int[10];
    srand(time(NULL));
    for(int i=0; i<10;i++){
        nums[i] = 1+(rand()%10);
    }
    display(nums, 10);
    reverse(nums, 10);
    display(nums, 10);
    delete[] nums;
    return 0;
}
