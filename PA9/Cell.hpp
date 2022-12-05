#pragma once

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:	This file contains functions that set up the cell shape and	   *
 * allows to to set and get a dead or alive cell.							   *
 *******************************************************************************/

#include <SFML/Graphics.hpp> // External Library

class Cell
{
public:

	//constructor
	Cell(float positionx = 0.f, float positiony = 0.f, float widthx = 1.f, float heighty = 1.f);

	//deconstructor
	~Cell();


	//a setter to allow you to set the position, width and height of a cell in the grid
	void setCell(float &positionx, float &positiony, float &widthx, float &heighty);

	//virtual void cellColor();  <- Throwing Linker Errors : Drew Evensen

	void drawCell(sf::RenderWindow& window);

	sf::RectangleShape cellShape();

	//sf::RectangleShape cellColor(); //ended up not using this functiona dn just ssetting the colors within alive and dead constructors

protected:

	//inherited in alive and dead classes
	sf::RectangleShape rectangleShape;

	sf::Color cellFillColor;

	sf::Color cellOutlineColor;

	bool live;


private:
	int cell;
	//to position the cell
	int x;
	int y;

	int width;
	int height;

};