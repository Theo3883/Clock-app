#include "Button.h"
Button::Button(float x, float y, float width,float height, std::string text,sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	font.loadFromFile("Coconut.ttf");
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);
	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setCharacterSize(12);
	this->buttonState = btn_idle;
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->text.setFillColor(this->idleColor);
	this->text.setOrigin(this->shape.getPosition().x, this->shape.getPosition().y);
	this->text.setPosition((this->shape.getPosition().x + this->shape.getGlobalBounds().width) / 2.f,
		(this->shape.getPosition().y + this->shape.getGlobalBounds().height )/ 2.f);
}
void Button::render(sf::RenderWindow& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
void Button::update(sf::Vector2f mousePos)
{
	this->buttonState = btn_idle;
	std::cout << shape.getPosition().x<<" "<< shape.getPosition().y <<'\n';
	if ((this->shape.getPosition().x < mousePos.x && mousePos.x < this->shape.getPosition().x + this->shape.getGlobalBounds().width )
		&& (this->shape.getPosition().y > mousePos.y && mousePos.y < this->shape.getPosition().y + this->shape.getGlobalBounds().height ))
	{
		this->buttonState = btn_hover;
		std::cout << "da";
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			system("CLS");
			this->buttonState = btn_pressed;
		}
	}
	switch (this->buttonState)
	{
	case btn_idle:
		this->shape.setFillColor(this->idleColor);
		break;
	case btn_hover:
		this->shape.setFillColor(this->hoverColor);
		std::cout << "aici e";
		break;
	case btn_pressed:
		this->shape.setFillColor(sf::Color::Magenta);
		break;
	}
}
void Button::testfunction()
{
	std::cout << this->buttonState << '\n';
	system("CLS");
}