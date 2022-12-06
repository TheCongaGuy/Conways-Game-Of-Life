#pragma once

/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description: This class represents a paper grid of cells which can be alive *
 *				or dead. There are two rules dictating if the cell will change *
 *				state; 1) If a live cell has less than two neighbors or more   *
 *				than three neighbors, it will die. 2) If a dead cell has	   *
 *				exaclty three neighbors, it will become a live cell. In short, *
 *				this class represents the functionality of Conway's Game of	   *
 *				Life.														   *
 *******************************************************************************/

#include "Alive.hpp"
#include "Dead.hpp"

class Grid
{
public:
	// Constructor
	// Takes a reference of the window we are configuring to, and the number of cells on each side
	Grid(sf::RenderWindow& window, int sideLength = 1);

	// Destructor
	~Grid();

	// Print the grid to the given window
	// Takes a reference to the window it is drawing to
	void printGrid(sf::RenderWindow& window);

	// Processes user input in the form of a hitbox
	// Takes a reference of the hitbox to be evaluated
	void processInput(sf::RectangleShape& mouseHitbox);

	// Revives a dead cell or kills a live cell
	// Takes the x and y position of the cell in the 2D array
	void defibCell(int xPos, int yPos);

	// Updates all cells in the array in accordance to Conway's rules
	void update();

private:
	// Data Members
	// Dynamic 2D array of cells
	Cell** cells;
	//Number of cells on each side
	int rowCellCount;
};