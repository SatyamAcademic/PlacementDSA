// C code to implement N queens problem using backtracking.
// The N queens problem is a classic problem in which the goal is to place N queens on an N x N chessboard such that no two queens threaten each other. This means that no two queens can be in the same row, column, or diagonal.
// The logic is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. If there is no clash, we move on to place the next queen. If we cannot place a queen in any row in the current column, we backtrack and move the previously placed queen to the next possible position.
// The process continues until all queens are placed on the board or we have tried all possible placements and found that no solution exists.
// The time complexity of this algorithm is O(N!), as in the worst case, we may have to explore all possible arrangements of queens on the board.
// Note: The value of N can be changed to solve for different sizes of the chessboard and number of queens.
// Example: For N = 4, the output will be a 4x4 board with 1s representing the positions of the queens and 0s representing empty spaces.
// For N = 4, the output will be:
//  0  1  0  0
//  0  0  0  1
//  1  0  0  0
//  0  0  1  0
// This indicates that the queens are placed in such a way that they do not threaten each other.

#include <stdio.h>
#define N 4
int board[N][N];
int isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}
int solveNQUtil(int col)
{
    if (col >= N)
        return 1;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
int main()
{
    if (solveNQUtil(0) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }
    printSolution();
    return 0;
}
