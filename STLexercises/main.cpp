#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;
void question1();
void question2();
void question3();
void loadDataToVector(vector<int> &nums);
void display(const vector<int> &nums, string s="");
void display(const vector<string> &strs, string s="");
void question4();
void question7();
void question8();
void question9();
void question10();
void interleave(const list<int> &lst1,const list<int> &lst2,const list<int> &lst3);
void loadDataToVector(vector<int> &numbers)
{
    ifstream fin("num.txt");

    if(fin)
    {
        while(!fin.eof())
        {
            int num;
            fin >> num;
            numbers.push_back(num);
        }
    }
    else
    {
        cout << "Error handling file" << endl;
    }
}
int main() {
    question10();
    return 0;
}
void display(const list<int> &nums, string s =""){
    cout << s << "[";
    for(auto iter = nums.cbegin(); iter!=nums.cend();iter++){
        if(iter != nums.cbegin()){
            cout << ", ";
        }
        cout << *iter;
    }
    cout << "]" << endl;
}
void question1(){
    ifstream fin("num.txt");
    vector<int> numbers;
    if(fin){
        while(!fin.eof()){
            int num;
            fin >> num;
            numbers.push_back(num);
        }
        cout << "Please enter a number to find" << endl;
        int key;
        cin >> key;
        int pos =-1;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers.at(i) == key){
                pos = 1;
                break;
            }
        }
        if(pos == -1){
            cout << key << " has not been found." << endl;
        }
        else{
            cout << key << " found at position " << pos;
        }
    }
}
void question3()
{
    vector<int> nums;
    loadDataToVector(nums);
    display(nums, "Before sort: ");

    sort(nums.begin(),nums.end());
    display(nums, "After Sort Ascending: ");

    sort(nums.begin(), nums.end(),[](int x, int y){return x>y;});
    display(nums, "After Sort non-Ascending: ");
}
void question4()
{
    vector<string> strs = {"I", "am", "Iron", "Man", "and", "Today", "is", "Thursday"};
    sort(strs.begin(), strs.end(), [](string x, string y){return x.size() > y.size();});
    display(strs, "After sort of string length: ");
}
void question7()
{
    vector<string> mths {"Jan", "Apr", "May", "Sept", "Nov", "Dec"};
    vector<string>::iterator iter = mths.begin();
    iter++;
//    iter = mths.insert(iter, "Feb");
//    display(mths, "After Feb inserted");
//
//    iter = mths.insert(iter+1, "Mar");
//    display(mths, "After Mar inserted");
//
//    iter = mths.insert(iter+3, "Jun");
//    display(mths, "After Jun inserted");
//
//    iter = mths.insert(iter+1, "Jul");
//    display(mths, "After Jul inserted");
//
//    iter = mths.insert(iter+1, "Aug");
//    display(mths, "After Aug inserted");
//
//    iter = mths.insert(iter+2, "Oct");
//    display(mths, "After Oct inserted");

    // you dont have to sort them

    iter = mths.insert(iter, "Mar");
    display(mths, "After Mar inserted");
    iter = mths.insert(iter, "Feb");
    display(mths, "After Feb inserted");
    iter+=4;
    iter = mths.insert(iter, "Aug");
    display(mths, "After Aug inserted");
    iter = mths.insert(iter, "Jul");
    display(mths, "After Jul inserted");
    iter = mths.insert(iter, "Jun");
    display(mths, "After Jun inserted");
    iter+=4;

    iter = mths.insert(iter, "Oct");
    display(mths, "After all months inserted");

}
int areSameUntil(const vector<int> &v1, const vector<int> &v2)
{
    int min = v1.size() < v2.size() ? v1.size() : v2.size();
    int i =0;
    while(i<min && v1[i] == v2[i])
    {
        i++;
    }
    return i-1;
}
void question8()
{
//    vector<int> x {1,2,3,4};
//    vector<int> y {1,2,3,6};
//    int pos = areSameUntil(x, y);
//
//    if (pos == x.size() && pos == y.size())
//    {
//        cout << "Vectors are completely same." << endl;
//    }
//    else
//    {
//        cout << "Vectors differ at position " << pos << endl;
//    }

    vector<int> v1a {1,2,3,4,5};
    vector<int> v2a {1,2,4,3,5};
    cout << "Test 1: " << areSameUntil(v1a,v2a) <<endl;

    vector<int> v1b {2,4,6,7,3};
    vector<int> v2b {1,2,4,3,5};
    cout << "Test 2: " << areSameUntil(v1b,v2b) <<endl;

    vector<int> v1c {0,2};
    vector<int> v2c {1,2,4,3,5};
    cout << "Test 3: " << areSameUntil(v1c,v2c) <<endl;

}
bool areSameReverse(const list<int> &lst1, const list<int> &lst2)
{
    list<int>::const_iterator iter1 = lst1.cbegin();
    list<int>::const_reverse_iterator iter2 = lst2.crbegin();
    while(iter1 != lst1.cend() && iter2 != lst2.crend()){
        if(*iter1 != *iter2){
            return false;
        }
        iter1++;
        iter2++;

    }
    return iter1 == lst1.cend() && iter2 == lst2.crend();
}
void question9(){
    list<int> lst1 {1,2,3};
    list<int> lst2 {3,2,1};
    string msg = areSameReverse(lst1,lst2)?"These are the same":"These are different";
    cout << "Test 1 (True):" << msg << endl;

    string msg2 = areSameReverse(lst1,lst1)?"These are the same":"These are different";
    cout << "Test 2 (False):" << msg2 << endl;
}
void interleave(const list<int> &lst1,const list<int> &lst2, list<int> &lst3){
    auto iter1 = lst1.cbegin();
    auto iter2 = lst2.cbegin();
    while(iter1!=lst1.cend() || iter2!=lst2.cend()){
        if(iter1!=lst1.cend()){
            lst3.push_back(*iter1);
            iter1++;
        }
        if(iter2!=lst2.cend()){
            lst3.push_back(*iter2);
            iter2++;
        }
    }
}
void question10(){
    list<int> lst1a {1,2,3};
    list<int> lst2a {3,2,1};
    list<int> lst3a;
    interleave(lst1a,lst2a,lst3a);
    display(lst3a, "Interleaved List 1");
    list<int> lst1b {1,2,3,4,5};
    list<int> lst2b {3,2,1};
    list<int> lst3b;
    interleave(lst1b,lst2b,lst3b);
    display(lst3b, "Interleaved List 2");
    list<int> lst3c;
    interleave(lst2b,lst1b,lst3c);
    display(lst3c, "Interleaved List 3");
}
