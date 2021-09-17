#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Grid.h"
#include "Game.h"

class Executive {
    public:
    Executive();
    ~Executive();
    void BeginGame();
    void playGame(Grid* P1, Grid* P2);
    void placeShips (int numShips, Grid* playerGrid);
	void clearScreen();
	
	/**
	* @pre: p1HitsLeft or p2HitsLeft = 0
	* @post: game's winner printed to terminal, program ends.
	*/
	void endTheGame();

    private:
    char col;
    int originRow;
    char direction;
    int shipsize;
    int originCol = 1;
    char colLetter = 'A';
    int numShips;
    int p1HitsLeft;
    int p2HitsLeft;
    Grid* player1;
    Grid* player2;
    Game* game;


};
#endif