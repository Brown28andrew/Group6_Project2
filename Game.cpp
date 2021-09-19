#include "Game.h"
#include "Grid.h"
#include <unistd.h>

#include <iostream>

using namespace std;

bool Game::isHit(int tRow, int tCol, Grid* tGrid)
{		
	while (tRow >= 10 || tRow <= 0 || tCol >= 11 || tCol <= 0)
	{
		tCol = invalidInput();
				
		cout << "What row would you like to fire at: ";
        sleep(2);
		cin >> tRow;
		
	}

	while (tGrid->getValue(tRow, tCol) == 'H' || tGrid->getValue(tRow, tCol) == 'M')	
	{	
		tCol = invalidInput();
				
		cout << "What row would you like to fire at: ";
        sleep(2);
		cin >> tRow;
	}
	
	if (tGrid->getValue(tRow, tCol) == '|' || tGrid->getValue(tRow, tCol) == '-')
	{
		tGrid -> setValue(tRow, tCol, true);
		return true;
	}
	else //(tGrid->getValue(tRow, tCol) != '|' || tGrid->getValue(tRow, tCol) != '-')
	{
		tGrid -> setValue(tRow,tCol, false);
		return false;
	}
	//else
	//{
	//	return isHit(tRow, tCol, tGrid);
	//	cout << "Got here mama";
	//}
	
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
	return ((shipNum * (shipNum + 1))/2);
}

int Game::invalidInput()
{
		cout << "Invalid location. Try again: " << endl;
        sleep(2);
		char tColLetter = 'A';
		char inLetter = ' ';	
		int tCol = 1;
		cout << "\nWhat column would you like to fire at: ";
		cin >> inLetter;
        sleep(2);
			
		while (tColLetter < inLetter)
		{
			tColLetter++;
			tCol++;
		}
		return tCol;
}