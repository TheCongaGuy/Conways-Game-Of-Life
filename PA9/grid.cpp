#include "Grid.hpp"

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

// Constructor
// Takes a reference of the window we are configuring to, and the number of cells on each side
Grid::Grid(sf::RenderWindow& window, int sideLength)
{
	// Ensure x and y are valid values
	if (sideLength < 1)
		sideLength = 1;

	// Set default cell color
	playerColor = sf::Color(205, 205, 205);

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
		std::fill(cells[y], cells[y] + sideLength, Dead());
}

// Destructor
Grid::~Grid()
{
	// Delete every subarray of cells
	for (int i = 0; i < rowCellCount; i++)
		delete[] cells[i];

	// Delete the array containing the subarrays
	delete[] cells;
}

// Sets the player's cell color to a new color
// Takes a reference to a sfml color
void Grid::setPlayerColor(sf::Color newColor)
{
	playerColor = newColor;
}

// Print the grid to the given window
// Takes a reference to the window it is drawing to
void Grid::printGrid(sf::RenderWindow& window)
{
	// Loop through each cell in the grid
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
		{
			// Calculate the position each cell needs to be in
			float shiftX = x * ((float)window.getSize().x / rowCellCount);
			float shiftY = y * ((float)window.getSize().x / rowCellCount);
			float length = (float)window.getSize().x / rowCellCount;

			// Shift the cell
			cells[x][y].setCell(shiftX, shiftY, length, length);

			// Set the cell to the player's color
			if (cells[x][y].getState())
				cells[x][y].setPlayerColor(playerColor);

			// Draw the cell
			cells[x][y].drawCell(window);
		}
}

// Processes user input in the form of a hitbox
// Takes a reference of the hitbox to be evaluated
void Grid::processInput(sf::RectangleShape& mouseHitbox)
{
	// Loop through each cell
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
			// If the cell is hit by the given hitbox, defib the cell and stop iterating
			if (cells[x][y].cellShape().getGlobalBounds().intersects(mouseHitbox.getGlobalBounds()))
			{
				defibCell(x, y);
				return;
			}
}

// Revives a dead cell or kills a live cell
// Takes the x and y position of the cell in the 2D array
void Grid::defibCell(int xPos, int yPos)
{
	// Set the cell to it's opposite state
	cells[xPos][yPos].getState() ? cells[xPos][yPos] = Dead() : cells[xPos][yPos] = Alive();
}

// Updates all cells in the array in accordance to Conway's rules
void Grid::update()
{
	// Instantiate an array to store the current cell's neigbors
	bool neighbors[9];
	std::fill(neighbors, neighbors + 9, false);

	// Instantiate an array to store each cell that needs to be changed
	bool* defibCells = new bool[rowCellCount * rowCellCount];
	std::fill(defibCells, defibCells + (rowCellCount * rowCellCount), false);

	// A counter to keep track of what cell we are on
	int curCell = 0;

	// Iterate through each cell in the grid
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
		{
			// A counter to keep track of what neighbor we are on
			int curNeighbor = 0;

			// Iterate through each neighbor on a 3x3 grid centered on the current cell
			for (int yShift = -1; yShift <= 1; yShift++)
				for (int xShift = -1; xShift <= 1; xShift++)
				{
					// Update the neighbor array with the state of the current neighbor cell
					if (x + xShift >= 0 && x + xShift < rowCellCount && y + yShift >= 0 && y + yShift < rowCellCount)
						neighbors[curNeighbor] = cells[x + xShift][y + yShift].getState();
					else
						neighbors[curNeighbor] = false;

					// Iterate through the neighbor array
					curNeighbor++;
				}

			// Calculate total neighbors
			int total = 0;
			for (int i = 0; i < 9; i++)
				if (neighbors[i])
					total++;

			// Update the current cell based on the state of the neighborhood
			if (neighbors[4])
			{
				// Remove one from the total to account for the current cell being alive
				total--;

				// Kill the cell if and only if there aren't two or three neighbors
				if (total < 2 || total > 3)
					defibCells[curCell] = true;

				// Continue to the next cell
				curCell++;
			}
			else
			{
				// Revive the cell if and only if there are exactly three neighbors
				if (total == 3)
					defibCells[curCell] = true;

				// Continue to the next cell
				curCell++;
			}
		}

	// Reset the curCell counter
	curCell = 0;

	// Iterate through each cell on the grid
	for (int y = 0; y < rowCellCount; y++)
		for (int x = 0; x < rowCellCount; x++)
		{
			// If the cell has been flagged for change, defib the cell
			if (defibCells[curCell])
				defibCell(x, y);

			// Continue through the defib array
			curCell++;
		}

	// Delete the dynamic array
	delete[] defibCells;
}