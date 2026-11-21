#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int transpose[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// DFS to fill the stack
void dfs1(int v)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
            dfs1(i);
    }

    stack[++top] = v;
}

// DFS on transpose graph
void dfs2(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (transpose[v][i] && !visited[i])
            dfs2(i);
    }
}

// Find Strongly Connected Components
void findSCC()
{
    int i;

    // First DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs1(i);
    }

    // Create transpose graph
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            transpose[j][i] = graph[i][j];
    }

    // Reset visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");

    // Second DFS
    while (top != -1)
    {
        int v = stack[top--];

        if (!visited[v])
        {
            dfs2(v);
            printf("\n");
        }
    }
}

int main()
{
    int e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
            transpose[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    findSCC();

    return 0;
}

