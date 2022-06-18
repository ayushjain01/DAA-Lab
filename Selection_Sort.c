#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("After sorting\n");
    print_array(arr, n);
    printf("\nTotal time taken is %lf", total_time);
}
