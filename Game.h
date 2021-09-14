#ifndef GAME_H
#define GAME_H
#include "Grid.h"
// This is what controls grid and gives it the commands 
class Game {
    public:
	
	/**
	* @brief: calls for getValue() at grid[tRow][tCol], verifies if it's a hit or a miss,
	*         updates value at that location, and updates hitsLeft and endGame if needed.
	* @return: true if hit, false if miss
	*/
	bool isHit(int tRow, int tCol, Grid tGrid);
	
	/**
	* @return: true if hitsLeft = 0, false otherwise
	*/
	bool getEndGame();
	
	/**
	* @brief: assigns (n(n+1))/2 to hitsLeft, where n = number of ships per player.
	*/
	void setHitsLeft(int shipNum);
	
	
	
    private:
	
	//number that decrements with each hit, down to 0.
	int hitsLeft;
};
#endif