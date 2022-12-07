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

	// Info Blerb before Game Start
	std::cout << std::endl << "Conway's game of life is a sandbox with no clear goal except to create interesting patterns" << std::endl
		<< "and experiment with the rules of the game. If you want a few games you can play with someone, here" << std::endl
		<< "are some ideas:" << std::endl;

	std::cout << std::endl << "HOW TO PLAY:" << std::endl
		<< "Before the game starts, left click on any square in the grid to place a cell.If you want to remove a" << std::endl
		<< "cell, left click it again and it'll dissapear! When you're ready to begin the simulation, press the green " << std::endl
		<< "button at the bottom of the window. Want to stop the simulation? Click the button againand the cells will stop in" << std::endl
		<< "place! Lastly, at any time you can click on a square to delete or create a cell." << std::endl;

	std::cout << std::endl << "Cellular Roulette:" << std::endl
		<< "Player 1 creates an initial start and runs the simulation. From there, wait for a stable state." << std::endl
		<< "Player 2 then creates or destroys one cell on the game board. The placed cell needs to be next to the stable state." << std::endl
		<< "Wait for the simulation to reach a stable state again and swap roles." << std::endl
		<< "Whoever causes all cells to die loses! Even if that's in the initial configuration!" << std::endl << std::endl;

	std::cout << "Auto Immune:" << std::endl
		<< "Player 1 creates cells on the left side of the grid, and player 2 places cells on the right side of the grid." << std::endl
		<< "Run the simulation." << std::endl
		<< "If the board reaches a stable state with cells remaining on both sides, pause the simulation" << std::endl
		<< "Each player may then place (not destroy) more cells on their respective sides." << std::endl
		<< "Whoever still has cells on their side of the board wins! Get creative! Can you send your own cells to kill" << std::endl
		<< "the other player's?" << std::endl << std::endl;

	std::cout << "Sturdy Cells:" << std::endl
		<< "Player 1 places cells on the grid and runs the simulation until the board reaches a stable state." << std::endl
		<< "Both players will then pause the simulation, place a configuration of cells and run the simulation again." << std::endl
		<< "The player who disturbs the state of the other stable cells loses!" << std::endl << std::endl;

	system("pause");

	// Controls the state of the game
	bool run = false;

	// Logs the mouse's x and y coordinates
	int x = 0;
	int y = 0;
	// Controls the button's position
	int buttonX = 240; 
	int buttonY = 820;

	// Delta-Time to ensure a smooth simulation across all machines
	time_t deltaTime = clock();

	// Window for gameplay
	sf::RenderWindow window(sf::VideoMode(770, 1000), "Conway's Game of Life");

	// Grid for game to take place in
	Grid game(window, 25);

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
		game.printGrid(window);
		window.draw(button);
		// Display the correct text
		run ? window.draw(pauseText) : window.draw(playText);
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
