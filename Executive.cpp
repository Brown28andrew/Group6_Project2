#include "Executive.h"
#include "Grid.h"
#include "Game.h"
#include <iostream>

/*
Executive::Executive()
{

}

Executive::~Executive()
{

}
*/
void Executive::BeginGame()
{
std::cout << "----------------------------------------------------------\n";
std::cout << "WELCOME TO THE BATTLESHIP GAME BY TEAM-18\n";
std::cout << "----------------------------------------------------------\n";
std::cout << "Below are the some symbols which will be used during the game.\n";
std::cout << "The symbol for ships: | or -\n";
std::cout << "The symbol for when ships are hit: H\n";
std::cout << "The symbol for when shots are missed: M\n";
std::cout << "How many ships would you like to have in the game?\nNumber of ships (1-6): ";
std::cin >> numShips;
    while (ship_number > 6 || ship_number < 0)
    {
        cout << "Invalid number. How many ships do you want to place? (1-6) \n";
        cin >> numShips;
    }
for (int i = 0; i < numShips; i++)//loop to place ships on board
{
    std::cout << "Where would you like to place the origin of ship "<< i+1 << "?\nColumn (A-J): ";
    std::cin >> col;
        while (colLetter <= col)//loop to turn letter for column into integer to place ship on grid
        {
            colLetter++;
            originCol++;
        }
    std::cout << "Row (1-9): ";
    std::cin >> originRow;
    std::cout << "Ship " << i+1 << " will take up " << i+1 << " spaces, which direction would you like to orient the ship? (U, D, L, R)\nDirection: ";
    std::cin >> direction;
    shipsize = i+1;
    Grid.setter;
    setter.setShip(col,originRow,direction,shipsize);    
}
std::cout << "\nUpdated Board\n";
setter.printUserGrid();
}