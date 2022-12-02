#include "Test.hpp"

/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:	File consisting of test methods. Not part of final solution.   *
 *				Used for experimenting and ensuring program works.			   *
 *******************************************************************************/

 // Test function that demonstrates a visualization of selection sort for the purposes of checking and understanding 
 // the graphics library
 // Programmer: Drew Evensen
void graphicsTest()
{
#pragma region Pre-Window Setup
	// Test array
	int test[30];

	// Iterator for selection sort
	int b = 0, bMin = 0;

	// Set a new seed for rand()
	srand((unsigned)time(NULL));

	// Create an array of 30 random integers
	for (int i = 0; i < 30; i++)
		test[i] = rand() % 500 + 1;

	// Display the starting array
	std::cout << "Test Array Initialized. Starting Config:" << std::endl;
	for (int i = 0; i < 30; i++) std::cout << test[i] << ", ";

	// Array of SFML rectangle objects to print to the screen
	sf::RectangleShape items[30];

	// Create new test window       (Size of Window)               (Title of Window)
	sf::RenderWindow testWindow(sf::VideoMode(1200, 500), "Selection Sort Algorithm Example");
#pragma endregion

#pragma region Window Open
	// Run while the window is open
	while (testWindow.isOpen())
	{
	#pragma region Event Manager
		// Catches an event in the window
		sf::Event event;

		// Close the window upon clicking the X
		while (testWindow.pollEvent(event))

			if (event.type == 0) // Equivalent to if statement below
		 // if (event.type == sf::Event::Closed)
		 // sf::Event::Closed is an enum with position 0, I.E. sf::Event::Closed == 0

				testWindow.close();
	#pragma endregion

	#pragma region Selection Sort
		// Iterate a step through selection sort
		if (b < 30)
		{
			bMin = b;
			for (int i = b; i < 30; i++)
				if (test[i] < test[bMin])
					bMin = i;

			int temp = test[b];
			test[b] = test[bMin];
			test[bMin] = temp;

			b++;
		}
	#pragma endregion

	#pragma region Graphics Manager
		// Create each rectangle item
		for (int i = 0; i < 30; i++)
		{
			// SFML Rectangle takes a SFML Vector 2, meaning a pair of 2 floating point numbers; the pixel width and length
			items[i] = sf::RectangleShape(sf::Vector2f(40.f, (float)test[i]));
			// SFML Rectangle member function setFillColor takes a static constant Color for the requested color
			// Can find available colors under the sf::Color class
			items[i].setFillColor(sf::Color::White);
			// SFML Rectangle member function setOrigin changes the origin of the image (top left corner of image) to the two given pixel coordinates
			items[i].setOrigin(0.f, test[i] - 500.f);

			// Mark each changed rectangle red
			if (b == 30)
				items[i].setFillColor(sf::Color::Green);

			// Mark each rectangle green when sorted
			else if (bMin == i || b == i)
				items[i].setFillColor(sf::Color::Red);
		}

		// Clear the window
		testWindow.clear();

		// Draw the items to the screen
		for (int i = 0; i < 30; i++)
		{
			// Shift each rectangle to the correct position before drawing
			// SFML Rectangle member function move adds the given pixel values to the rectangle's origin value
			items[i].move(i * 40.f, 0.f);
			testWindow.draw(items[i]);
		}

		// Draw the window
		testWindow.display();

		Sleep(100);
	#pragma endregion
	}
#pragma endregion
}

// Test function prints the grid to the screen
// Programmer: Drew Evensen
void printGridTest()
{
	// Instantiate a new test grid and window
	Grid test(25, 25);
	sf::RenderWindow window(sf::VideoMode(500, 500), "Grid Test");

	while (window.isOpen())
	{
		// Catches events in the window
		sf::Event event;

		// Close the window upon clicking the X
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		// Display the grid
		window.clear();
		test.printGrid(window);
		window.display();
	}
}

void printCell()
{
	Cell test(25, 25, 25, 25);
	sf::RenderWindow window(sf::VideoMode(500, 500), "Grid Test");

	while (window.isOpen())
	{
		// Catches events in the window
		sf::Event event;

		// Close the window upon clicking the X
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		// Display the grid
		window.clear();
		test.drawCell(window);
		window.display();
	}
}