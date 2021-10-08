#include <iostream>
#include "Grid.h"
#include "Executive.h"
#include <unistd.h>
//#include <math.h>

using namespace std;

int main()
{
	int* gameState = new int[5];		//[Wanted # of Games, Bot?, CurGame, P1Wins, P2Wins]
										//Bot? 0 = No bot, 1-3 = difficulty
										//CurGame starts at 1, Both players' wins start at 0
	gameState[2] = 1;
	gameState[3] = 0;
	gameState[4] = 0;
	
	cout << "\n----------------------------------------------------------\n";
    cout << "WELCOME TO THE BATTLESHIP GAME BY TEAM-18\n";
    cout << "And expanded by Zach Sambol, Raj Nara, Truman Klenklen, Andrew Brown, and Drew Fink!" << endl;
    sleep(2);
    cout << "----------------------------------------------------------\n";
    cout << "\nBelow are the some symbols which will be used during the game.\n";
    cout << "The symbol for ships: | or -\n";
    cout << "The symbol for when ships are hit: H\n";
    cout << "The symbol for when shots are missed: M\n";
	
	bool validAns = false;

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
	
	do
	{
		char seriesQ;
		int games = 0;
		bool validSeries = false;
		
		cout << "\nDo you want to play a 'Best of n' series? (y/n): ";
		std::cin >> seriesQ;

		if (seriesQ == 'Y' || seriesQ == 'y')
        {
            validAns = true;
            do{
              cout << "\nChoose the Max Number of Games to Play (Min:3, First to 2 wins): ";
              cin >> games;
              if((games % 2) == 0 || games < 3){
                cout << "\nThat difficulty doesn't exist" << endl;
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
            cout << "Come on, this really isn't a tough question..." << endl;
        }
	}while (!validAns);
	
	Executive* gameRunner = new Executive(gameState);
    gameRunner->BeginGame();
	delete gameRunner;

	if(gameState[0] != 1) {
		do {
			
			gameState[2]++;
			cout << "\nBeginning Game " << gameState[2] << " in best of " << gameState[0];
			sleep(2);
			gameRunner = new Executive(gameState);
			gameRunner->BeginGame();
			delete gameRunner;
			
		}while((((gameState[0]/2 + 1) == gameState[3]) || ((gameState[0]/2 + 1) == gameState[4])) == 0 );
		
		int winner = 1;
		if(gameState[4] > gameState[3]) {
			winner = 2;
		}
		cout << "\nOverall Winner is Player " << winner;
		sleep(4);
	}
	
	
	
	cout << "\nThanks for playing our game!";

	delete [] gameState;
    return (0);
}