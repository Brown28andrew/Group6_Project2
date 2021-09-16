#ifndef GAME_H
#define GAME_H
#include "Grid.h"
// This is what controls grid and gives it the commands 
class Game {
    public:
	
	/**
	* @pre: tRow and tCol are within the boundaries of the game board.
	* @post: tGrid's m_grid[tRow][tCol] is updated to H if hit, M if miss, and hitsLeft is decremented if hit.
	* @return: true if hit, false if miss
	*/
	bool isHit(int tRow, int tCol, Grid* tGrid);
	
	/**
	* @return: true if hitsLeft = 0, false otherwise
	*/
	bool getEndGame(int hitsLeft);
	
	/**
	* @brief: assigns (n(n+1))/2 to hitsLeft, where n = number of ships per player.
	*/
	int setHitsLeft(int shipNum);
	
	
	
    private:
	
	//number that decrements with each hit, down to 0.
	int hitsLeft;
};
#endif