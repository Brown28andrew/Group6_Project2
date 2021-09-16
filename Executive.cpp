#include "Executive.h"
#include "Grid.h"
#include "Game.h"
#include <iostream>
using namespace std;


Executive::Executive()
{

}

Executive::~Executive()
{

}

void Executive::BeginGame()
{
cout << "----------------------------------------------------------\n";
cout << "WELCOME TO THE BATTLESHIP GAME BY TEAM-18\n";
cout << "----------------------------------------------------------\n";
cout << "Below are the some symbols which will be used during the game.\n";
cout << "The symbol for ships: | or -\n";
cout << "The symbol for when ships are hit: H\n";
cout << "The symbol for when shots are missed: M\n";
cout << "How many ships would you like to have in the game?\nNumber of ships (1-6): ";
cin >> numShips;
    while (numShips > 6 || numShips < 0)
    {
        cout << "Invalid number. How many ships do you want to place? (1-6) \n";
        cin >> numShips;
    }
    
Grid setter;
setter.print_ships_Grid();

for (int i = 0; i < numShips; i++)//loop to place ships on board
{
    /*
    col = ' ';
    originRow = 0;
    direction = ' ';
    */
    originCol = 1;
    colLetter = 'A';
    
    cout << "Where would you like to place the origin of ship "<< i+1 << "?\nColumn (A-J): ";
    cin >> col;
        while (colLetter < col)//loop to turn letter for column into integer to place ship on grid
        {
            colLetter++;
            originCol++;
        }

    cout << "Row (1-9): ";
    cin >> originRow;
    cout << "Ship " << i+1 << " will take up " << i+1 << " spaces, which direction would you like to orient the ship? (U, D, L, R)\nDirection: ";
    cin >> direction;
    shipsize = i+1;

    
    setter.setShip(originRow,originCol,direction,shipsize);  
    std::cout << "\nUpdated Board\n";
    setter.print_ships_Grid();   
}
}
