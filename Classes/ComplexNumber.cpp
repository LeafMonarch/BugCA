//
// Created by USER on 11/4/2024.
//
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(){
    this->real = this-> imaginary = 0;
}

ComplexNumber::ComplexNumber(int real, int imaginary){
    this->real = real;
    this->imaginary = imaginary;
}

void ComplexNumber::setReal(int real){
    this->real = real;
}
void ComplexNumber::setImaginary(int img){
    this->imaginary = img;
}
int ComplexNumber::getReal(){
    return this->real;
}
int ComplexNumber::getImaginary(){
    return this->imaginary;
}

ostream& operator<<(ostream& out, const ComplexNumber& cn){
    out << cn.real; // out: 3
    if(cn.imaginary < 0)
    {
        out << " - " << abs(cn.imaginary) << "i"; //out: 3 + 4i
    }
    else
    {
        out << " + " << cn.imaginary << "i";
    }
    return out; //out is say: 3 + 4i
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other){
    int r = this->real + other.real;
    int i = this-> imaginary + other.imaginary;
    return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other){
    int r = this->real - other.real;
    int i = this-> imaginary - other.imaginary;
    return ComplexNumber(r, i);
}

bool ComplexNumber::operator<(const ComplexNumber& other) const{
    if(this->real == other.real){
        return this->imaginary < other.imaginary;
    }
    return this->real < other.real;
}

bool operator>(ComplexNumber& cn1, ComplexNumber& cn2){
    if(cn1.getReal() == cn2.getReal()){
        return cn1.getImaginary() > cn2.getImaginary();
    }
    return cn1.getReal() > cn2.getReal();
}


bool ComplexNumber::operator<=(const ComplexNumber& other) const{
    if(this->real == other.real){
        return this->imaginary <= other.imaginary;
    }
    return this->real <= other.real;
}
bool ComplexNumber::operator>=(const ComplexNumber& other) const{
    if(this->real == other.real){
        return this->imaginary >= other.imaginary;
    }
    return this->real >= other.real;
}
bool ComplexNumber::operator==(const ComplexNumber& other) const{
    return this->real == other.real && this->imaginary == other.imaginary;
}
bool ComplexNumber::operator!=(const ComplexNumber& other) const{
    return this->real != other.real || this->imaginary != other.imaginary;
}