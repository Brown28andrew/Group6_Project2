#ifndef GAME_H
#define GAME_H
#include "Grid.h"

#include <string>

/**
* @brief this class handles all game rules related to Battleship, including setting the number of hits to win,
*         checking if a player's shot input hits a ship, and if the game's win condition
*         has been met.
* @authors Nifemi Fadahunsi, Michael Lane, Yuri Martinez, Anna Burns, Rokunuzjahan Rudro
*/
class Game {
    public:
	
	/**
	* @brief verifies that player's shot inputs are valid, then checks if the shot was a hit or miss.
	*
	* This function first makes sure that tRow and tCol are within the boundaries of the board, then
	* makes sure that the board location at (tCol, tRow) has not been fired at already. If the inputs are
	* valid, the function then calls Grid's setValue function to assign H (if it's a hit) or M (if it's a miss)
	* at (tCol, tRow).
	*
	* @pre none
	* @post tGrid's m_grid[tRow][tCol] is updated to H if hit, M if miss.
	* @return true if hit, false if miss.
	* @param tRow the target row the player is firing at.
	* @param tCol the target column the player is firing at.
	* @param tGrid the game board being fired at.
	*/
	bool isHit(int tRow, int tCol, Grid* tGrid);
	
	/**
	* @brief checks if the opponent has any more untouched ship spaces.
	* @return true if hitsLeft = 0, false otherwise.
	* @param hitsLeft the number of ship spaces that have not been hit yet.
	*/
	bool getEndGame(int hitsLeft);
	
	/**
	* @brief determines how many hits each player has to earn in order to win.
	* @return (shipNum(shipNum+1))/2
	* @param shipNum the number of ships each player has placed.
	*/
	int setHitsLeft(int shipNum);

	/**
	* @brief called when the location is an invalid location and takes in a new column
	* @return integer of column value
	*/
	int invalidInput ();
	
	/**
	* @brief ensures that the player's column input is one char and returns that char.
	* @pre none
	* @return first char in input
	* @param input the string for player's column input
	*/
	char getColumnLetter(std::string input);
	
    private:

};
#endif