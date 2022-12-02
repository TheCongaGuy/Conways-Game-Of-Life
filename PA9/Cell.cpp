#include "Cell.hpp"

Cell::Cell(float positionx, float positiony, float widthx, float heighty)
{
	x = positionx;
	y = positiony;

	width = widthx;
	height = heighty;

	rectangleShape = sf::RectangleShape(sf::Vector2f(widthx, heighty));
	rectangleShape.setPosition(positionx, positiony);

	rectangleShape.setOutlineThickness(2);
	rectangleShape.setOutlineColor(sf::Color(255, 0, 0));
}

sf::RectangleShape Cell::cellShape()
{ 
	return rectangleShape; 
}

void Cell::drawCell(sf::RenderWindow& window)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			window.draw();
		}
	}
}

Cell::~Cell()
{

}