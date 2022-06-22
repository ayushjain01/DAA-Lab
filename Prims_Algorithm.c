// 9. Find the minimum cost spanning tree of a given undirected graph
// using prim’s algorithm and give the trace of it.
#include <stdio.h>
int ne = 1, min_cost = 0;
void main()
{
    int i, j, n, min, cost[20][20], a, u, v, b, source, visited[20];
    printf("Enter the number of Vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("Enter the Root Vertex:\n");
    scanf("%d", &source);
    visited[source] = 1;
    printf("Minimum cost Spanning Tree is \n");
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                    if (visited[i] == 0)
                        continue;
                    else
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n edge %d \t (%d->%d) = %d \n", ne++, a, b, min);
            min_cost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n Minimum Cost = %d \n", min_cost);
}
