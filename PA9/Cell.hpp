#pragma once

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
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
	Cell(float positionx = 0.f, float positiony = 0.f, float widthx = 1.f, float heighty = 1.f);

	//deconstructor
	~Cell();



	void setCell(float &positionx, float &positiony, float &widthx, float &heighty);

	//virtual void cellColor();  <- Throwing Linker Errors : Drew Evensen

	void drawCell(sf::RenderWindow& window);

	sf::RectangleShape cellShape();

	//sf::RectangleShape cellColor();

protected:
	sf::RectangleShape rectangleShape;

	sf::Color cellFillColor;

	sf::Color cellOutlineColor;


private:
	int cell;

	int x;
	int y;

	int width;
	int height;

};