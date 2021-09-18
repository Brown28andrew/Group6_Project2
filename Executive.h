#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Grid.h"
#include "Game.h"
#include <string>

class Executive {
    public:
	/**
	* @pre: none
	* @post: 2 Grid object pointers (1 per player) and 1 Game object pointers are initialized.
	*/
    Executive();
	
	/**
	* @pre: none
	* @post: All object pointers are deleted.
	*/
    ~Executive();
	
	/**
	* @brief: players are welcomed to the game and asked how many ships they would like to play with.
	* @pre: none
	* @post: Number of ships established, both player's ships are placed by calling placeShips, playGame method is called.
	*/
    void BeginGame();
	
	/**
	* @brief: This function handles the game's turns and player inputs per turn.
	* @pre: P1 and P2 must be initialized, with ships already placed.
	* @post: p1HitsLeft or p2HitsLeft is reduced to 0, endTheGame method is called.
	*/
    void playGame(Grid* P1, Grid* P2);
	
	/**
	* @pre: numShips must be between 1 and 6
	* @post: All player ships are placed
	*/
    void placeShips (int numShips, Grid* playerGrid);
	
	/**
	* @brief: "clears" the terminal screen by printing newlines.
	*/
	void clearScreen();
	
	/**
	* @
    char getUserLetter(std::string input);
	
	/**
	* @pre: p1HitsLeft or p2HitsLeft = 0
	* @post: game's winner printed to terminal, program ends.
	*/
	void endTheGame();
	
	/**
	* @pre:
	*/
	void nextTurn(bool is_hit);

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
	int turnCounter = 0;
    Grid* player1;
    Grid* player2;
    Game* game;


};
#endif