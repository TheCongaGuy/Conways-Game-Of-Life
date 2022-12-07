/*******************************************************************************
 * Programmers: Drew Evensen, Kaitlyn Cornish                                  *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

//#include "Test.hpp"
#include "Grid.hpp"
#include <iostream> // std::cout
#include <time.h> // clock(), difftime()

int main(int argc, char argv[])
{
#pragma region Test Cases
	//graphicsTest();
	//printGridTest();
	//printCellTest();
	//userInputTest();
	//simulationTest();
	//runGameTest();
#pragma endregion

	// Controls the state of the game
	bool run = false;

	// Logs the mouse's x and y coordinates
	int x = 0;
	int y = 0;
	// Controls the button's position
	float buttonX = 240; 
	float buttonY = 820;

	// Delta-Time to ensure a smooth simulation across all machines
	time_t deltaTime = clock();

	// Window for gameplay
	sf::RenderWindow window(sf::VideoMode(770, 1000), "Conway's Game of Life");

	// Grid for game to take place in
	Grid game(window, 25);

	// Color Selection for Player
	sf::RectangleShape colors[4];
	std::fill(colors, colors + 4, sf::RectangleShape(sf::Vector2f(60, 60)));

	// Button to control flow of the simulation
	sf::RectangleShape button(sf::Vector2f(308, 193));
	button.setFillColor(sf::Color::Green);
	sf::Font textFont;
	// Hitbox for the mouse click
	sf::RectangleShape mouseClick(sf::Vector2f(1.f, 1.f));

	// Set up the button before start
	textFont.loadFromFile("block.ttf");
	sf::Text playText("Play", textFont, 46);
	playText.setFillColor(sf::Color(25, 25, 25));
	sf::Text pauseText("Pause", textFont, 46);
	pauseText.setFillColor(sf::Color(205, 205, 205));

	// Shift the button down to the bottom of the screen before runtime
	button.setPosition(buttonX, buttonY);
	playText.setPosition(buttonX, buttonY);
	pauseText.setPosition(buttonX + 77, buttonY + 135);

	// Set up color selection buttons
	colors[0].setFillColor(sf::Color(205, 205, 205)); // Default White
	colors[0].setOutlineColor(sf::Color(3, 150, 98));
	colors[0].setOutlineThickness(2);
	colors[1].setFillColor(sf::Color(2, 70, 42)); // Dark Green
	colors[2].setFillColor(sf::Color(139, 0, 0)); // Dark Red
	colors[3].setFillColor(sf::Color(0, 0, 139)); // Dark Blue

	// Move color selection buttons to the correct spot
	colors[0].setPosition(60, 800);
	colors[1].setPosition(60, 900);
	colors[2].setPosition(650, 800);
	colors[3].setPosition(650, 900);

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
				game.processInput(mouseClick);

				// Play Button Check
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

				// Color Selection Check
				for (int i = 0; i < 4; i++)
					if (colors[i].getGlobalBounds().intersects(mouseClick.getGlobalBounds()))
					{
						// Set the players color to the selected button's color
						game.setPlayerColor(colors[i].getFillColor());
						pauseText.setFillColor(colors[i].getFillColor());
						colors[i].setOutlineColor(sf::Color(2, 100, 64));
						colors[i].setOutlineThickness(2);

						// Remove highlight showing which button was selected
						for (int j = 0; j < 4; j++)
							if (j != i)
								colors[j].setOutlineThickness(0);

						break;
					}
			}
		}

		window.clear();

		// Display the grid
		game.printGrid(window);
		// Display the button with correct text
		window.draw(button);
		run ? window.draw(pauseText) : window.draw(playText);
		// Display color choices
		for (int i = 0; i < 4; i++)
			window.draw(colors[i]);

		window.display();

		// Only update every 250 milliseconds
		if (difftime(clock(), deltaTime) >= 250 && run)
		{
			game.update();
			deltaTime = clock();
		}
	}

	return 0;
}
