#include<iostream>
using namespace std;

bool getemptycell(int grid[9][9], int &row, int &col);

bool check(int grid[9][9], int row, int col, int num);

bool sudoku(int grid[9][9])
{
    int row, col;

    if (!getemptycell(grid, row, col))
       return true;

    for (int num = 1; num <= 9; num++)
    {
        if (check(grid, row, col, num))
        {
            grid[row][col] = num;
            if (sudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}


bool getemptycell(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool check(int grid[9][9], int row, int col, int num)
{

    for (int coli = 0; coli < 9; coli++)     // check if the number already exists in a row
        if (grid[row][coli] == num)
            return false;

    for (int rowi = 0; rowi < 9; rowi++)     // check if the number already exists in a column
        if (grid[rowi][col] == num)
          return false;

    int largecellrow=row-row%3;             // finding the starting position of 3x3 cell
    int largecellcol=col-col%3;

    for (int rowi = 0; rowi < 3; rowi++)    // check whether the number exists in that 3x3 cell
        for (int coli = 0; coli < 3; coli++)
            if (grid[rowi+largecellrow][coli+largecellcol] == num)
                return false;

    return true;
}

void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             cout<<"  "<<grid[row][col];
        cout<<"\n";
    }
}


int main()
{

    //CUSTOM GRID
     //cells fill from left to right then jump to the next row
     //empty cells are presented by 0
    /* int grid[9][9];
     for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
           cin>>grid[i][j];*/

    int grid[9][9] = {{0, 0, 0, 9, 8, 0, 0, 0, 5},
                      {0, 0, 5, 0, 0, 0, 7, 0, 0},
                      {0, 0, 0, 4, 0, 0, 3, 0, 6},
                      {0, 1, 0, 0, 0, 3, 9, 0, 0},
                      {5, 4, 0, 0, 9, 0, 0, 3, 1},
                      {0, 0, 9, 6, 0, 0, 0, 4, 0},
                      {8, 0, 3, 0, 0, 2, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 5, 0, 0},
                      {2, 0, 0, 0, 1, 4, 0, 0, 0}};


     //CUSTOM GRID
     //cells fill from left to right then jump to the next row
     //empty cells are presented by 0
    /* int grid[9][9];
     for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
           cin>>grid[i][j];*/



    if (sudoku(grid) == true)
          printGrid(grid);
    else
         cout<<"no solution";

    return 0;
}
