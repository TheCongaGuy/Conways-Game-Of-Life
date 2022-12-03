#include "Cell.hpp"

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

Cell::Cell(float positionx, float positiony, float widthx, float heighty)
{
	x = positionx;
	y = positiony;

	width = widthx;
	height = heighty;

	rectangleShape = sf::RectangleShape(sf::Vector2f(widthx, heighty));
	rectangleShape.setPosition(positionx, positiony);
}

sf::RectangleShape Cell::cellShape()
{ 
	return rectangleShape; 
}

void Cell::drawCell(sf::RenderWindow& window)
{
	window.draw(rectangleShape); // Fixed drawing to window : Drew Evensen
}

Cell::~Cell()
{

}

void Cell::setCell(float& newpositionx, float& newpositiony, float& newwidthx, float& newheighty)
{
	x = newpositionx;
	y = newpositiony;

	width = newwidthx;
	height = newheighty;

	rectangleShape.setSize(sf::Vector2f(newwidthx, newheighty));
	rectangleShape.setPosition(newpositionx, newpositiony);
}

