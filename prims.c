#include <stdio.h>

#define INF 999

int main()
{
    int cost[10][10];
    int visited[10] = {0};
    int n, i, j;
    int min, a, b;
    int ne = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = INF;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] != 0 && visited[j] == 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(min == INF)
        {
            printf("Graph is not connected!\n");
            return 0;
        }

        printf("%d -> %d = %d\n", a, b, min);

        mincost = mincost + min;
        visited[b] = 1;
        ne++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
