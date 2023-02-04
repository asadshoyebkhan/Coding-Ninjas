/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.
Sample Sudoku for you to get the logic for its solution:

Example:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

Your Task:
You need to complete the two functions:
SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.
NOTE: Do not give a new line character after printing the grid. It has already been taken care of in the Driver Code.


Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).


Constraints:
0 ≤ grid[i][j] ≤ 9

*/

#define N 9
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    void printGrid(int grid[N][N])
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
    
    bool  findEmptyLocation(int grid [N][N],int &row,int &col)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    
    
    bool isSafeRow(int grid[N][N],int row,int num)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[row][i]==num)
            {
                return false;
            }
        }
        return true;
    }
    
    
    bool isSafeCol(int grid[N][N],int col,int num)
    {
        for(int i=0;i<N;i++)
        {
            if(grid[i][col]==num)
            {
                return false;
            }
        }
        return true;
    }
    
    
    bool isSafeGrid(int grid[N][N],int row,int col,int num)
    {
        int rowFactor=row-(row%3);
        int colFactor=col-(col%3);
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i+rowFactor][j+colFactor]==num)
                {
                    return false;
                }
    
            }
        }
        return true;
    }
    
    bool isSafe(int grid[N][N],int row,int col,int num)
    {
        if(isSafeRow(grid,row,num) && isSafeCol(grid,col,num) && isSafeGrid(grid,row,col,num))
        {
            return true;
        }
        return false;
    }
    
    bool solveSudoku(int grid[N][N])
    {
        int row,col;
        if(!findEmptyLocation(grid,row,col))
        {
            return true;
        }
    
        for(int i=1;i<=N;i++)
        {
            // findEmptyLocation se row,col me vo cell ka index aa jaega jispe ki value 0 hai 
            if(isSafe(grid,row,col,i))
            {
                grid[row][col]=i;
                if(solveSudoku(grid))
                {
                    return true;
                }
                grid[row][col]=0;
                 
            }
    
        }
        return false;
    }

    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solveSudoku(grid);
    }
    
    //Function to print grids of the Sudoku.

};

