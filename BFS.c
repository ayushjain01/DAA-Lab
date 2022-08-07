#include <stdio.h>
void bfs(int v, int n, int a[n][n], int visited[n])
{
    int q[n], f = 0, r = -1;
    q[++r] = v;
    while (f <= r)
    {
        int u = q[f++];
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && a[u][i] == 1)
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
        printf("%d\n", u);
    }
}
void main()
{
    int v, n;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    int a[n][n], visited[n];
    printf("\n Enter adjacency matrix:\n");
    for (int i = 0; i < n; visited[i++] = 0)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    visited[v] = 1;
    printf("\n The node which are reachable are:\n");
    bfs(v, n, a, visited);
}