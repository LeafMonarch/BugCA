//
// Created by USER on 11/4/2024.
//

#ifndef CLASSES_COMPLEXNUMBER_H
#define CLASSES_COMPLEXNUMBER_H
#include <iostream>

using namespace std;

class ComplexNumber {
    int real, imaginary; //declaring variable
public:
    ComplexNumber();
    ComplexNumber(int real, int imaginary); //constructor

    void setReal(int real);
    void setImaginary(int img);
    int getReal();
    int getImaginary();
    friend ostream& operator<<(ostream& out, const ComplexNumber& cn);

    ComplexNumber operator+(const ComplexNumber& other);
    ComplexNumber operator-(const ComplexNumber& other);

    bool operator<(const ComplexNumber& other) const;
    bool operator==(const ComplexNumber& other) const;
    bool operator<=(const ComplexNumber& other) const;
    bool operator>=(const ComplexNumber& other) const;
    bool operator!=(const ComplexNumber& other) const;
};


#endif //CLASSES_COMPLEXNUMBER_H
bool operator>( ComplexNumber& cn1,  ComplexNumber& cn2);