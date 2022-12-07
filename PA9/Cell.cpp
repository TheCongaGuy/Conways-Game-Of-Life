#include "Cell.hpp"

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:	This file contains functions that set up the cell shape and    *
 *				allows to to set and get a dead or alive cell.				   *
 *******************************************************************************/


//constructor to et up the cell shape and position
Cell::Cell(float positionx, float positiony, float widthx, float heighty)
{
	x = positionx;
	y = positiony;

	width = widthx;
	height = heighty;

	rectangleShape.setSize(sf::Vector2f(widthx, heighty));
	rectangleShape.setPosition(positionx, positiony);
}

//returns the shape of the cell
sf::RectangleShape Cell::cellShape()
{ 
	return rectangleShape; 
}

//draws the cells to the window
void Cell::drawCell(sf::RenderWindow& window)
{
	window.draw(rectangleShape); // Fixed drawing to window : Drew Evensen
}

//deconstructor
Cell::~Cell()
{

}

// Method to get the state of the cell
// Returns true if the cell is alive, false otherwise
// Programmer: Drew Evensen
bool Cell::getState()
{
	return live;
}

sf::RectangleShape setPlayerColor(sf::Color newFillColor)
{
	sf::Color cellFillColor = newFillColor;
}

//allows you to set the position, height and width of the cell in the grid
void Cell::setCell(float& newpositionx, float& newpositiony, float& newwidthx, float& newheighty)
{
	x = newpositionx;
	y = newpositiony;

	width = newwidthx;
	height = newheighty;

	rectangleShape.setSize(sf::Vector2f(newwidthx, newheighty));
	rectangleShape.setPosition(newpositionx, newpositiony);
}


