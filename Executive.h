#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Grid.h"
#include "Game.h"
#include <string>

/**
* @brief This class handles all inputs and outputs to be passed to Game or Grid classes.
* @authors Nifemi Fadahunsi, Michael Lane, Yuri Martinez, Anna Burns, Rokunuzjahan Rudro
*/
class Executive {
    public:
	/**
	* @pre none
	* @post 2 Grid object pointers (1 per player) and 1 Game object pointers are initialized.
	*/
    Executive();

	/**
	* @pre none
	* @post All object pointers are deleted.
	*/
    ~Executive();

	/**
	* @brief players are welcomed to the game and asked how many ships they would like to play with.
	* @pre none
	* @post Number of ships established, both player's ships are placed by calling placeShips method, playGame method is called.
	*/
    void BeginGame();

	/**
	* @brief This function handles the game's turns and player inputs per turn.
	* @pre P1 and P2 must be initialized, with ships already placed.
	* @post p1HitsLeft or p2HitsLeft is reduced to 0, endTheGame method is called.
	* @param P1 pointer to player 1's Grid object
	* @param P2 pointer to player 2's Grid object
	*/
    void playGame(Grid* P1, Grid* P2);

	/**
	* @brief takes inputs and passes them to Grid class's setShip method in order to place one player's ships.
	* @pre numShips must be between 1 and 6
	* @post All ships are placed for one player.
	* @param numShips number of ships to be placed per player.
	* @param playerGrid pointer to one player's Grid object.
	*/
    void placeShips (int numShips, Grid* playerGrid);

	/**
	* @brief takes inputs and passes them to Grid class's setShip method in order to place one player's ships.
	* @pre numShips must be between 1 and 6
	* @post All ships are placed for one player.
	* @param numShips number of ships to be placed per player.
	*/
    void botShips(int numShips);

	/**
	* @brief "clears" the terminal screen by printing newlines.
	*/
	void clearScreen();

	/**
	* @brief ensures that the player's column input is one char and returns that char.
	* @pre none
	* @return first char in input
	* @param input the string for player's column input
	*/
    char getUserLetter(std::string input);

	/**
	* @brief handles the output to terminal when the game ends.
	* @pre p1HitsLeft or p2HitsLeft = 0
	* @post game's winner printed to terminal, program ends.
	*/
	void endTheGame();

	/**
	* @brief prints whether the current player's shot was a hit or miss,
	*         then waits for next turn's player's input that they're ready.
	* @param is_hit indicates whether current player's shot was a hit(true)
	*         or a miss(false)
	*/
	void nextTurn(bool is_hit, bool is_Sunk);

	/**
	* @brief takes in the input for where the user would like to shoot and returns if the spot is a hit or miss
	* @param grid takes in the grid to check the shot in
	* @param n takes in the player number
	* @return bool whether the spot is a hit or miss
	*/
	bool getShot (Grid* grid, int n);

  /**
  *@brief Based on the difficulty, the bot will fire at the other players grid and get a hit or miss
  *@param dif takes in the difficulty of the bot to see if it shoot random, only hits, or tactically when it gets a hit
  *@post Updates is_hit if the shot hit or not
  */
  bool playerBotShoot (int dif);

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
	  bool isSunk = false;
	  bool player2Bot = false;
    Grid* player1; //
    Grid* player2;
    Game* game;
    char botQ;
    bool validAns = false;
    int difficulty = 0;
    bool validDif = false;

	bool botFoundShip = false;
	int failsafeCol = 0;
	char failsafeRow = 'Z';
	int foundCol = 0;
	char foundRow = 'Z';
	int currentCol = 0;
	char currentRow = 'Z';
	char dirsTried[4] = {};
	bool sunkFoundShip = false;
	
	int d3Rerow= 0;
	int d3Recol= 0;
};
#endif
