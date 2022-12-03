#include "Dead.hpp"

Dead::Dead()
{
	dead = false;
	cellColor = sf::Color(255, 0, 0);
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