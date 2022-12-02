#include "Alive.hpp"
#include "Cell.hpp"

Alive::Alive()
{
	alive = true;
}

Alive::~Alive() 
{

}

void Alive::setAlive(bool aliveCell)
{
	alive = aliveCell;

	rectangleShape.setFillColor(aliveColor);
}

bool Alive::isAlive()
{
	return alive;
}