#pragma once

/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

#include "Alive.hpp"
#include "Dead.hpp"

class Grid
{
public:
	// Constructor
	// Takes the side length of the grid in cells and the window to configure to
	Grid(sf::RenderWindow& window, int sideLength = 1);

	// Destructor - PROBLEM: MEMORY LEAK
	~Grid();

	// Print the grid to the given window
	void printGrid(sf::RenderWindow& window);

	// Processes user input in the form of a hitbox
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
	//Number of cells in each array
	int rowCellCount;
};