//
// Created by USER on 21/3/2024.
//
#include <iostream>
#ifndef CLASSES_STUDENT_H
#define CLASSES_STUDENT_H


class Student {
    int id;
    std::string name;
    int age;
    double height;

public:
    //this is constructor
    Student();
    Student(int id, std::string name,int age,double height);


    //getter, we can only add const to getter, but NOT the constructor nor setter cause they technically modifies
    int getId() const;
    std::string getName() const;
    int getAge() const;
    double getHeight() const;

    //setter
    void setId(int id);
    void setName(std::string name);
    void setAge(int age);
    void setHeight(double height);
};


#endif //CLASSES_STUDENT_H
