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
Grid::Grid(sf::RenderWindow& window, int sideLength)
{
	// Ensure x and y are valid values
	if (sideLength < 1)
		sideLength = 1;

	// Record number of cells
	rowCellCount = sideLength;

	// Source: https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/
	// Instantiate each collumn in the grid
	cells = new Cell*[sideLength];

	// Instantiate each row in the grid
	for (int i = 0; i < sideLength; i++)
		cells[i] = new Cell[sideLength];

	// Fill the new 2D array with dead cells
	for (int y = 0; y < sideLength; y++)
		for (int x = 0; x < sideLength; x++)
			cells[x][y] = Dead();
}

// Destructor - PROBLEM: MEMORY LEAK
Grid::~Grid()
{

}

// Print the grid to the given window
void Grid::printGrid(sf::RenderWindow& window)
{
	// Loop through the entire 2D array
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
		{
			// Calculate the position each cell needs to be in
			float shiftX = x * ((window.getSize().x) / (rowCellCount));
			float shiftY = y * ((window.getSize().x) / (rowCellCount));
			float lengthX = ((window.getSize().x) / (rowCellCount));
			float lengthY = ((window.getSize().x) / (rowCellCount));

			// Shift the cell
			cells[x][y].setCell(shiftX, shiftY, lengthX, lengthY);

			// Draw the cell
			cells[x][y].drawCell(window);
		}
}

// Processes user input in the form of a hitbox
void Grid::processInput(sf::RectangleShape& mouseHitbox)
{
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
		{
			if (cells[x][y].cellShape().getGlobalBounds().intersects(mouseHitbox.getGlobalBounds()))
			{
				defibCell(x, y);
			}
		}
}

// Revives a dead cell or kills a live cell
// Takes the x and y position of the cell in the 2D array
void Grid::defibCell(int xPos, int yPos)
{
	if (cells[xPos][yPos].getState())
		cells[xPos][yPos] = Dead();
	else
		cells[xPos][yPos] = Alive();
}

// Updates all cells in the array in accordance to Conway's rules
void Grid::update()
{
	// Instantiate an array to store the current cell's neigbors and an array to store which cells need to be changed
	bool neighbors[9];
	bool* defibCells = new bool[rowCellCount * rowCellCount];
	for (int i = 0; i < rowCellCount * rowCellCount; i++)
		defibCells[i] = false;
	int curCell = 0;

	// Check each cell's neighbors with x and y being the target cell
	for (int y = 0; y < rowCellCount; y++)
	{
		for (int x = 0; x < rowCellCount; x++)
		{
			int curNeighbor = 0;

			for (int yShift = -1; yShift <= 1; yShift++)
			{
				for (int xShift = -1; xShift <= 1; xShift++)
				{
					if (x + xShift >= 0 && x + xShift < rowCellCount && y + yShift >= 0 && y + yShift < rowCellCount)
						neighbors[curNeighbor] = cells[x + xShift][y + yShift].getState();
					else
						neighbors[curNeighbor] = false;

					curNeighbor++;
				}
			}

			// Calculate total neighbors
			int total = 0;
			for (int i = 0; i < 9; i++)
				if (neighbors[i])
					total++;

			// Update the center cell based on the state of the neighborhood
			if (neighbors[4])
			{
				total--;
				if (total < 2 || total > 3)
					defibCells[curCell] = true;
				curCell++;
			}
			else
			{
				if (total == 3)
					defibCells[curCell] = true;
				curCell++;
			}
		}
	}

	curCell = 0;
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
		{
			if (defibCells[curCell])
				defibCell(x, y);
			curCell++;
		}

	delete defibCells;
}