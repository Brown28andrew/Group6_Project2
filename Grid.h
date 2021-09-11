#ifndef GRID_H
#define GRID_H

// The storage of the grid changes
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
		bool setShip(int tRow, int tCol);
		
		/**
		* @pre: passed inputs represent valid location on the board.
		* @return: value at P1_array_grid[tRow][tCol]
		* @param: tRow and tCol, target row and column respectively
		*/
		char getValue(int tRow, int tCol);

		/**
		* @pre: passed int tRow and int tCol
		* @return: true or false 
		* @param: tRow and tCol, target row and column respectively
		*/
		bool checkForValidPlacedCoordinates(int tRow, int tCol);

		/**
		* @pre: array, user input row and input col
		* @return: print the grid with the ships
		* @param: tRow and tCol, target row and column respectively
		*/
		void printUserGrid(int tRow, int tCol);

    private:
        char** P1_array_grid; 
        //char** P2_array_grid;
		const int rows = 9;
        const int columns = 10;
        char ships = 'S';
        char hit_ship = 'H';
        char miss_ship = 'M';
};
#endif