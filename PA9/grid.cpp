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
Grid::Grid(sf::RenderWindow& window, int xCells, int yCells)
{
	// Ensure x and y are valid values
	if (xCells < 1)
		xCells = 1;
	if (yCells < 1)
		yCells = 1;

	// Record number of cells
	yCellsCount = yCells;
	xCellsCount = xCells;

	// Source: https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/
	// Instantiate each collumn in the grid
	cells = new Cell*[yCells];

	// Instantiate each row in the grid
	for (int i = 0; i < xCells; i++)
		cells[i] = new Cell[xCells];

	// Fill the new 2D array with dead cells
	for (int y = 0; y < yCells; y++)
		for (int x = 0; x < xCells; x++)
			cells[x][y] = Dead();

	// Calculate number of dividers needed
	dividerCount = xCells + yCells - 2;

	// Instantiate dividers
	dividers = new sf::RectangleShape[dividerCount];
	int i = 0;
	// Horizontal dividers
	for (; i < yCells - 1; i++)
	{
		dividers[i] = sf::RectangleShape(sf::Vector2f((float)(window.getSize().x), 1.f));
		dividers[i].move(0, ((float)window.getSize().y / yCells) * (i + 1));
	}
	// Vertical dividers
	for (int j = 0; j < xCells - 1; j++)
	{
		dividers[j + i] = sf::RectangleShape(sf::Vector2f(1.f, (float)(window.getSize().y)));
		dividers[j + i].move(((float)window.getSize().x / xCells) * (j + 1), 0);
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
	
	// Draw each cell
	for (int y = 0; y < yCellsCount; y++)
		for (int x = 0; x < xCellsCount; x++)
		{
			float shiftX = x * (window.getSize().x / (dividerCount / 2));
			float shiftY = y * (window.getSize().x / (dividerCount / 2));
			float lengthX = (window.getSize().x / (dividerCount / 2));
			float lengthY = (window.getSize().x / (dividerCount / 2));

			cells[x][y].setCell(shiftX, shiftY, lengthX, lengthY);

			cells[x][y].drawCell(window);
		}
}

