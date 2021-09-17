#include <iomanip>
#include <iostream>
#include "Grid.h"
using namespace std;

/**
* @pre: none
* @post: m_grid made with initial value 'O' in each board position.
*/

Grid::Grid()
{
    char rowNum = '1'; //char to increment row indicator
    char colLetter = 'A'; //char to increment column indicator
	
	m_grid = new char*[rows]; //creates the m_grid

	for (int i = 0; i < rows; i++)
            {
                m_grid[i] = new char[cols];
            }
	//m_grid = new char [rows][cols];

	for (int i = 0; i < rows; i++) // loop to fill m_grid with row/col indicator and unused positions
    {
		//m_grid[i] = new char *[cols];
		
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                m_grid[i][j] = ' ';
            }
            else if (i == 0 && j != 0)
            {
                m_grid[i][j] = colLetter;
                colLetter++;
            }
            else if (j == 0 && i != 0)
            {
                m_grid[i][j] = rowNum;
                rowNum++;
            }
            else if (i != 0 && j != 0)
            {
                m_grid[i][j] = '*';
			}
		}
		
	}
	
	
}

/**
* @pre: none
* @post: P1_array_m_grid is deleted
*/
// In the future needs to be edited to delete the constructor m_grid, P1's two m_grid and P2's m_grid.

Grid::~Grid()
{
	
	for (int i = 0; i < rows; i++)
		delete[] m_grid[i];

	delete[] m_grid;
	
}



/**
* @pre: Player inputs represent a valid location on the board.
* @post: 'S' assigned to P1_array_m_grid[tRow][tCol] to denote ship location
*/
//removed the first argument variable since P1_array_m_grid is already a member variable. -Yuri
// This can be discussed upon but I feel like passing the size of the ship into set ship would
// help in being able to check if all of that ship slot is a valid position by making check for validplacedcoordinates
// Check the whole ship not just a single spot - Nifemi.
// If checkforvalidcoordinates checks to see if that position is valid then we shouldn't need " m_grid[tRow][tCol] == '*' " down the line - Nifemi.


bool Grid::setShip(int tRow, int tCol, char dir, int size) 
{
	bool isPlaced = false;
	if (checkForValidPlacedCoordinates(tRow, tCol, size) && m_grid[tRow][tCol] == '*') // ensures that the position is valid.
	{
		 // iterates to put the ship of the right size into the m_grid
		
			if (dir == 'U' || dir == 'u')//conditionals to place ship in correct direction
        	{
				
				if(checkUp(tRow, tCol, size) == true) {
					//m_grid[tRow][tCol] = '|';
					for ( int i = 0; i < size ; i++) {
						for(int j=0; j < i+1; j++) {
							m_grid[tRow-j][tCol] = '|'; 
							}
						}
					isPlaced = true;
				}
        	}

			if (dir == 'D' || dir == 'd')
        	{
				if(checkDown(tRow, tCol, size) == true) {
					//m_grid[tRow][tCol] = '|';
					for ( int i = 0; i < size ; i++) {
						for(int j=0; j < i+1; j++) {
							m_grid[tRow+j][tCol] = '|'; 
							}
						}
					isPlaced = true;
				}
			}
			

        	if (dir == 'L' || dir == 'l')
        	{
				if(checkLeft(tRow, tCol, size) == true) {
					for ( int i = 0; i < size ; i++) 
					{
					for(int j=0; j < i+1; j++)
						{
							m_grid[tRow][tCol-j] = '-'; 
						}
					}
				isPlaced = true;
				}
        	}

        	if (dir == 'R' || dir == 'r')
        	{
				if(checkRight(tRow, tCol, size) == true) {
					for ( int i = 0; i < size ; i++) {
					for(int j=0; j < i+1; j++)
					{
                		m_grid[tRow][tCol+j] = '-'; 
            		}	
				}
				isPlaced = true;
				}
            	
       		}
	}

	return (isPlaced);
}

void Grid::setValue(int tRow, int tCol, bool hitOrMiss)
{
	if (hitOrMiss == true)
		m_grid[tRow][tCol] = hit_ship;
	
	else
		m_grid[tRow][tCol] = miss_ship;
}

/**
* @pre: none
* @return: value at P1_array_m_grid[tRow][tCol]
*/

// Would we need to change this method to know if we have to get from P1's m_grid or P2's m_grid. Right now i've just set it to get from m_grid
// since we are working with one m_grid for now - Nifemi.
char Grid::getValue(int tRow, int tCol)
{
	return (m_grid[tRow][tCol]);
}

//////////////////////////////////////////////////////////
void Grid::print_ships_Grid()
{
	cout << "\nHere is your game board: "<<endl;
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) //changed cols to columns to match member variable. -Yuri
        {
            //cout<<setw(3)<<m_grid[i][j];     //show row in one line (changed m_grid[][] to P1_array_m_grid to match the member variable. -Yuri)
			cout << m_grid[i][j] << ' ';
        }
        cout<<endl;
    }
}

void Grid::print_shots_Grid()
{
	cout << "\nHere's your opponent's game board:\n";
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(m_grid[i][j] == '|' || m_grid[i][j] == '-')
			{
				cout << "* ";
			}
			
			else
				cout << m_grid[i][j] << ' ';
		}
		cout << endl;
	}	
}
// I'm guessing this function would be adapted to no longer call set ship and would now take the size of the ship being checked

bool Grid::checkForValidPlacedCoordinates(int tRow, int tCol, int size)
{

	if (tRow >= rows || tRow <= 0 || tCol >= cols || tCol <= 0) //changed cols to columns to match member variable. -Yuri
	{
		cout << "Oops, the placement not in battlezone. Try again: " << endl;

		return false;
	}

	return true;
}

bool Grid::checkUp(int tRow, int tCol, int size)
{
	for (int i=0; i<size; i++)
	{
		if (m_grid[tRow-i][tCol] != '*' || (tRow-i) <= 0) {
			return(false);
		}
	}
	return(true);
}

bool Grid::checkDown(int tRow, int tCol, int size)
{
	for (int i=0; i<size; i++)
	{
		if ((tRow+i) >= 10 || m_grid[tRow+i][tCol] != '*') {
			return(false);
		}
	}
	return(true);
}

bool Grid::checkRight(int tRow, int tCol, int size)
{
	for (int i=0; i<size; i++)
	{
		if ((tCol+i) >= 11 || m_grid[tRow][tCol+i] != '*') {
			return(false);
		}
	}
	return(true);
}

bool Grid::checkLeft(int tRow, int tCol, int size)
{
	for (int i=0; i<size; i++)
	{
		if ((tCol-i) < 0 || m_grid[tRow][tCol-i] != '*') {
			return(false);
		}
	}
	return(true);
}

///////////////////////////////////////////////////////////