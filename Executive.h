#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Grid.h"

class Executive {
    public:
    Executive();
    ~Executive();
    void BeginGame();
    void playGame();
    void placeShips (int numShips, Grid* playerGrid);

    private:
    char col;
    int originRow;
    char direction;
    int shipsize;
    int originCol = 1;
    char colLetter = 'A';
    int numShips;
    Grid* player1;


};
#endif