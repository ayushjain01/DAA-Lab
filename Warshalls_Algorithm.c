#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 50

int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}
void printMatrix(int arr[SIZE][SIZE], int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void getMatrix(int arr[SIZE][SIZE], int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            printf("Element [%d][%d] - ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}

void warshalls(int arr[SIZE][SIZE], int n)
{
    for (int k =0; k<n; k++)
    {
        for (int i =0; i<n; i++)
        {
            for (int j =0; j<n; j++)
            {
                    arr[i][j] = max(arr[i][j],(arr[i][k] && arr[k][j]));
            }
        }
        printMatrix(arr,n);
        printf("\n");
    }
}

void main()
{
    int n;
    clock_t start, end;
    double time;
    printf("Enter Matrix SIZE -");
    scanf("%d",&n);
    int arr[SIZE][SIZE];
    getMatrix(arr,n);
    printMatrix(arr,n);
    start = clock();
    warshalls(arr,n);
    end = clock();
    printMatrix(arr,n);
    time = (double) (end - start)/CLOCKS_PER_SEC;
    time = time * 1000;
    printf("Time Taken is %lf ms", time);
}
