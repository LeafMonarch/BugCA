//
// Created by USER on 21/3/2024.
//

#include "DayType.h"

std::string DayType::days[7]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

DayType::DayType():currentDay(0){}

//DayType::DayType(unsigned int currentDay):currentDay(currentDay){
DayType::DayType(unsigned int currentDay){
    if(currentDay>6){
        this->currentDay = 0;
    }
    else
    {
        this->currentDay = currentDay;
    }
}

void DayType::setCurrentDay(unsigned int day) {
    this->currentDay = day%7;
    //between 0 and 6
}

std::string DayType::getCurrentDay() const{
    return days[currentDay];
}
void DayType::printCurrentDay() const{
    std::cout << "The current day is: " << days[currentDay] << std::endl;
}

std::string DayType::getNextDay()  const{
    return days[(currentDay+1)%7];
}

std::string DayType::getPreviousDay() const{
    return days[(currentDay+7-1)%7];
}

std::string DayType::getXdaysInFuture(unsigned int x) const{
    return days[(currentDay+x)%7];
}
