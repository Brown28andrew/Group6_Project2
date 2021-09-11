#include <iostream>
#include <fstream>
//#include <string>

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

    std::cout << "Original Board\n";

    for (int i = 0; i < rows; i++) //loop to print baord with no ships
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << grid[i][j];
            std::cout << " ";
        }
        std::cout << "\n";
    }


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
        std::cout << "Where would you like to place the origin of ship 3?\nColumn (A-J): ";
        std::cin >> col;
        while (colLetter <= col)//loop to turn letter for column into integer to place ship on grid
        {
            colLetter++;
            originCol++;
        }
        std::cout << "Row (1-9): ";
        std::cin >> originRow;
        std::cout << "Ship 3 will take up 3 spaces, which direction would you like to orient the ship? (U, D, L, R)\nDirection: ";
        std::cin >> direction;

        if (direction == 'U')//conditionals to place ship in correct direction
        {
            grid[originRow][originCol] = '|';
            grid[originRow - 1][originCol] = '|';
            grid[originRow - 2][originCol] = '|';
        }

        if (direction == 'D')
        {
            grid[originRow][originCol] = '|';
            grid[originRow + 1][originCol] = '|';
            grid[originRow + 2][originCol] = '|';
        }

        if (direction == 'L')
        {
            grid[originRow][originCol] = '-';
            grid[originRow][originCol - 1] = '-';
            grid[originRow][originCol - 2] = '-';
        }

        if (direction == 'R')
        {
            grid[originRow][originCol] = '-';
            grid[originRow][originCol + 1] = '-';
            grid[originRow][originCol + 2] = '-';
        }

        std::cout << "\nUpdated Board\n";

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