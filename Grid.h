#ifndef GRID_H
#define GRID_H
#include "Executive.h"
// The storage of the grid changes
class Grid {
    public:
        char** P1_array_grid; 
        char** P2_array_grid;
        ~Grid();
        Grid();

    private:
        const int rows = 9;
        const int columns = 10;
        char ships = 'S';
        char hit_ship = 'H';
        char miss_ship = 'M';
};
#endif