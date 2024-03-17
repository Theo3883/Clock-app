#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include<windows.h>
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
class CClock {
private:
    int radius;
    int xsize;
    int ysize;
    const int HOUR_HAND_LENGTH = 60;
    const int MINUTE_HAND_LENGTH = 80;
    const int SECOND_HAND_LENGTH = 100;
public:
    CClock(int CLOCK_RADIUS, int sizex, int sizey);
    void clockface(sf::RenderWindow& window);
    void numbers(sf::RenderWindow& window);
    void hour(sf::RenderWindow& window,Clock& time);
    void minute(sf::RenderWindow& window, Clock& time);
    void second(sf::RenderWindow& window, Clock& time);
};