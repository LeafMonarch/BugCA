#include <iostream>
#include <time.h> //for random
#include <iomanip> //for setw

using namespace std;
void question2();
void question4();
void question5();
void question6();
void question7();

void increment(double *d);
double divide(const int *ptr1, const int *ptr2);
double sumArr(const double arr[], const int &size);
double sumPtr(const double *arr, const int &size);
void doubleElements(int *arr, const int &size);
int strcmp(const char *s1, const char *s2);

int main() {
    question2();
    question4();
    question5();
    question6();
    question7();
    return 0;
}
void question7(){
    char str1[] = "Are these the sane?";
    char str2[] = "Are these the same?";
    int result = strcmp(str1, str2);
    cout << result;
}
int strcmp(const char *s1, const char *s2){
    while(*s1 == *s2 && *s1!='\0'){
        s1++;
        s2++;
    }
//    if(*s1 > *s2){
//        return 1;
//    }
//    else if(*s2 > *s1){
//        return -1;
//    }
//    else if(*s1 == *s2){
//        return 0;
//    }
    if(*s1 == *s2){
        return 0;
    }
    return (*s1 - *s2/abs(*s1-*s2));
}
void doubleElements(int *arr, const int &size){
    for(int i=0; i<size; i++){
        *arr *= 2;
        arr++;
    }
}
void display(int *arr, int size){
    cout << "[";
    for(int i=0; i<size; i++){
        if(i!=0){
            cout << ", ";
        }
        cout << setw(2) << *arr;
        arr++;
    }
    cout << "]" << endl;

}
void question6(){
    int arr[10];
    srand(time(NULL));
    for(int i=0; i<10; i++){
        arr[i] = (rand()%20) + 1;
    }
    display(arr, 10);
    doubleElements(arr,10);
    display(arr,10);
}
double sumArr(const double arr[],const int &size){
    double sum = 0.0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    return sum;
}
double sumPtr(const double *arr,const int &size){
    double sum = 0.0;
    for(int i=0; i<size; i++){
        sum += *arr;
        arr++;
    }
    return sum;
}
void question5(){
    double arr[] {1.5,9.8,6.3,8.2,9.7};
    cout << "Total using array notation: " << sumArr(arr, 5) << endl;
    cout << "Total using Pointer notation: " << sumPtr(arr, 5) << endl;

}
void question2(){
    double d = 3.14;
    cout << "Original value: " << d << endl;
    cout << "Address of D: " << &d << endl;
    increment(&d);
    cout << "Updated value: " << d << endl;
}
void question4(){
    int x = 10;
    int y = 4;
    cout << x << " / " << y << " = " << divide(&x,&y) << endl;
}
void increment(double *d){
    cout << "Address of D (in function): " << d << endl;
    *d += 0.01;
}
double divide(const int *ptr1,const int *ptr2){
    return *ptr1/ (double)*ptr2;
}
