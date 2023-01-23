//
// Created by USER on 21/3/2024.
//

#include "Student.h"
Student::Student(){
    this->id = 1;
    this->name = "John Doe";
    this->age = 25;
    this->height = 1.5;
}

Student::Student(int id, std::string name,int age,double height){
    //this is a pointer, so dereference is needed
    this->id = id;
    this->name = name;
    this->age = age;
    this->height = height;
}

//getter, we can only add const to getter, but NOT the constructor nor setter cause they technically modifies
int Student::getId() const{
    return this->id;
}
std::string Student::getName() const{
    return this->name;
}
int Student::getAge() const{
    return this->age;
}
double Student::getHeight() const{
    return this->height;
}

//setter
void Student::setId(int id){
    this->id = id;
}
void Student::setName(std::string name){
    this->name = name;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setHeight(double height){
    this->height = height;
}
