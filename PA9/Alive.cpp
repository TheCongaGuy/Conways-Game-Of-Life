/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description: This file contains functions to set a cell on the grid to alive*															   *
 *******************************************************************************/

#include "Alive.hpp"
#include "Cell.hpp"

//constructor to set alive to true and set the color of the cell
Alive::Alive()
{
	live = true;
	cellFillColor = sf::Color(205, 205, 205);

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setFillColor(cellFillColor);
}

//deconstructor
Alive::~Alive() 
{

}

//setters to set a cell to alive
void Alive::setAlive(bool aliveCell)
{
	live = aliveCell;

	rectangleShape.setFillColor(cellFillColor);
}

//confirm the cell is alive
bool Alive::isAlive()
{
	return live;
}