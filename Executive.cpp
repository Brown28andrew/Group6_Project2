#include "Executive.h"
#include "Grid.h"
#include "Game.h"
#include <iostream>
#include <string>
//#include <ctype.h>
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
	delete game;
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
    cout << "\nHow many ships would you like to have in the game?\nNumber of ships (1-6): ";
        cin >> numShips;
        while (cin.fail() || numShips > 6 || numShips <= 0)
        {
            cout << "Invalid number of ships. Please try again. Number of ships (1-6): " ;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> numShips;
        }
        
    p1HitsLeft = game->setHitsLeft(numShips);
    p2HitsLeft = game->setHitsLeft(numShips);   

    char readiness; 

	cout << "\nPlayer 1 places their ships first.";
    player1->print_ships_Grid();
    placeShips(numShips, player1);
	
	clearScreen();
    cout << "\nAll ships placed for player 1!\n";
	
	do
	{
		cout << "\nPlayer 2, Are you ready to place your ships? (enter Y to continue)\n";
		cin >> readiness; 
		
		if (readiness != 'Y' && readiness != 'y')
			cout << "\nInvalid input!\n\n";
	}while (readiness != 'Y' && readiness != 'y');
        
    player2->print_ships_Grid();
    placeShips(numShips, player2);
	
	clearScreen();
	cout << "\nAll ships placed for player 2!\n";
	
	do
	{
		cout << "\nPlayer 1, Are you ready to start the game? (enter Y to continue)\n";
		cin >> readiness; 
		
		if (readiness != 'Y' && readiness != 'y')
			cout << "\nInvalid input!\n\n";
	}while (readiness != 'Y' && readiness != 'y');
	
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
            string userCol;
            cin >> userCol;
            col = getUserLetter(userCol);
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
            
            if(isalpha(col))
                isPlaced = playerGrid->setShip(originRow,originCol,direction,shipsize);
            
            if (isPlaced == false)
                cout << "\nInvalid placement! Please try again.\n";
		
        }while (isPlaced == false);
        
        playerGrid->print_ships_Grid();  
    }
}

void Executive::playGame(Grid* P1, Grid* P2)
{
    bool gameEnd = false;
    bool is_Hit = false;
    while (!gameEnd)
    {
        

        if (turnCounter % 2 == 0)
        {
            clearScreen();
            P2->print_shots_Grid();
            P1->print_ships_Grid();

            is_Hit = getShot(P2, 1);

            gameEnd = game->getEndGame(p1HitsLeft);//check if game end
            turnCounter++;
        }
        else
        {
            clearScreen();
            P1->print_shots_Grid(); //print player ones shot grid
            P2->print_ships_Grid();//print player ones ship grid

            is_Hit = getShot(P1, 2);

            gameEnd = game->getEndGame(p2HitsLeft);//check if game end
            turnCounter++;
        }
		
		if (!gameEnd)
			nextTurn(is_Hit);
    }
	
	endTheGame();
}

void Executive::endTheGame()
{
	cout << "\nPlayer " << ((turnCounter - 1) % 2) + 1 << " wins!";
	
	cout << "\n\nThank you for playing our game. Goodbye!\n\n";
}

void Executive::nextTurn(bool is_hit)
{
	char c;
	clearScreen();
	
	if (is_hit)
		cout << "Hit!";
	
	else
		cout << "Miss!";
	
	cout << "\n\nIs player " << (turnCounter % 2) + 1 << " ready? (Enter Y to continue): ";
		
	do
	{
		cin >> c;
		c = toupper(c);
	
		if (c != 'Y')
			cout << "Invalid input! please enter Y when the next player is ready: ";
	} while (c != 'Y');
	
}
	
	

void Executive::clearScreen()
{
	for (int i = 0; i < 10; i++)
		cout << "\n\n\n\n\n\n";
}

char Executive::getUserLetter(string input)
{
    char col = ' ';
    while (input.length() > 1 || isalpha(input.at(0)) == false)
    {
        cout << "Error, please enter a valid column: ";
        cin >> input;
    }
    col = input.at(0);
    col = toupper(col);
    return col;
}

bool Executive::getShot(Grid* grid, int n) {
            originCol = 1;
            colLetter = 'A';
            bool is_Hit;

            cout << "Where would you like to take your shot Player " << n << "?\nColumn (A-J):"; //get shot from player one
            string shotColStr;
            char shotColumn;
            cin >> shotColStr;
            shotColumn = getUserLetter(shotColStr);
            shotColumn = toupper(shotColumn);
            
            while (colLetter < shotColumn)//loop to turn letter for column into integer to place ship on grid
            {
                colLetter++;
                originCol++;
            }
            cout << "Row (1-9): ";
            int shotRow;
            cin >> shotRow;

            
            is_Hit = game->isHit(shotRow, originCol, grid);//check if hit or miss
            
            if (is_Hit)
            {
                p1HitsLeft--;
            }

            return is_Hit;
}
