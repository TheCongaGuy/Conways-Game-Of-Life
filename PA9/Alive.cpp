#include "Alive.hpp"
#include "Cell.hpp"

Alive::Alive()
{
	alive = true;
	cellFillColor = sf::Color(0, 0, 0);

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setFillColor(cellFillColor);
}

Alive::~Alive() 
{

}

void Alive::setAlive(bool aliveCell)
{
	alive = aliveCell;

	rectangleShape.setFillColor(cellFillColor);
}

bool Alive::isAlive()
{
	return alive;
}