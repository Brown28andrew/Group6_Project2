#include "Game.h"
#include "Grid.h"
#include <unistd.h>

#include <iostream>

using namespace std;


bool Game::isHit(int tRow, int tCol, Grid* tGrid)
{
	bool validShot = false;
	
	//currently, Grid class's hit_ship and miss_ship are private member variables with no public methods to retrieve them.
	//we'll want to define somthing like getHit_ship and getMiss_ship if we want to use them here.
	do
	{
		if (tGrid->getValue(tRow, tCol) == 'H' || tGrid->getValue(tRow, tCol) == 'M')	
		{			
			cout << "That location has already been fired at!\n\n what row would you like to fire at: ";
			cin >> tRow;
            sleep(3);
			cout << "what column would you like to fire at: ";
			cin >> tCol;
            sleep(2);
		}
		
		else
			validShot = true;
		
	} while(validShot == false);
	
	if (tGrid->getValue(tRow, tCol) == '|' || tGrid->getValue(tRow, tCol) == '-')
	{
		tGrid->setValue(tRow, tCol, true);
		hitsLeft--;
		return true;
	}
		
	tGrid->setValue(tRow, tCol, false);
	return false;
}

bool Game::getEndGame(int hitsLeft)
{
	if (hitsLeft == 0)
		return true;
	
	else
		return false;
}

int Game::setHitsLeft(int shipNum)
{
	return (hitsLeft = (shipNum * (shipNum + 1))/2);
}