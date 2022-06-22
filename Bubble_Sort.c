
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubble(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1-i; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j+!];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
        printf("\n");
    }
}
void main()
{
    double total_time;
    clock_t start, end;
    int i, j, min, n, temp = 0;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        int r;
        r = rand();
        arr[i] = r;
    }
    printf("Before sorting\n");
    print_array(arr, n);
    start = clock();
    bubble(arr, n);

    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("After sorting\n");
    print_array(arr, n);
    printf("\nTotal time taken is %lf", total_time);
}
