#include "Dead.hpp"

Dead::Dead()
{
	dead = false;
	cellColor = sf::Color(25, 25, 25);
	rectangleShape.setOutlineColor(sf::Color(255, 255, 255));

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setFillColor(cellColor);
}

Dead::~Dead()
{

}

void Dead::setDead(bool deadCell)
{
	dead = deadCell;

	rectangleShape.setFillColor(cellColor);
}

bool Dead::isDead()
{
	return dead;
}