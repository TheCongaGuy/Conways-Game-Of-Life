#include "Dead.hpp"

Dead::Dead()
{
	dead = false;
	cellFillColor = sf::Color(25, 25, 25);
	rectangleShape.setOutlineColor(sf::Color(255, 255, 255));

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setFillColor(cellFillColor);
}

Dead::~Dead()
{

}

void Dead::setDead(bool deadCell)
{
	dead = deadCell;

	rectangleShape.setFillColor(cellFillColor);
}

bool Dead::isDead()
{
	return dead;
}