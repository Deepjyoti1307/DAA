#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX]; // Stores the column positions for queens

// Function to read number of queens
int readNumberOfQueens()
{
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);
    return n;
}

// Function to check if a queen can be placed at board[row] = col
int place(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        // Check column and diagonal conflict
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}
// Prototype for display function
void display(int n);

// Recursive backtracking function to solve N-Queens
void queen(int row, int n, int *solutionCount)
{
    for (int col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            board[row] = col;
            if (row == n)
            {
                (*solutionCount)++;
                printf("\nSolution %d:\n", *solutionCount);
                display(n);
            }
            else
            {
                queen(row + 1, n, solutionCount);
            }
        }
    }
}

// Function to display the solution as table and vector
void display(int n)
{
    printf("Queen Positions (Row: Column): ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d:%d ", i, board[i]);
    }
    printf("\n");

    // Print board
    printf("Chessboard:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

int main()
{
    int n = readNumberOfQueens();
    int solutionCount = 0;

    queen(1, n, &solutionCount);

    if (solutionCount == 0)
        printf("No solutions exist for N = %d\n", n);
    else
        printf("\nTotal Solutions Found: %d\n", solutionCount);

    return 0;
}
