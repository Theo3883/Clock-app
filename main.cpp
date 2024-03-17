#include "SFML/Graphics.hpp"
#include "Time.h";
#include <iostream>
#include <string>
#include<windows.h>

int main()
{
    Clock time;
    const int CLOCK_RADIUS = 150;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "App");
    sf::Texture texture;
    if (!texture.loadFromFile("background.jpg"))
        return -1;
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("Coconut.ttf"))
    {
        std::cout << "Font error";
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(time.getter()); 
    text.setCharacterSize(60); 
    text.setFillColor(sf::Color::Red); 

    // center the origin
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);

    // set the position to the center of the window
    text.setPosition(sf::Vector2f(window.getSize().x / 4.5f, window.getSize().y / 3.0f));

    CClock watch(CLOCK_RADIUS,window.getSize().x, window.getSize().y);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        //drow the clock
        watch.clockface(window);
        watch.numbers(window);
        watch.hour(window, time);
        watch.minute(window, time);
        watch.second(window, time);

        text.setString(time.getter());
        time.update();
        //Sleep(1000);
        window.draw(text);
        window.display();
        //std::cout<<time.getter()<<'\n';
    }

    return 0;
}

/*#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int CLOCK_RADIUS = 150;
const int HOUR_HAND_LENGTH = 60;
const int MINUTE_HAND_LENGTH = 80;
const int SECOND_HAND_LENGTH = 100;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Clock");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Get current time
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int hours = ltm->tm_hour % 12; // Convert to 12-hour format
        int minutes = ltm->tm_min;
        int seconds = ltm->tm_sec;

        // Draw clock face
        sf::CircleShape clockFace(CLOCK_RADIUS);
        clockFace.setFillColor(sf::Color::White);
        clockFace.setOutlineThickness(2);
        clockFace.setOutlineColor(sf::Color::Black);
        clockFace.setOrigin(CLOCK_RADIUS, CLOCK_RADIUS);
        clockFace.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        window.draw(clockFace);

        // Draw hour indicators
        sf::Font font;
        font.loadFromFile("arial.ttf"); // Replace with your font path
        for (int i = 0; i < 12; ++i) {
            sf::Text text(std::to_string(i + 1), font, 24);
            text.setFillColor(sf::Color::Black);
            text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
            float angle = (i-2) * (360 / 12) * (3.14159265359 / 180); // Convert degrees to radians
            float x = WINDOW_WIDTH / 2 + (CLOCK_RADIUS - 20) * cos(angle);
            float y = WINDOW_HEIGHT / 2 + (CLOCK_RADIUS - 20) * sin(angle);
            text.setPosition(x, y);
            window.draw(text);
        }

        // Draw hour hand
        sf::RectangleShape hourHand(sf::Vector2f(HOUR_HAND_LENGTH, 4));
        hourHand.setFillColor(sf::Color::Black);
        hourHand.setOrigin(0, 2);
        hourHand.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        hourHand.rotate((hours * 30) + (minutes * 0.5)); // 30 degrees per hour, 0.5 degrees per minute
        window.draw(hourHand);

        // Draw minute hand
        sf::RectangleShape minuteHand(sf::Vector2f(MINUTE_HAND_LENGTH, 4));
        minuteHand.setFillColor(sf::Color::Black);
        minuteHand.setOrigin(0, 2);
        minuteHand.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        minuteHand.rotate(minutes * 6); // 6 degrees per minute
        window.draw(minuteHand);

        // Draw second hand
        sf::RectangleShape secondHand(sf::Vector2f(SECOND_HAND_LENGTH, 2));
        secondHand.setFillColor(sf::Color::Red);
        secondHand.setOrigin(0, 1);
        secondHand.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        secondHand.rotate(seconds * 6); // 6 degrees per second
        window.draw(secondHand);

        window.display();
    }

    return 0;
}*/

