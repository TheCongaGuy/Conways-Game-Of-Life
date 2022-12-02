#include "Dead.hpp"

Dead::Dead()
{
	dead = false;
}

Dead::Dead()
{

}

void Dead::setDead(bool deadCell)
{
	dead = deadCell;

	rectangleShape.setFillColor(deadColor);
}

bool Dead::isDead()
{
	return dead;
}