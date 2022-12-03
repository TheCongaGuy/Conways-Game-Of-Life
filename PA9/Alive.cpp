#include "Alive.hpp"
#include "Cell.hpp"

Alive::Alive()
{
	alive = true;
	cellColor = sf::Color(0, 0, 0);

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setFillColor(cellColor);
}

Alive::~Alive() 
{

}

void Alive::setAlive(bool aliveCell)
{
	alive = aliveCell;

	rectangleShape.setFillColor(cellColor);
}

bool Alive::isAlive()
{
	return alive;
}