#pragma once

/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:	File consisting of test methods. Not part of final solution.   *
 *				Used for experimenting and ensuring program works.			   *
 *******************************************************************************/

#include <SFML/Graphics.hpp>// External Library
#include <iostream>
#include <random>
#include <Windows.h>
#include <time.h>
#include "Grid.hpp"
#include "Cell.hpp"

// Test function that demonstrates a visualization of selection sort for the purposes of checking and understanding 
// the graphics library
// Programmers: Drew Evensen
void graphicsTest();

// Test function prints the grid to the screen
// Programmers: Drew Evensen
void printGridTest();

// Test function prints a cell to the screen
// Programmers: Kaitlyn Cornish
void printCellTest();

// Programmers: Kaitlyn Cornish, Drew Evensen
void printAliveCellTest();

// Programmers: Kaitlyn Cornish, Drew Evensen
void printDeadCellTest();

// Test function gets user input via clicks of a mouse and finds the correct cell they clicked on
// Programmers: Drew Evensen
void userInputTest();