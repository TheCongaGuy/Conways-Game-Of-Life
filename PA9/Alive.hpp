#pragma once

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:	This file contains functions to set a cell on the grid to alive.															   *
 *******************************************************************************/

#include "Cell.hpp"

class Alive : public Cell
{
public:
	//constructor
	Alive();
	//deconstructor
	~Alive();
	//setter
	void setAlive(bool alivevalue);
	//alive confirmation function
	bool isAlive();

private:


};