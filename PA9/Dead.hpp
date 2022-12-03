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

class Dead : public Cell
{
public:
	Dead();

	~Dead();

	void setDead(bool alivevalue);

	bool isDead();

private:
	bool dead;
};