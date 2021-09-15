#include "Executive.h"
#include "Grid.h"
#include "Game.h"
#include <iostream>
using namespace std;


Executive::Executive()
{
	player1 = new Grid;
}

Executive::~Executive()
{
	delete player1;
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
        
    player1->printUserGrid();
    placeShips(numShips, player1);

}

void Executive::placeShips(int numShips, Grid* playerGrid) {
	bool isPlaced = false;
	
    for (int i = 0; i < numShips; i++)//loop to place ships on board
    {
		isPlaced = false;
		
        do {
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
		
		isPlaced = playerGrid->setShip(originRow,originCol,direction,shipsize);
		if (isPlaced == false)
			cout << "\nInvalid placement! please try again.\n";
		
        }while (isPlaced == false);
           // cout << "Invalid location. Try again:\n";
            //placeShips(numShips, playerGrid, i);
        

        std::cout << "\nUpdated Board\n";
        playerGrid->printUserGrid();  
    }
}

void Executive::playGame()
{
    bool gameEnd = false;
    int turnCounter = 0;
    while (!gameEnd)
    {
        if (turnCounter % 2 == 0)
        {
            //print player ones shot grid
            //print player ones ship grid
            cout << "Where would you like to take your shot?\nColumn (A-J):"; //get shot from player one
            char shotColumn;
            cin >> shotColumn;
            cout << "Row (1-9): ";
            int shotRow;
            cin >> shotRow;
            
            //check if hit or miss
            //update board
            //check if game end
            turnCounter++;
        }
        else
        {
            //print player twos shot grid
            //print player twos ship grid
            //get shot from player two
            //check if hit or miss
            //update board
            //check if game end
            turnCounter++;
        }
    }


}
