#include "Executive.h"
#include "Grid.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

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
    cout << "And expanded by Zach Sambol, Raj Nara, Truman Klenklen, Andrew Brown, and Drew Fink!" << endl;
    sleep(2);
    cout << "----------------------------------------------------------\n";
    cout << "\nBelow are the some symbols which will be used during the game.\n";
    cout << "The symbol for ships: | or -\n";
    cout << "The symbol for when ships are hit: H\n";
    cout << "The symbol for when shots are missed: M\n";

    do
	{
		cout << "\nDo you want to play against a bot? (y/n): ";
		std::cin >> botQ;

		if (botQ == 'Y' || botQ == 'y')
        {
            player2Bot = true;
            validAns = true;
            do{
              cout << "\nSelect Difficulty (Easy: 1 , Medium: 2, Hard: 3): ";
              cin >> difficulty;
              if(difficulty > 3 || difficulty < 1){
                cout << "\nThat difficulty doesn't exist" << endl;
              }else{
                validDif = true;
              }
            }while(validDif != true);
        }
        else if (botQ == 'N' || botQ == 'n')
        {
            player2Bot = false;
            validAns = true;
        }
        else
        {
            cout << "Come on, this really isn't a tough question..." << endl;
        }
	}while (!validAns);

    cout << "\nHow many ships would you like to have in the game?\nNumber of ships (1-6): ";
    std::cin >> numShips;
    while (std::cin.fail() || numShips > 6 || numShips <= 0)
    {
        cout << "Invalid number of ships. Please try again. Number of ships (1-6): " ;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> numShips;
    }

    p1HitsLeft = game->setHitsLeft(numShips);
    p2HitsLeft = game->setHitsLeft(numShips);

	string userInput;
    char readiness;

	cout << "\nPlayer 1 places their ships first.";
    player1->print_ships_Grid();
    placeShips(numShips, player1);

	clearScreen();
    cout << "\nAll ships placed for player 1!\n";

	std::cin.ignore(256, '\n');

    if(!player2Bot)
    {
        do
        {
            cout << "\nPlayer 2, are you ready to place your ships? (enter Y to continue)\n";
            std::cin >> userInput;
            readiness = getUserLetter(userInput);

            if (readiness != 'Y' && readiness != 'y')
                cout << "\nError, please enter 'Y' or 'y' to continue.\n";
        }while (readiness != 'Y' && readiness != 'y');

        player2->print_ships_Grid();
        placeShips(numShips, player2);

        clearScreen();
        cout << "\nAll ships placed for player 2!\n";
        sleep(2);

        std::cin.ignore(256, '\n');
    }
    else
    {
        botShips(numShips);
        cout << "\nThe bot has placed its ships!\n";
    }

	do
	{
		cout << "\nPlayer 1, are you ready to start the game? (enter Y to continue)\n";
		std::cin >> userInput;
		readiness = getUserLetter(userInput);

		if (readiness != 'Y' && readiness != 'y')
			cout << "\nError, please enter 'Y' or 'y' to continue.\n";
	}while (readiness != 'Y' && readiness != 'y');

    playGame(player1, player2);
}

