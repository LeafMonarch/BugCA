//
// Created by USER on 21/3/2024.
//
#include <iostream>
#ifndef CLASSES_CLOCKTYPE_H
#define CLASSES_CLOCKTYPE_H


class ClockType {
    unsigned int hh, mm, ss;
public:
    ClockType(int hh=0, int mm=0, int ss=0);
    void incrementBySeconds(unsigned int n);
    void incrementByMinutes(unsigned int n);
    void incrementByHours(unsigned int n);
    std::string getCurrentTime() const;
    void displayCurrentTime() const;
    void resetClock();
    void setTime ( unsigned int hh, unsigned int mm, unsigned int ss);

    unsigned int getElapsedTime() const;
    unsigned int getRemainingTime() const;
    std::string getDifference(ClockType &other) const;
};


#endif //CLASSES_CLOCKTYPE_H
