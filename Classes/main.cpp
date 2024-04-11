#include <iostream>

#include "Student.h"
#include "DayType.h"
#include <iomanip>
#include "ClockType.h"
#include "ComplexNumber.h"
#include "BufferedReader.h"

using namespace std;

void question1();
void display_student_by_value(Student stud);
void display_student_by_reference(const Student &stud);
void display_student_by_pointer(const Student *stud);
void question2();
void question3();
void question5();
void question6();


int main() {
    //every project can only have 1 main method
    question6();
    return 0;
}
void display_student_by_value(Student stud){
    cout << "(display by value) " << stud.getId() << ": " << stud.getName() << " (" << stud.getAge() << ", " << stud.getHeight() << ")" << endl;
}
void display_student_by_reference(const Student &stud){
    cout << "(by reference) " << stud.getId() << ": " << stud.getName() << " (" << stud.getAge() << ", " << stud.getHeight() << ")" << endl;
}
void display_student_by_pointer(const Student *stud){
    cout << "(by pointer) " << stud->getId() << ": " << stud->getName() << " (" << stud->getAge() << ", " << stud->getHeight() << ")" << endl;
}
void question1(){
    Student student1;
    Student student2(2, "Tony Stark", 46, 1.7);
    display_student_by_value(student1);
    display_student_by_value(student2);

    display_student_by_reference(student1);
    display_student_by_reference(student2);

    display_student_by_pointer(&student1);
    display_student_by_pointer(&student2);

    Student *studentPtr = new Student(3, "Natasha Romanov", 32, 1.5);

    display_student_by_pointer(studentPtr);
    cout << "Name via pointer: " << studentPtr->getName() << endl;
    studentPtr-> setHeight(1.65);
    display_student_by_pointer(studentPtr);

    delete studentPtr;
    studentPtr = nullptr;
}
void question2(){
    DayType dt(3);
    cout << "At start: " << dt.getCurrentDay() << endl;
    dt.setCurrentDay(5);
    dt.printCurrentDay();

    cout << left << setw(10) << "Previous" << setw(10) << "Current" << setw(10) << "Next" << endl;
    for(int i=0; i<7; i++){
        dt.setCurrentDay(i);
        cout << left << setw(10) << dt.getPreviousDay() << setw(10) << dt.getCurrentDay() << setw(10) << dt.getNextDay() << endl;
    }

    dt.setCurrentDay(1);
    cout << dt.getCurrentDay() << " + 4 days : " << dt.getXdaysInFuture(4) << endl;

    dt.setCurrentDay(2);
    cout << dt.getCurrentDay() << " + 13 days : " << dt.getXdaysInFuture(13) << endl;
}

void question3(){
    ClockType ct(23,59,59);
    cout << ct.getCurrentTime() << endl;
    ct.incrementBySeconds(2);
    cout << ct.getCurrentTime() << endl;

    ct.displayCurrentTime();
    ct.resetClock();
    ct.displayCurrentTime();
    ct.setTime(10,10,30);
    ct.displayCurrentTime();

    cout << "getElapsedTime():" << ct.getElapsedTime() << endl;
    cout << "getRemainingTime():" <<ct.getRemainingTime() << endl;

    ClockType ctt(0,0,0);
    cout << "getDifference():" << ct.getDifference(ctt) << endl;
}
void question5(){
    ComplexNumber cn(3,4);
    ComplexNumber cn2(1,2);

    cout << cn << endl;
    ComplexNumber cn3 = cn + cn2;
    cout << "(" << cn << ") + (" << cn2 << ") = " << cn3;

    cout << endl;

    ComplexNumber cn4 = cn - cn2;
    cout << "(" << cn << ") - (" << cn2 << ") = " << cn4;
    ComplexNumber cn5 = cn4;

    cout << endl;
    if(cn3 < cn4){
        cout << cn3 << " is smallest" << endl;
    }
    else{
        cout << cn4 << " is smallest" << endl;
    }

    cout << endl;
    if(cn3 > cn4){
        cout << cn3 << " is greater" << endl;
    }
    else{
        cout << cn4 << " is greater" << endl;
    }

    cout << endl;
    if(cn3 == cn4){
        cout << cn3 << " is equal to "  << cn4 << endl;
    }
    else{
        cout << cn3 << " is not equal to " << cn4 << endl;
    }

    cout << endl;
    if(cn5 == cn4){
        cout << cn5 << " is equal to "  << cn4 << endl;
    }
    else{
        cout << cn5 << " is not equal to " << cn4 << endl;
    }

    cout << endl;
    if(cn3 <= cn4){
        cout << cn3 << " is less than equals to "  << cn4 << endl;
    }
    else{
        cout << cn3 << " is not less than equals to " << cn4 << endl;
    }

    cout << endl;
    if(cn4 <= cn3){
        cout << cn4 << " is less than equals to "  << cn3 << endl;
    }
    else{
        cout << cn4 << " is not less than equals to " << cn3 << endl;
    }

    cout << endl;
    if(cn3 >= cn4){
        cout << cn3 << " is more than equals to "  << cn4 << endl;
    }
    else{
        cout << cn3 << " is not more than equals to " << cn4 << endl;
    }

    cout << endl;
    if(cn4 >= cn3){
        cout << cn4 << " is more than equals to "  << cn3 << endl;
    }
    else{
        cout << cn4 << " is not more than equals to " << cn3 << endl;
    }

    cout << endl;
    if(cn3 != cn4){
        cout << cn3 << " is not equal to "  << cn4 << endl;
    }
    else{
        cout << cn3 << " is  equal to " << cn4 << endl;
    }

    cout << endl;
    if(cn5 != cn4){
        cout << cn5 << " is not equal to "  << cn4 << endl;
    }
    else{
        cout << cn5 << " is equal to " << cn4 << endl;
    }
}

void question6(){
    BufferedReader i("Input.txt");
//    cout << i++ << endl;
    cout << i << endl;
//    cout << ++i << endl;
    cout << i << endl;
}

