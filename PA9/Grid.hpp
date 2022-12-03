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
	// Takes the number of cells in each x and y direction and the window to configure to
	Grid(sf::RenderWindow& window, int xCells = 1, int yCells = 1);

	// Destructor - PROBLEM: MEMORY LEAK
	~Grid();

	// Getters
	// 2D Cell Array
	Cell**& getCellArray() { return cells; }
	int numXCells() { return xCellsCount; }
	int numYCells() { return yCellsCount; }

	// Print the grid to the given window
	void printGrid(sf::RenderWindow& window);

private:
	// Data Members
	// Dynamic 2D array of cells
	Cell** cells;
	//Number of items in each array
	int yCellsCount;
	int xCellsCount;
	int dividerCount;
	// Dynamic array of rectangles to display to the grid as line dividers
	sf::RectangleShape* dividers;
};