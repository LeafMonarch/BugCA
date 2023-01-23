//
// Created by USER on 21/3/2024.
//
#include <iostream>
#ifndef CLASSES_DAYTYPE_H
#define CLASSES_DAYTYPE_H


class DayType {
    static std::string days[7];
    int currentDay;
public:
    //unsigned are non negative
    DayType();
    DayType(unsigned int currentDay);
    void setCurrentDay(unsigned int day);
    std::string getCurrentDay() const;
    void printCurrentDay() const;
    std::string getNextDay() const;
    std::string getPreviousDay() const;
    std::string getXdaysInFuture(unsigned int x) const;

};


#endif //CLASSES_DAYTYPE_H
