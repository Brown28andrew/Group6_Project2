#ifndef GRID_H
#define GRID_H

class Grid {
    public:
		/**
		* @pre: none
		* @post: P1_array_grid made with initial value 'O' in each board position.
		*/
        Grid();
		
		/**
		* @pre: none
		* @post: P1_array_grid is deleted
		*/
        ~Grid();
		
		/**
		* @pre: Player inputs represent a valid location on the board.
		* @post: 'S' assigned to P1_array_grid[tRow][tCol] to denote 1x1 ship location
		* @return: true if 'S' assigned successfully, false otherwise.
		* @param: tRow and tCol, target row and column respectively
		*/
		bool setShip(int tRow, int tCol, char dir, int size);
		
		/**
		* @pre: tRow and tCol represent a valid location on the game board. and m_grid[tRow][tCol]
		* has not been fired on already.
		* @post: 'H' assigned to m_grid[tRow][tCol] if hitOrMiss = true, 'M' if hitOrMiss = false.
		* @param: tRow and tCol, target row and column respectively
		* @param: hitOrMiss, variable that signals if the player's shot is a hit or a miss.
		*/
		void setValue(int tRow, int tCol, bool hitOrMiss);
		
		/**
		* @pre: passed inputs represent valid location on the board.
		* @return: value at P1_array_grid[tRow][tCol]
		* @param: tRow and tCol, target row and column respectively
		*/
		char getValue(int tRow, int tCol);

		/**
		* @pre: none
		* @return: true if tRow and tCol represent a valid board position, false otherwises.
		* @param: tRow and tCol, target row and column respectively
		*/
		bool checkForValidPlacedCoordinates(int tRow, int tCol, int size);

		/**
		* @pre: none
		* @post: current turn's player's board printed to terminal
		*/
		void print_ships_Grid();
		
		/**
		* @pre: none
		* @post: opponent's board printed to terminal, where '|' and
		* '-' are replaced with '*'.
		*/
		void print_shots_Grid();
		
		/**
		* @pre: 1 <= tRow <= 9, 1 <= tCol <= 10, and m_grid, and
		* m_grid[tRow][tCol] == '*'.
		* @post: ship is placed and oriented above the origin location.
		* @return: true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param: tRow and tCol, row and column the ship's origin is placed.
		* @param: size, the number of spaces the ship will take up.
		*/
		bool checkUp(int tRow, int tCol, int size);
		
		/**
		* @pre: 1 <= tRow <= 9, 1 <= tCol <= 10, and m_grid, and
		* m_grid[tRow][tCol] == '*'.
		* @post: ship is placed and oriented below the origin location.
		* @return: true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param: tRow and tCol, row and column the ship's origin is placed.
		* @param: size, the number of spaces the ship will take up.
		*/
		bool checkDown(int tRow, int tCol, int size);
		
		/**
		* @pre: 1 <= tRow <= 9, 1 <= tCol <= 10, and m_grid, and
		* m_grid[tRow][tCol] == '*'.
		* @post: ship is placed and oriented to the right of the origin location.
		* @return: true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param: tRow and tCol, row and column the ship's origin is placed.
		* @param: size, the number of spaces the ship will take up.
		*/
		bool checkRight(int tRow, int tCol, int size);
		
		/**
		* @pre: 1 <= tRow <= 9, 1 <= tCol <= 10, and m_grid, and
		* m_grid[tRow][tCol] == '*'.
		* @post: ship is placed and oriented to the left of the origin location.
		* @return: true if ship is placed, false if ship would overlap another
		* or go off the board.
		* @param: tRow and tCol, row and column the ship's origin is placed.
		* @param: size, the number of spaces the ship will take up.
		*/
		bool checkLeft(int tRow, int tCol, int size);

    private:
		
		//game board for one player (each Grid object represents one player's board)
        char** m_grid;
		const int rows = 10;
        const int cols = 11;
        char hit_ship = 'H';
        char miss_ship = 'M'; 
};
#endif