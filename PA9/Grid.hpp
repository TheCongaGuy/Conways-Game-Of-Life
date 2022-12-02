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
	// Takes the number of cells in each x and y direction
	Grid(int xCells = 1, int yCells = 1);

	// Destructor - PROBLEM: MEMORY LEAK
	~Grid();

	// Print the grid to the given window
	void printGrid(sf::RenderWindow& window);

private:
	// Data Members
	// Dynamic 2D array of cells
	Cell** cells;
	//Number of items in each array
	int collumnCellsCount;
	int rowCellsCount;
	int dividerCount;
	// Array of rectangles to display the grid as line dividers
	sf::RectangleShape* dividers;
};