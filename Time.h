//#pragma once
#include <string>
class Clock {
private:
    int hour, minute, second;
public:
    Clock();
    void update();
    void showTime();
    std::string getter();
    int minutes();
    int seconds();
    int hours();
};