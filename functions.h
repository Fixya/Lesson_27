#pragma once
#include "SFML/Graphics.hpp"

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(batSize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}
void initBall(sf::CircleShape& ball, const sf::Color ballColor, const sf::Vector2f ballPosition)
{
	ball.setRadius(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition(ballPosition);
}

void PText(sf::Text& PText, sf::Font& font, const sf::Vector2f textPosition)
{
	PText.setFont(font);
	PText.setCharacterSize(40);
	PText.setPosition(textPosition);
	
}




/*float leftbatwall(float x, float y)
{
	(x <= midleftx && midleftx <= x + batWidth) && (y <= midlefty && midlefty <= y + batHeight)
}*/