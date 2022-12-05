/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description: This file contains functions to set a cell on the grid to dead.*														   *
 *******************************************************************************/

#include "Dead.hpp"
#include "Cell.hpp"


//contructor to set up the dead cell
Dead::Dead()
{
	live = false;
	cellFillColor = sf::Color(25, 25, 25);
	rectangleShape.setOutlineColor(sf::Color(255, 255, 255));

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setFillColor(cellFillColor);
}


//deconstructor
Dead::~Dead()
{

}

//setter to allow the cells to be set to dead
void Dead::setDead(bool deadCell)
{
	live = deadCell;

	rectangleShape.setFillColor(cellFillColor);
}

//confirms whether the cell is alive or dead
bool Dead::isDead()
{
	return live;
}