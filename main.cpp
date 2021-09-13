#include <iostream>
#include "Grid.h"
#include "Executive.h"
//#include <math.h>

using namespace std;

// changed to 10 and 11
const int rows = 10;
const int columns = 11;

int array_grid[rows][columns];

char ships = 'S';
char hit_ship = 'H';
char miss_ship = 'M';

//method for opening the game


    // embedded in Executive -Nifemi
void gameIntro()
{
    cout << "----------------------------------------------------------" << endl;
    cout << "WELCOME TO THE BATTLESHIP GAME BY TEAM-18" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Below are the some symbols which will be used during the game." << endl;
}
//function to print the legends for the users
void func_legend()
{
    cout << "The symbol for ships: " << ships << endl;
    cout << "The symbol for when ships are hit: " << hit_ship << endl;
    cout << "The symbol for when shots are missed: " << miss_ship << endl;
}

//function to print the empty grid with no ships placed on it
// Embedded in grid constructor
void grid_make()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= columns; j++)
        {
            array_grid[i][j] = 'O';
        }
    }
}

//function to ask for placement on the grid

    // embedded in executive - Nifemi
void user_pos_grid()
{
    int row_input;
    int col_input;
    int ship_number;
	
	//made make_number declaration into a comment because it didn't have a use yet. -Yuri
    //int make_number;

    cout << "How many ships do you want to place? (1-6): ";
    cin >> ship_number;

    while (ship_number > 6 || ship_number < 0)
    {
        cout << "Invalid number. How many ships do you want to place? (1-6) " << endl;
        cin >> ship_number;
    }

    for (int i = 1; i <= ship_number; i++)
    {
        cout << "Input the row number for the placement of ship " << i << endl;
        cin >> row_input;

        cout << "Input the column number for the placement of ship " << i << endl;
        cin >> col_input;
    }
}


int main()
{
    //gameIntro();
    //func_legend();
    //grid_make();
    //user_pos_grid();
    //checkForValidPlacedCoordinates();
    //printUserGrid();
    Executive myExec;
    myExec.BeginGame();
    //Grid myGrid;
    //myGrid.setShip(5,5,'U',1);
    //myGrid.printUserGrid();

    return (0);
}