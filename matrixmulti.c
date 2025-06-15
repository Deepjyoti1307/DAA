#include <stdio.h>
#include <limits.h>

#define MAX 100

int m[MAX][MAX]; // Cost matrix
int s[MAX][MAX]; // Split matrix
int p[MAX];      // Dimensions of matrices

// b) Function to generate cost matrix
void costmatrix(int n)
{
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    { // l is chain length
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// c) Function to return minimum scalar multiplications
int multiplication(int n)
{
    return m[1][n];
}

// d) Function to print optimal parenthesis structure
void optimalsequence(int i, int j)
{
    if (i == j)
    {
        printf("M%d", i);
    }
    else
    {
        printf("(");
        optimalsequence(i, s[i][j]);
        optimalsequence(s[i][j] + 1, j);
        printf(")");
    }
}

// a) Main function
int main()
{
    int n;

    printf("Enter number of matrices (n > 1): ");
    scanf("%d", &n);

    printf("Enter %d dimensions: \n", n + 1);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    costmatrix(n);
    int minCost = multiplication(n);

    printf("\nMinimum number of scalar multiplications: %d\n", minCost);
    printf("Optimal Parenthesization Sequence: ");
    optimalsequence(1, n);
    printf("\n");

    return 0;
}
