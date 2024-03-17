#include "Time.h"
#include <iostream>
#include <ctime>
#include <string>
Clock::Clock() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}
void Clock::update() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}
void Clock::showTime() {
    std::cout << "Time: " << hour << ":" << minute << ":" << second<<" ";
}
std::string Clock::getter()
{
    return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
}
int Clock::minutes()
{
    return minute;
}
int Clock::seconds()
{
    return second;
}
int Clock::hours()
{
    return hour;
}