#include <iostream>
#include <math.h>

using namespace std;

CONST int rows = 9;
CONST int columns = 10;

int array_grid[rows][cols];

char ships = 'S';
char hit_ship = 'H';
char miss_ship = 'M';

//function to print the legends for the users
void func_legend()
{
    cout << "The symbol for ships " << ships << endl;
    cout << "The symbol for when ships are hit " << hit_ship << endl;
    cout << "The symbol for when shots are missed " << miss_ship << endl;
}

//function to print the empty grid with no ships placed on it
void grid_show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            array_grid[i][j] = 'O';
        }
    }
}

//function to ask for placement on the grid
int user_pos_grid()
{
    int row_input;
    int col_input;
    int ship_number;

    cout << "How many ships do you want to place? " << endl;
    cin >> ship_number;

    if (ship_number > 6)
    {
        cout << "Not possible. Sorry." << endl;
    }

    while (ship_number <= 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << "Input the row number for the placement of ship: " << i << endl;
            cin >> row_input;

            cout << "Input the column number for the placement of ship: " << i << endl;
            cin >> col_input;
        }
    }
}