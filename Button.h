#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
enum button_state{btn_idle=0 , btn_hover,btn_pressed};
class Button
{
private:
	button_state buttonState;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
public:
	Button(float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	void render(sf::RenderWindow& target);
	void update(const sf::Vector2f mousePos);
	void testfunction();
};

