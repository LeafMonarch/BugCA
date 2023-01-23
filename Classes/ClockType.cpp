//
// Created by USER on 21/3/2024.
//

#include "ClockType.h"
ClockType::ClockType(int hh, int mm, int ss){
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
}
void ClockType::incrementBySeconds(unsigned int n){
    this->ss += n;
    if(this->ss>=60){
        incrementByMinutes(this->ss/60);
        this->ss = this->ss%60;
    }
}
void ClockType::incrementByMinutes(unsigned int n){
    this->mm += n;
    if(this->mm>=60){
        incrementByHours(this->mm/60);
        this->mm = this->mm%60;
    }
}
void ClockType::incrementByHours(unsigned int n){
    this->hh = (this->hh+n)%24;
}
std::string ClockType::getCurrentTime() const{
    return std::to_string(hh) + ":" + std::to_string(mm) + ":" + std::to_string(ss);
    //ask why to_string
}

void ClockType::displayCurrentTime() const {
    std::cout << getCurrentTime() << std::endl;
}

void ClockType::resetClock() {
    hh = mm = ss = 0;
}

void ClockType::setTime(unsigned int hh, unsigned int mm, unsigned int ss){
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
}

unsigned int ClockType::getElapsedTime() const{
    return (hh*3600) + (mm*60) + ss;
}
unsigned int ClockType::getRemainingTime() const{
    return 86400 - getElapsedTime();
}
std::string ClockType::getDifference(ClockType &other) const{
    unsigned int diff = abs(getElapsedTime()-other.getElapsedTime());
    int h = diff/3600;
    int m = (diff%3600)/60;
    int s = diff%60;
    return std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);
}