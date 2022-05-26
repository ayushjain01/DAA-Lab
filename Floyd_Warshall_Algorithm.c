#include <stdio.h>

#define nV 4
#define INF 999

void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printMatrix(matrix);
}

int main()
{
    int graph[nV][nV];
    printf("\nENter DIstance Matrix -\n");
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            printf("\nGraph[%d][%d] - ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nDistance Matrix - \n");
    printMatrix(graph);
    printf("\nShortest path matrix - \n");
    floydWarshall(graph);
}
