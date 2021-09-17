#include "Game.h"
#include "Grid.h"

#include <iostream>

using namespace std;


bool Game::isHit(int tRow, int tCol, Grid* tGrid)
{		
	while (tRow >= 10 || tRow <= 0 || tCol >= 11 || tCol <= 0)
	{
		cout << "Oops, the placement not in battlezone. Try again: " << endl;
		char tColLetter = 'A';
		char inLetter = ' ';	
		tCol = 1;
		cout << "\nWhat column would you like to fire at: ";
		cin >> inLetter;
			
		while (tColLetter < inLetter)
		{
			tColLetter++;
			tCol++;
		}
				
		cout << "What row would you like to fire at: ";
		cin >> tRow;
		
	}

	while (tGrid->getValue(tRow, tCol) == 'H' || tGrid->getValue(tRow, tCol) == 'M')	
	{	
		char tColLetter = 'A';
		char inLetter = ' ';	
		tCol = 1;
		cout << "\nThat location has already been fired at!\nwhat column would you like to fire at: ";
		cin >> inLetter;
			
		while (tColLetter < inLetter)
		{
			tColLetter++;
			tCol++;
		}
				
		cout << "what row would you like to fire at: ";
		cin >> tRow;
	}
	
	if (tGrid->getValue(tRow, tCol) == '|' || tGrid->getValue(tRow, tCol) == '-')
	{
		tGrid -> setValue(tRow, tCol, true);
		return true;
	}
	else if(tGrid->getValue(tRow, tCol) != '|' || tGrid->getValue(tRow, tCol) != '-')
	{
		tGrid -> setValue(tRow,tCol, false);
	}
	else
	{
		return isHit(tRow, tCol, tGrid);
		cout << "Got here mama";
	}
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
	return ((shipNum * (shipNum + 1))/2);
}