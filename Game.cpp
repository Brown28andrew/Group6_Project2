#include "Game.h"
#include "Grid.h"


bool Game::isHit(int tRow, int tCol, Grid tGrid)
{
	if (tGrid.getValue(tRow, tCol) == '|' || tGrid.getValue(tRow, tCol) == '-')
	{
		
	}
	return false;
}

bool Game::getEndGame()
{
	if (hitsLeft == 0)
		return true;
	
	else
		return false;
}

void Game::setHitsLeft(int shipNum)
{
	hitsLeft = (shipNum * (shipNum + 1))/2;
}