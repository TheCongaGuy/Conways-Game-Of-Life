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
// Programmer: Drew Evensen
void graphicsTest();

// Test function prints the grid to the screen
// Programmer: Drew Evensen
void printGridTest();

void printCellTest();

void printAliveCellTest();

void printDeadCellTest();