#include <iomanip>
#include <iostream>
#include "Grid.h"
using namespace std;

Grid::Grid()
{
    char rowNum = '1'; //char to increment row indicator
    char colLetter = 'A'; //char to increment column indicator
	
	m_grid = new char*[rows]; //creates the m_grid

	for (int i = 0; i < rows; i++)
            {
                m_grid[i] = new char[cols];
            }

	for (int i = 0; i < rows; i++) // loop to fill m_grid with row/col indicator and unused positions
    {	
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

Grid::~Grid()
{
	
	for (int i = 0; i < rows; i++)
		delete[] m_grid[i];

	delete[] m_grid;
	
}

bool Grid::setShip(int tRow, int tCol, char dir, int size) 
{
	bool isPlaced = false;
	if (checkForValidPlacedCoordinates(tRow, tCol, size) && m_grid[tRow][tCol] == '*') // ensures that the position is valid.
	{
		 // iterates to put the ship of the right size into the m_grid
		
			if (dir == 'U' || dir == 'u')//conditionals to place ship in correct direction
        	{
				
				if(checkUp(tRow, tCol, size) == true) {
					for ( int i = 0; i < size ; i++) {
						for(int j=0; j < i+1; j++) {
							m_grid[tRow-j][tCol] = '|'; 
							}
						}
					isPlaced = true;
				}
        	}

			else if (dir == 'D' || dir == 'd')
        	{
				if(checkDown(tRow, tCol, size) == true) {
					for ( int i = 0; i < size ; i++) {
						for(int j=0; j < i+1; j++) {
							m_grid[tRow+j][tCol] = '|'; 
							}
						}
					isPlaced = true;
				}
			}
			

        	else if (dir == 'L' || dir == 'l')
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

        	else if (dir == 'R' || dir == 'r')
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

char Grid::getValue(int tRow, int tCol)
{
	return (m_grid[tRow][tCol]);
}

void Grid::print_ships_Grid()
{
	cout << "\nHere is your game board: "<<endl;
	for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
			cout << m_grid[i][j] << ' ';
		
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

bool Grid::checkForValidPlacedCoordinates(int tRow, int tCol, int size)
{

	if (tRow >= rows || tRow <= 0 || tCol >= cols || tCol <= 0)
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