void Executive::placeShips(int numShips, Grid* playerGrid)
{
	bool isPlaced = false;
	string userInput;

    for (int i = 0; i < numShips; i++)//loop to place ships on board
    {
		isPlaced = false;

        do {
            originCol = 1;
            colLetter = 'A';

            cout << "\nWhere would you like to place the origin of ship "<< i+1 << "?\nColumn (A-J): ";
            string userCol;
            std::cin >> userCol;
            col = getUserLetter(userCol);
            col = toupper(col);
                while (colLetter < col)//loop to turn letter for column into integer to place ship on grid
                {
                    colLetter++;
                    originCol++;
                }
            cout << "Row (1-9): ";
            std::cin >> originRow;
            while (std::cin.fail() || isalpha(originRow))
            {
                cout << "Invalid row input! please enter an integer between 1 and 9: " ;

                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> originRow;
            }

            if (i != 0)
            {
                cout << "Ship " << i+1 << " will take up " << i+1 << " spaces, which direction would you like to orient the ship? (U, D, L, R)\nDirection: ";
                std::cin >> userInput;
				direction = getUserLetter(userInput);
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

void Executive::botShips(int numShips)
{
	bool isPlaced = false;
	string userInput;

    for (int i = 0; i < numShips; i++)//loop to place ships on board
    {
        char columns[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
        char cardinalDir[4] = {'U', 'D', 'L', 'R'};
		isPlaced = false;

        do {
            originCol = 1;
            colLetter = 'A';

            srand(time(NULL)); // This is necessary because your rand() is always the same unless you do this or restart the program. We base our random seed off the time.
            int selection = rand() % 10;
            col = columns[selection];

            while (colLetter < col)//loop to turn letter for column into integer to place ship on grid
            {
                colLetter++;
                originCol++;
            }

            srand(time(NULL)); // We can't exactly restart the program so we regenerate the random seed.
            originRow = (rand() % 10);

            if (i != 0)
            {
                srand(time(NULL));
                int dirSelect = rand() % 4; // There are four directions.
				direction = cardinalDir[dirSelect];
            }

            else
                direction = 'U';

            shipsize = i+1;

            if(isalpha(col))
                isPlaced = player2->setShip(originRow,originCol,direction,shipsize);

        }while (isPlaced == false);
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

            if (is_Hit)
            {
                p2HitsLeft--;
            }
            gameEnd = game->getEndGame(p2HitsLeft);//check if game end
            turnCounter++;
        }
        else if (player2Bot)
        {
            is_Hit = playerBotShoot(difficulty);
            gameEnd = game->getEndGame(p1HitsLeft);//check if game end
            turnCounter++;
        }
        else
        {
            clearScreen();
            P1->print_shots_Grid(); //print player ones shot grid
            P2->print_ships_Grid();//print player ones ship grid

            is_Hit = getShot(P1, 2);

            if (is_Hit)
            {
                p1HitsLeft--;
            }

            gameEnd = game->getEndGame(p1HitsLeft);//check if game end
            turnCounter++;
        }

		if (!gameEnd)
			nextTurn(is_Hit, isSunk);
    }

	endTheGame();
}

void Executive::endTheGame()
{
	cout << "\nPlayer " << ((turnCounter - 1) % 2) + 1 << " wins!";
    sleep(2);

	cout << "\n\nThank you for playing our game. Goodbye!\n\n";
}

void Executive::nextTurn(bool is_hit, bool is_Sunk)
{
	char c;
	string userInput;
	clearScreen();

	if (isSunk)
		{cout << "Hit, sunk!";}

    else if (is_hit)
        {cout << "Hit!";}

	else
		{cout << "Miss!";}

	std::cin.ignore(256, '\n');

	cout << "\n\nIs player " << (turnCounter % 2) + 1 << " ready? (Enter Y to continue): ";

	do
	{
		std::cin >> userInput;
		c = getUserLetter(userInput);

		if (c != 'Y' && c != 'y')
			cout << "Invalid input! please enter Y when the next player is ready: ";
	} while (c != 'Y' && c!= 'y');

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
        cout << "Error, please enter a valid input: ";
        std::cin >> input;
    }
    col = input.at(0);
    col = toupper(col);
    return col;
}

bool Executive::getShot(Grid* grid, int n) {
            originCol = 1;
            colLetter = 'A';
            bool is_Hit;
            isSunk = false;
            int num;

            sleep(2);
            cout << "Where would you like to take your shot Player " << n << "?\nColumn (A-J):"; //get shot from player one
            string shotColStr;
            char shotColumn;
            std::cin >> shotColStr;
            shotColumn = getUserLetter(shotColStr);
            shotColumn = toupper(shotColumn);

            while (colLetter < shotColumn)//loop to turn letter for column into integer to place ship on grid
            {
                colLetter++;
                originCol++;
            }
            cout << "Row (1-9): ";
            int shotRow;
            std::cin >> shotRow;
            while (std::cin.fail() || isalpha(originRow))
            {
                cout << "invalid row input! please enter an integer between 1 and 9: " ;

                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> shotRow;
            }
			if (shotRow <= 9 && shotRow >= 1)
				num = grid->getShadow(shotRow, originCol);

            is_Hit = game->isHit(shotRow, originCol, grid);//check if hit or miss

			if (is_Hit)
            {
                isSunk = game->checkSunk(grid, num);
            }


            return is_Hit;
}

bool Executive::playerBotShoot(int dif)
{
    char botCol;
    int botColInt;
    int botRow;
    int num;
    bool is_Hit;
    isSunk = false;
    originCol = 1;
    colLetter = 'A';

    if(dif == 1)
    {
        do
        {
            srand(time(NULL));
            botColInt = rand() % 10; //Selects a random number between 0-9
            botCol = 'a' + botColInt; //Adds the value to 'a' to get the column selected
            botCol = toupper(botCol);

            while(colLetter < botCol){
                colLetter++;
                originCol++;
            }

            srand(time(NULL));
            botRow = rand() % 9;
            botRow++;
            }while (player1->getValue(botRow, originCol) == 'M' || player1->getValue(botRow, originCol) == 'H'); // Ensure the bot doesn't strike anywhere it hasn't already

        num = player1->getShadow(botRow, originCol);
        is_Hit = game->isHit(botRow, originCol, player1);
        if(is_Hit == true)
        {
            isSunk = game->checkSunk(player1, num);
            p1HitsLeft--;
        }
    }
    
    else if(dif == 2)
    {
        int failCounter = 0; // To try and avoid the bot getting stuck, this is a counter of invalid moves it's tried to make.
        do
        {
            if(failCounter >= 25) // The worst has happened: the bot has gotten stuck. We will get it unstuck by taking it back to the first found block.
            {
                currentRow = failsafeRow;
                currentCol = failsafeCol;
                failCounter = 0;
            }

            botRow = currentRow; // This is necessary for our if statements below.
            if(botFoundShip)
            {
                char cardinalDir[4] = {'U', 'D', 'L', 'R'};
                srand(time(NULL));
                int dirSelect = rand() % 4; // There are four directions. We choose one to go in.

				if(cardinalDir[dirSelect] == 'U' && currentRow > 0)
                {
                    botRow = currentRow - 1;
                    originCol = currentCol;
                }
                else if(cardinalDir[dirSelect] == 'L' && originCol > 0)
                {
                    originCol = currentCol - 1;
                    botRow = currentRow;
                }
                else if(cardinalDir[dirSelect] == 'R' && originCol < 10)
                {
                    originCol = currentCol + 1;
                    botRow = currentRow;
                }
                else if(cardinalDir[dirSelect] == 'D' && currentRow < 10)
                {
                    botRow = currentRow + 1;
                    originCol = currentCol;
                }
            }
            else // If we haven't found a place, we just randomly guess
            {
                srand(time(NULL));
                botColInt = rand() % 10; //Selects a random number between 0-9
                botCol = 'a' + botColInt; //Adds the value to 'a' to get the column selected
                botCol = toupper(botCol);

                while(colLetter < botCol){
                    colLetter++;
                    originCol++;
                }

                srand(time(NULL));
                botRow = rand() % 9;
                botRow++;
            }
        }while (player1->getValue(botRow, originCol) == 'M' || player1->getValue(botRow, originCol) == 'H'); // Ensure the bot doesn't strike anywhere it has already

        num = player1->getShadow(botRow, originCol);
        is_Hit = game->isHit(botRow, originCol, player1);
        if(is_Hit == true)
        {
            isSunk = game->checkSunk(player1, num);
            if(!isSunk)
            {
                if(failsafeCol == 0) // Set the failsafes up just once in case the bot backs itself into a corner
                {
                    failsafeCol = foundCol;
                }
                if(failsafeRow == 'Z')
                {
                    failsafeRow = foundRow;
                }
                botFoundShip = true;
                foundCol = originCol;
                foundRow = botRow;
                currentCol = originCol;
                currentRow = botRow;
            }
            else // If we just sunk a ship, we reset everything.
            {
                botFoundShip = false;
                failsafeRow = 0;
                failsafeCol = 'Z';
            }
            p1HitsLeft--;
        }
        else if (botFoundShip && !is_Hit) // If we miss, we take a step back to figure out where we went wrong.
        {
            currentCol = foundCol;
            currentRow = foundRow;
        }
    }
    
    else if(dif == 3)
    {
        
    }

    return is_Hit;
}
