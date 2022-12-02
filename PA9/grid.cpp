#include "Grid.hpp"

/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

// Constructor
Grid::Grid(int xCells, int yCells)
{
	// Ensure x and y are valid values
	if (xCells < 1)
		xCells = 1;
	if (yCells < 1)
		yCells = 1;

	// Record number of cells
	collumnCellsCount = yCells;
	rowCellsCount = xCells;

	// Source: https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/
	// Instantiate each collumn in the grid
	cells = new Cell*[yCells];

	// Instantiate each row in the grid
	for (int i = 0; i < xCells; i++)
		cells[i] = new Dead[xCells];

	// Calculate number of dividers needed
	dividerCount = xCells + yCells - 2;

	// Instantiate dividers
	dividers = new sf::RectangleShape[dividerCount];
	int i = 0;
	// Horizontal dividers
	for (; i < yCells - 1; i++)
	{
		dividers[i] = sf::RectangleShape(sf::Vector2f(500, 1));
		dividers[i].move(0, (500.f/yCells) * (i + 1));
	}
	// Vertical dividers
	for (int j = 0; j < xCells - 1; j++)
	{
		dividers[j + i] = sf::RectangleShape(sf::Vector2f(1, 500));
		dividers[j + i].move((500.f/xCells) * (j + 1), 0);
	}
}

// Destructor - PROBLEM: MEMORY LEAK
Grid::~Grid()
{

}

// Print the grid to the given window
void Grid::printGrid(sf::RenderWindow& window)
{
	// Draw each divider
	for (int i = 0; i < dividerCount; i++)
		window.draw(dividers[i]);
}

