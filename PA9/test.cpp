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
	memset(test, 0, 30);

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

	// Create new test window       (Size of Window)        (Title of Window)
	sf::RenderWindow testWindow(sf::VideoMode(1200, 500), "Selection Sort Test");
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

			// Mark each rectangle green when sorted
			if (b == 30)
				items[i].setFillColor(sf::Color::Green);

			// Mark each changed rectangle red
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
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Grid Test");
	Grid test(window, 10);

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

void printCellTest()
{
	Cell test(450, 450, 100, 100);
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Cell Test");

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

// Test function gets user input via clicks of a mouse and finds the correct cell they clicked on
// Programmers: Drew Evensen
void userInputTest()
{
	// Instantiate new test grid and window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Input Test");
	Grid test(window, 10);

	// Instantiate a hitbox for the mouse click
	sf::RectangleShape mouseClick(sf::Vector2f(1.f, 1.f));

	// Global variables to log the mouse's x and y coordinates
	int x = 0;
	int y = 0;

	while (window.isOpen())
	{
		// Catches events in the window
		sf::Event event;

		while (window.pollEvent(event))
		{
			// Close the window upon clicking the X
			if (event.type == sf::Event::Closed)
				window.close();

			// When the mouse is clicked
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// Get it's local coordinate position
				x = sf::Mouse::getPosition(window).x;
				y = sf::Mouse::getPosition(window).y;

				// Set the hitbox to the mouse's position
				mouseClick.setPosition((float)x, (float)y);

				// Check for intersection
				test.processInput(mouseClick);
			}
		}

		// Display the grid
		window.clear();
		test.printGrid(window);
		window.display();
	}
}

// Test function runs through a preset simulation without user input
// Programmers: Drew Evensen
void simulationTest()
{
	// Time object to set up a delta-time system
	time_t deltaTime = clock();

	// Instantiate a new test grid and window
	sf::RenderWindow window(sf::VideoMode(1300, 1300), "Simulation Test");
	Grid test(window, 36);

	// Set up initial grid configuration
#pragma region Glider Gun
	// Left Boundry
	test.defibCell(0, 14);
	test.defibCell(0, 13);
	test.defibCell(1, 14);
	test.defibCell(1, 13);
	// Right Boundry
	test.defibCell(35, 12);
	test.defibCell(35, 11);
	test.defibCell(34, 12);
	test.defibCell(34, 11);
	// Left Component
	test.defibCell(10, 13);
	test.defibCell(10, 14);
	test.defibCell(10, 15);
	test.defibCell(11, 12);
	test.defibCell(11, 16);
	test.defibCell(12, 11);
	test.defibCell(13, 11);
	test.defibCell(12, 17);
	test.defibCell(13, 17);
	test.defibCell(14, 14);
	test.defibCell(15, 12);
	test.defibCell(15, 16);
	test.defibCell(16, 13);
	test.defibCell(16, 14);
	test.defibCell(16, 15);
	test.defibCell(17, 14);
	// Right Component
	test.defibCell(20, 11);
	test.defibCell(20, 12);
	test.defibCell(20, 13);
	test.defibCell(21, 11);
	test.defibCell(21, 12);
	test.defibCell(21, 13);
	test.defibCell(22, 10);
	test.defibCell(22, 14);
	test.defibCell(24, 9);
	test.defibCell(24, 10);
	test.defibCell(24, 14);
	test.defibCell(24, 15);
#pragma endregion

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

		// Only update every 250 milliseconds
		if (difftime(clock(), deltaTime) >= 250)
		{
			test.update();
			deltaTime = clock();
		}
	}
}

// Test function runs an example game, waiting until the user places a set number of cells to begin the simulation
// Programmers: Drew Evensen
void runGameTest()
{
	// Bool to control state of the game
	bool run = false;

	// Time object to set up a delta-time system
	time_t deltaTime = clock();

	// Instantiate new test grid, window, start button, and font
	sf::RenderWindow window(sf::VideoMode(1000, 1300), "Game Test");
	Grid test(window, 20);
	sf::RectangleShape button(sf::Vector2f(400, 250));
	button.setFillColor(sf::Color::Green);

	// Instantiate a hitbox for the mouse click
	sf::RectangleShape mouseClick(sf::Vector2f(1.f, 1.f));

	// Global variables to log the mouse's x and y coordinates
	int x = 0;
	int y = 0;

	// Shift the button down to the bottom of the screen
	int buttonX = 300, buttonY = 1025;
	button.setPosition(buttonX, buttonY);

	while (window.isOpen())
	{
		// Catches events in the window
		sf::Event event;

		while (window.pollEvent(event))
		{
			// Close the window upon clicking the X
			if (event.type == sf::Event::Closed)
				window.close();

			// When the mouse is clicked
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// Get it's local coordinate position
				x = sf::Mouse::getPosition(window).x;
				y = sf::Mouse::getPosition(window).y;

				// Set the hitbox to the mouse's position
				mouseClick.setPosition((float)x, (float)y);

				// Check for intersections
				test.processInput(mouseClick);

				if (button.getGlobalBounds().intersects(mouseClick.getGlobalBounds()))
				{
					if (run)
					{
						run = false;
						button.setFillColor(sf::Color::Green);
					}
					else
					{
						run = true;
						button.setFillColor(sf::Color::Red);
					}
				}
			}
		}

		// Display the grid
		window.clear();
		test.printGrid(window);
		window.draw(button);
		window.display();

		// Only update every 250 milliseconds
		if (difftime(clock(), deltaTime) >= 250 && run)
		{
			test.update();
			deltaTime = clock();
		}
	}
}