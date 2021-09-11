#include <iomanip>
#include <iostream>

#include "Grid.h"

using namespace std;

/**
* @pre: none
* @post: P1_array_grid made with initial value 'O' in each board position.
*/
Grid::Grid()
{
	P1_array_grid = new char *[rows];

	for (int i = 0; i < rows; i++)
	{
		P1_array_grid[i] = new char[columns];

		for (int j = 0; j < columns; j++)
			P1_array_grid[i][j] = 'O';
	}
}

/**
* @pre: none
* @post: P1_array_grid is deleted
*/
Grid::~Grid()
{
	for (int i = 0; i < rows; i++)
		delete[] P1_array_grid[i];

	delete[] P1_array_grid;
}

/**
* @pre: Player inputs represent a valid location on the board.
* @post: 'S' assigned to P1_array_grid[tRow][tCol] to denote ship location
*/
bool Grid::setShip(int tRow, int tCol) //removed the first argument variable since P1_array_grid is already a member variable. -Yuri
{
	bool isPlaced = false;

	checkForValidPlacedCoordinates(tRow, tCol);

	if (P1_array_grid[tRow][tCol] == 'O')
	{
		P1_array_grid[tRow][tCol] = 'S';
		isPlaced = true;
	}

	return (isPlaced);
}

/**
* @pre: none
* @return: value at P1_array_grid[tRow][tCol]
*/
char Grid::getValue(int tRow, int tCol)
{
	return (P1_array_grid[tRow][tCol]);
}

//////////////////////////////////////////////////////////
void Grid::printUserGrid(int tRow, int tCol)
{
	cout << "Here is your grid: "<<endl;
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++) //changed cols to columns to match member variable. -Yuri
        {
            cout<<setw(3)<<P1_array_grid[i][j];     //show row in one line (changed grid[][] to P1_array_grid to match the member variable. -Yuri)
        }
        cout<<endl;
    }
}

bool Grid::checkForValidPlacedCoordinates(int tRow, int tCol)
{

	if (tRow >= rows || tRow <= 0 || tCol >= columns || tCol <= 0) //changed cols to columns to match member variable. -Yuri
	{
		cout << "Oops, the placement not in battlezone. Try again: " << endl;

		return 0;
	}

	else 
	{
		setShip(tRow, tCol); //added tRow and tCol since this function expects two passed arguments. -Yuri
	}

	return true;
}
///////////////////////////////////////////////////////////