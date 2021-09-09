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