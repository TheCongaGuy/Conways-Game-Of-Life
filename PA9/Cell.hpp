#pragma once

/*******************************************************************************
 * Programmers: ____________		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

#include <SFML/Graphics.hpp> // External Library

class Cell
{
public:

	//constructor
	Cell(float, float, float, float);

	//deconstructor
	~Cell();

	virtual void cellColor();

	void drawCell(sf::RenderWindow& window);

	sf::RectangleShape cellShape();

private:
	sf::RectangleShape rectangleShape;

	int cell;

	int x;
	int y;

	int width = 35;
	int height = 35;

};