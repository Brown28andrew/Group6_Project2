#include "Game.h"
#include "Grid.h"
#include <unistd.h>
#include <string>

#include <iostream>

using namespace std;

bool Game::isHit(int tRow, int tCol, Grid* tGrid)
{		
	while (tRow >= 10 || tRow <= 0 || tCol >= 11 || tCol <= 0)
	{
		tCol = invalidInput();
		
				
		tCol = tCol;
		cin.ignore(256, '\n');
		
		
		cout << "What row would you like to fire at: ";
		cin >> tRow;
		while (cin.fail() || isalpha(tRow))
        {
            cout << "Invalid row input! please enter an integer between 1 and 9: " ;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> tRow;
        }	
	}

	while (tRow >= 10 || tRow <= 0 || tCol >= 11 || tCol <= 0 || tGrid->getValue(tRow, tCol) == 'H' || tGrid->getValue(tRow, tCol) == 'M')	
	{	
		tCol = invalidInput();
				
		tCol = tCol;
		cin.ignore(256, '\n');
				
		cout << "What row would you like to fire at: ";
		cin >> tRow;
		while (cin.fail() || isalpha(tRow))
        {
            cout << "Invalid row input! please enter an integer between 1 and 9: " ;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> tRow;
        }
	}
	
	if (tGrid->getValue(tRow, tCol) == '|' || tGrid->getValue(tRow, tCol) == '-')
	{
		tGrid -> setValue(tRow, tCol, true);
		tGrid->setShadow(tRow, tCol);
		return true;
	}
	else 
	{
		tGrid -> setValue(tRow,tCol, false);
		return false;
	}
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

char Game::getColumnLetter(string input)
{
    char col = ' ';
    while (input.length() > 1 || isalpha(input.at(0)) == false)
    {
        cout << "Error, please enter a valid column (A-J: ";
        cin >> input;
    }
    col = input.at(0);
    col = toupper(col);
    return col;
}

int Game::invalidInput()
{
		cout << "Invalid location. Try again: " << endl;
		string userInput;
		char tColLetter = 'A';
		char inLetter = ' ';	
		int tCol = 1;
		cout << "\nWhat column would you like to fire at (A-J): ";
		cin >> userInput;
		inLetter = getColumnLetter(userInput);
			
		while (tColLetter < inLetter)
		{
			tColLetter++;
			tCol++;
		}
		return tCol;
}

bool Game::checkSunk (Grid* playerGrid, int n) {
	return(playerGrid->checkShadow(n)); //Checks if the ship at that particular position is sunk or not.
}

