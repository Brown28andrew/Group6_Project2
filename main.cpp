#include <iostream>
#include "Grid.h"
#include "Executive.h"
#include <unistd.h>

using namespace std;

int main()
{
  //Initializes an array to store the users options
  //gameState[0] represents the number of games the user wants to play
  //gameState[1] represents whether or not the user wants to play with a bot
  //gameState[2] represents which game in your n-series you're currently playing
  //gameState[3] represents the number of wins player 1 has in your n-series of games
  //gameState[4] represents the number of wins player 2 has in your n-series of games
  //This array is passed to the Executive class where each of these states represents an option that determines the setup of your game.
  //In order for the user's game of battleship to begin, the user must answer each of these options.
  int* gameState = new int[5];		//[Wanted # of Games, Bot?, CurGame, P1Wins, P2Wins]
										//Bot? 0 = No bot, 1-3 = difficulty
										//CurGame starts at 1, Both players' wins start at 0
	gameState[2] = 1;
	gameState[3] = 0;
	gameState[4] = 0;

  //Displaying menu for users, along with a legend for symbols used in the game.

	cout << "\n----------------------------------------------------------\n";
    cout << "WELCOME TO THE BATTLESHIP GAME BY TEAM-18\n";
    cout << "And expanded by Zach Sambol, Raj Nara, Truman Klenklen, Andrew Brown, and Drew Fink!" << endl;
    sleep(2);
    cout << "----------------------------------------------------------\n";
    cout << "\nBelow are the some symbols which will be used during the game.\n";
    cout << "The symbol for ships: | or -\n";
    cout << "The symbol for when ships are hit: H\n";
    cout << "The symbol for when shots are missed: M\n";

  //Variable used to determine valid input from the user
  //as long as validAns is false, the user will be prompted for input
  //input is prompted for playing a bot, the difficulty of the bot, and asking the user if they want to play multiple games.
	bool validAns = false;

//loop that won't stop until the user gives a valid answer to pre-game question
//Prompts the user if they want to play against a bot
//if user answers "y" or "Y" indicating yes, they will be prompted to select a difficulty
//when prompted with difficulty, user must enter an integer between 1-3
//game will only continue once a valid difficulty for the bot has been selected
//if user answers "n" or "N" indicating no, loop will exit and continue to the next prompt
  do
	{
		char botQ;
		int difficulty = 0;
		bool validDif = false;

		cout << "\nDo you want to play against a bot? (y/n): ";
		std::cin >> botQ;

		if (botQ == 'Y' || botQ == 'y')
    {
      gameState[1] = 1;
      validAns = true;
      do{
        cout << "\nSelect Difficulty (Easy: 1 , Medium: 2, Hard: 3): ";
        cin >> difficulty;
        if(difficulty > 3 || difficulty < 1){
          cout << "\nThat difficulty doesn't exist" << endl;
        }else{
          validDif = true;
				  gameState[1] = difficulty;
        }
      }while(validDif != true);
    }
    else if (botQ == 'N' || botQ == 'n')
    {
      gameState[1] = 0;
      validAns = true;
    }
    else
    {
      cout << "Come on, this really isn't a tough question..." << endl;
    }
	}while (!validAns);

	validAns = false;

  //loop that won't stop until the user gives a valid answer to pre-game question

	do
	{
		char seriesQ;
		int games = 0;
		bool validSeries = false;

		cout << "\nDo you want to play a 'best-of-N' series? (y/n): ";
		std::cin >> seriesQ;

		if (seriesQ == 'Y' || seriesQ == 'y')
    {
      validAns = true;
      do{
        cout << "\nChoose the number you'll play to (must be odd, first to win majority wins, min: 3): "; // Odd numbers would result in ties, and those are no fun
        cin >> games;
        if((games % 2) == 0 || games < 3){
          cout << "\nInvalid number of games. Try again." << endl;
        }else{
          validSeries = true;
				gameState[0] = games;
        }
      }while(validSeries != true);
    }
        else if (seriesQ == 'N' || seriesQ == 'n')
        {
            gameState[0] = 1;
            validAns = true;
        }
        else
        {
            cout << "Is saying yes or no really that hard? Come on..." << endl;
        }
	}while (!validAns);

	Executive* gameRunner = new Executive(gameState);
  gameRunner->BeginGame();
	delete gameRunner;

	if(gameState[0] != 1) { // If we're playing a best-of-N series (i.e. games to be played is more than 1)
		do {
			gameState[2]++; // Current game # being played.
			cout << "\nBeginning game #" << gameState[2] << " in best of " << gameState[0];
			sleep(2);
			gameRunner = new Executive(gameState);
			gameRunner->BeginGame();
			delete gameRunner;

		}while((((gameState[0]/2 + 1) == gameState[3]) || ((gameState[0]/2 + 1) == gameState[4])) == 0);
    // This will run until one player has won a majority (number divided by two plus one) games.


		int winner = 1;
		if(gameState[4] > gameState[3]) {
			winner = 2;
		}
		cout << "\nOverall winner is Player " << winner;
		sleep(4);
	}

	cout << "\nThanks for playing our game!";

	delete [] gameState;
    return (0);
}
