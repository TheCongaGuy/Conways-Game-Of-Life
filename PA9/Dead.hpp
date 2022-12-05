#pragma once

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:	This file contains functions to set a cell on the grid to dead.																   *
 *******************************************************************************/

#include "Cell.hpp"

class Dead : public Cell
{
public:
	//constructor
	Dead();
	//deconstructor
	~Dead();
	//setter to set the cell to dead
	void setDead(bool alivevalue);
	//function to confirm if the cell is alive or dead
	bool isDead();

private:
	
};