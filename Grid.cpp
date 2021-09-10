#include "Grid.h"

/**
* @pre: none
* @post: P1_array_grid made with initial value 'O' in each board position.
*/
Grid::Grid()
{
	P1_array_grid = new char*[rows];

	for(int i = 0; i < rows; i++)
	{
		P1_array_grid[i] = new char[columns];
		
		for(int j = 0; j < columns; j++)
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
bool Grid::setShip(int tRow, int tCol)
{
	bool isPlaced = false;
	
	if (P1_array_grid[tRow][tCol] == 'O')
	{
		P1_array_grid[tRow][tCol] = 'S';
		isPlaced = true;
	}
	
	return(isPlaced);
}

/**
* @pre: none
* @return: value at P1_array_grid[tRow][tCol]
*/
char Grid::getValue(int tRow, int tCol)
{
	return(P1_array_grid[tRow][tCol]);
}
	

