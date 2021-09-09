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