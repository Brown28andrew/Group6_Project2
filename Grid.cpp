#include <iomanip>
#include <iostream>
#include "Grid.h"
using namespace std;

/**
* @pre: none
* @post: Grid made with initial value 'O' in each board position.
*/

Grid::Grid()
{
    char rowNum = '1'; //char to increment row indicator
    char colLetter = 'A'; //char to increment column indicator
    char grid[rows][cols]; //creates the grid
	grid = new char *[rows];
	for (int i = 0; i < rows; i++) // loop to fill grid with row/col indicator and unused positions
    {
		grid[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                grid[i][j] = ' ';
            }
            else if (i == 0 && j != 0)
            {
                grid[i][j] = colLetter;
                colLetter++;
            }
            else if (j == 0 && i != 0)
            {
                grid[i][j] = rowNum;
                rowNum++;
            }
            else if (i != 0 && j != 0)
            {
                grid[i][j] = '*';
			}
		}
	}
	
}

/**
* @pre: none
* @post: P1_array_grid is deleted
*/
// In the future needs to be edited to delete the constructor grid, P1's two grid and P2's grid.

Grid::~Grid()
{
	for (int i = 0; i < rows; i++)
		delete[] grid[i];

	delete[] grid;
}

/**
* @pre: Player inputs represent a valid location on the board.
* @post: 'S' assigned to P1_array_grid[tRow][tCol] to denote ship location
*/
//removed the first argument variable since P1_array_grid is already a member variable. -Yuri
// This can be discussed upon but I feel like passing the size of the ship into set ship would
// help in being able to check if all of that ship slot is a valid position by making check for validplacedcoordinates
// Check the whole ship not just a single spot - Nifemi.
// If checkforvalidcoordinates checks to see if that position is valid then we shouldn't need " grid[tRow][tCol] == '*' " down the line - Nifemi.

bool Grid::setShip(int tRow, int tCol, char dir, int size) 
{
	bool isPlaced = false;
	if (checkForValidPlacedCoordinates(tRow, tCol, size) && grid[tRow][tCol] == '*') // ensures that the position is valid.
	{
		for ( int i = 0; i < size ; i++) // iterates to put the ship of the right size into the grid
		{
			if (direction == 'U')//conditionals to place ship in correct direction
        	{
			grid[tRow][tCol] = '|';
            	for(int j=0; j < i+1; j++)
				{
                grid[tRow-j][tCol] = '|'; 
            	}
        	}

			if (direction == 'D')
        	{
			grid[tRow][tCol] = '|';
            	for(int j=0; j < i+1; j++)
				{
                grid[tRow+j][tCol] = '|'; 
            	}
       		}

        	if (direction == 'L')
        	{
            	for(int j=0; j < i+1; j++)
				{
                grid[tRow][tCol-j] = '-'; 
            	}
        	}

        	if (direction == 'R')
        	{
            	for(int j=0; j < i+1; j++)
				{
                grid[tRow][tCol+j] = '-'; 
            	}
       		}
		}
	isPlaced = true;
	}

	return (isPlaced);
}

/**
* @pre: none
* @return: value at P1_array_grid[tRow][tCol]
*/

// Would we need to change this method to know if we have to get from P1's grid or P2's grid. Right now i've just set it to get from grid
// since we are working with one grid for now - Nifemi.
char Grid::getValue(int tRow, int tCol)
{
	return (grid[tRow][tCol]);
}

//////////////////////////////////////////////////////////
void Grid::printUserGrid(int tRow, int tCol)
{
	cout << "Here is your grid: "<<endl;
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) //changed cols to columns to match member variable. -Yuri
        {
            cout<<setw(3)<<grid[i][j];     //show row in one line (changed grid[][] to P1_array_grid to match the member variable. -Yuri)
        }
        cout<<endl;
    }
}

// I'm guessing this function would be adapted to no longer call set ship and would now take the size of the ship being checked
bool Grid::checkForValidPlacedCoordinates(int tRow, int tCol int size)
{

	if (tRow >= rows || tRow <= 0 || tCol >= cols || tCol <= 0) //changed cols to columns to match member variable. -Yuri
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