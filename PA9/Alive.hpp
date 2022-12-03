#pragma once

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

#include "Cell.hpp"

class Alive : public Cell
{
public:
	Alive();

	~Alive();

	void setAlive(bool alivevalue);

	bool isAlive();

private:
	bool alive;
};