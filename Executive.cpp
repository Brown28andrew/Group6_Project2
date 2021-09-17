#include "Executive.h"
#include "Grid.h"
#include "Game.h"
#include <iostream>
using namespace std;


Executive::Executive()
{
	player1 = new Grid;
    player2 = new Grid;
    game = new Game;
}

Executive::~Executive()
{
	delete player1;
    delete player2;
}

void Executive::BeginGame()
{
    
    cout << "\n----------------------------------------------------------\n";
    cout << "WELCOME TO THE BATTLESHIP GAME BY TEAM-18\n";
    cout << "----------------------------------------------------------\n";
    cout << "\nBelow are the some symbols which will be used during the game.\n";
    cout << "The symbol for ships: | or -\n";
    cout << "The symbol for when ships are hit: H\n";
    cout << "The symbol for when shots are missed: M\n";
    cout << "\nHow many ships would you like to have in the game Player 1?\nNumber of ships (1-6): ";
    cin >> numShips;
        while (numShips > 6 || numShips < 0)
        {
            cout << "Invalid number. How many ships do you want to place? (1-6) \n";
            cin >> numShips;
        }
    p1HitsLeft = game->setHitsLeft(numShips);
    p2HitsLeft = game->setHitsLeft(numShips);   
    cout << "\nHits Left: " << p1HitsLeft; 
    char readiness;     
    player1->print_ships_Grid();
    placeShips(numShips, player1);
    cout << "\nThanks Player1!\n";
	
	do
	{
		cout << "\nPlayer 2, Are you ready to place your ships? (enter Y to continue)\n";
		cin >> readiness; 
		
		if (readiness != 'Y')
			cout << "\nInvalid input!\n\n";
	}while (readiness != 'Y');

	clearScreen();
	
    cout << "Player 2, its your turn to place your " << numShips << " ship(s)!\n";
        
    player2->print_ships_Grid();
    placeShips(numShips, player2);
    playGame(player1, player2);
}

void Executive::placeShips(int numShips, Grid* playerGrid) 
{
	bool isPlaced = false;
	
    for (int i = 0; i < numShips; i++)//loop to place ships on board
    {
		isPlaced = false;
		
        do {
        originCol = 1;
        colLetter = 'A';
        
        cout << "\nWhere would you like to place the origin of ship "<< i+1 << "?\nColumn (A-J): ";
        cin >> col;
        col = toupper(col);
            while (colLetter < col)//loop to turn letter for column into integer to place ship on grid
            {
                colLetter++;
                originCol++;
            }

        cout << "Row (1-9): ";
        cin >> originRow;
		if (i != 0)
		{
			cout << "Ship " << i+1 << " will take up " << i+1 << " spaces, which direction would you like to orient the ship? (U, D, L, R)\nDirection: ";
			cin >> direction;
		}
		
		else
			direction = 'U';
		
        shipsize = i+1;
		
		isPlaced = playerGrid->setShip(originRow,originCol,direction,shipsize);
		if (isPlaced == false)
			cout << "\nInvalid placement! please try again.\n";
		
        }while (isPlaced == false);
           // cout << "Invalid location. Try again:\n";
            //placeShips(numShips, playerGrid, i);
        
        playerGrid->print_ships_Grid();  
    }
}

void Executive::playGame(Grid* P1, Grid* P2)
{
    bool gameEnd = false;
    int turnCounter = 0;
    bool is_Hit = false;
    while (!gameEnd)
    {
        originCol = 1;
        colLetter = 'A';

        if (turnCounter % 2 == 0)
        {
            clearScreen();
            P2->print_shots_Grid(); //print player ones shot grid
            P1->print_ships_Grid();//print player ones ship grid

            cout << "Where would you like to take your shot Player 1?\nColumn (A-J):"; //get shot from player one
            char shotColumn;
            cin >> shotColumn;
            shotColumn = toupper(shotColumn);
            while (colLetter < shotColumn)//loop to turn letter for column into integer to place ship on grid
            {
                colLetter++;
                originCol++;
            }
            cout << "Row (1-9): ";
            int shotRow;
            cin >> shotRow;
            
            is_Hit = game->isHit(shotRow, originCol, P2);//check if hit or miss
            if (is_Hit == true)
            {
                p1HitsLeft--;
            }
            P2->setValue(shotRow, originCol, is_Hit);//update board
            gameEnd = game->getEndGame(p1HitsLeft);//check if game end
            turnCounter++;
        }
        else
        {
            clearScreen();
            P1->print_shots_Grid(); //print player ones shot grid
            P2->print_ships_Grid();//print player ones ship grid

            cout << "Where would you like to take your shot Player 2 ?\nColumn (A-J):"; //get shot from player one
            char shotColumn;
            cin >> shotColumn;
            shotColumn = toupper(shotColumn);
            while (colLetter < shotColumn)//loop to turn letter for column into integer to place ship on grid
            {
                colLetter++;
                originCol++;
            }
            cout << "Row (1-9): ";
            int shotRow;
            cin >> shotRow;
            is_Hit = game->isHit(shotRow, originCol, P1);//check if hit or miss
            if (is_Hit == true)
            {
                p2HitsLeft--;
            }
            P1->setValue(shotRow, originCol, is_Hit);//update board
            gameEnd = game->getEndGame(p2HitsLeft);//check if game end
            turnCounter++;
        }
    }
	
	endTheGame();
}

void Executive::endTheGame()
{
	if (p1HitsLeft == 0)
		cout << "\n\nPlayer 1 wins!";
	
	else if (p2HitsLeft == 0)
		cout << "\n\nPlayer 2 wins!";
	
	cout << "Thank you for playing our game. Goodbye!\n\n";
}

void Executive::clearScreen()
{
	for (int i = 0; i < 10; i++)
		cout << "\n\n\n\n\n\n";
}