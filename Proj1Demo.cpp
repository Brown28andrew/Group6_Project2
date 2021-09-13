#include <iostream>
#include <fstream>
//#include <string>

{
    // Just variables that aren't really needed and the same type are created accros the 3 classes. 
int main()
{
    const int ship1Spaces = 1;
    const int ship2Spaces = 2;
    const int ship3Spaces = 3;
    const int ship4Spaces = 4;
    const int ship5Spaces = 5;
    const int ship6Spaces = 6;
    const int rows = 10;
    const  int cols = 11;

    int numShips = 0;
    char rowNum = '1'; //char to increment row indicator
    char colLetter = 'A'; //char to increment column indicator
    char grid[rows][cols]; //creates the grid
}  
{
    // This is now all managed by the constructor of grid class - Nifemi

    for (int i = 0; i < rows; i++) // loop to fill grid with row/col indicator and unused positions
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                grid[i][j] = ' ';
            }
            else if (i == 0 && j != 0)
            {
                grid[i][j] = colLetter;
                colLetter++;
            }
            else if (j == 0 && i != 0)
            {
                grid[i][j] = rowNum;
                rowNum++;
            }
            else if (i != 0 && j != 0)
            {
                grid[i][j] = '*';
            }
        }

    }
}

{
    // this should be managed by constructor I believe - Nifemi
    std::cout << "Original Board\n";

    for (int i = 0; i < rows; i++) //loop to print board with no ships
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << grid[i][j];
            std::cout << " ";
        }
        std::cout << "\n";
    }
} 
{
    // this is managed by new game in executive -Nifemi
    std::cout << "How many ships would you like to have in the game?\nNumber of ships (1-6): ";
    std::cin >> numShips;

    char col;
    int originRow;
    char direction;
    int originCol = 0;
    for (int i = 0; i < numShips; i++)//loop to place ships on board
    {
        col = ' ';
        originRow = 0;
        direction = ' ';
        originCol = 0;
        colLetter = 'A';
        std::cout << "Where would you like to place the origin of ship "<< i+1 << "?\nColumn (A-J): ";
        std::cin >> col;
        while (colLetter <= col)//loop to turn letter for column into integer to place ship on grid
        {
            colLetter++;
            originCol++;
        }
        std::cout << "Row (1-9): ";
        std::cin >> originRow;
        std::cout << "Ship " << i+1 << " will take up " << i+1 << " spaces, which direction would you like to orient the ship? (U, D, L, R)\nDirection: ";
        std::cin >> direction;

        if (direction == 'U')//conditionals to place ship in correct direction
        {
            for(int j=0; j < i+1; j++){
                grid[originRow-j][originCol] = '|'; 
            }
        }

        if (direction == 'D')
        {
            for(int j=0; j < i+1; j++){
                grid[originRow+j][originCol] = '|'; 
            }
        }

        if (direction == 'L')
        {
            for(int j=0; j < i+1; j++){
                grid[originRow][originCol-j] = '-'; 
            }
        }

        if (direction == 'R')
        {
            for(int j=0; j < i+1; j++){
                grid[originRow][originCol+j] = '-'; 
            }
        }

        std::cout << "\nUpdated Board\n";
}
{
    // This is managed by print user grid in grid.cpp - Nifemi

        for (int j = 0; j < rows; j++)//loop to print updated board
        {
            for (int k = 0; k < cols; k++)
            {
                std::cout << grid[j][k];
                std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    
    return 0;
}