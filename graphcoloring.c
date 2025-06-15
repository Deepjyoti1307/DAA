#include <stdio.h>

#define MAX 20

int G[MAX][MAX]; // Adjacency matrix
int color[MAX];  // Stores color assigned to each vertex
int n, m;        // n = vertices, m = number of colors

// Function to read number of vertices, edges and adjacency matrix
void readGraph()
{
    int e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j] = 0;

    // Input edges
    printf("Enter edges (start end) as 0-based indices:\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1; // Undirected graph
    }

    // Initialize colors to 0
    for (int i = 0; i < n; i++)
        color[i] = 0;
}

// Function to check if current color assignment is valid
int isSafe(int vertex, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (G[vertex][i] && color[i] == c)
            return 0;
    }
    return 1;
}

// Backtracking function to assign colors
int nextcolor(int vertex)
{
    if (vertex == n)
        return 1; // All vertices colored

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, c))
        {
            color[vertex] = c;
            if (nextcolor(vertex + 1))
                return 1;
            color[vertex] = 0; // Backtrack
        }
    }
    return 0; // No color can be assigned
}

// Function to display result
void displaycolor()
{
    printf("\nColors assigned to vertices:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

// Main function
int main()
{
    readGraph();
    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    if (nextcolor(0))
    {
        displaycolor();
    }
    else
    {
        printf("Solution not possible with %d colors.\n", m);
    }

    return 0;
}
