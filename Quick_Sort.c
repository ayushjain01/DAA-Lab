/*Consider a list of ‘n’ files numbered using ID’s. Write a C program to sort files based 
on its ID using Quick sort. Determine the time required sort the files. Plot a graph of 
number of IDs versus time taken. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int partition(int array[], int low, int high)
{
    int pivot = low, i = low, j = high, temp;
    while (i < j)
    {
        while (array[i] <= array[pivot] && i < high)
            i++;
        while (array[j] > array[pivot])
            j--;
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;
    return j;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n", arr[i]);
}

void main()
{
    clock_t start, end;
    double total;
    printf("Enter the number of files :");
    int i, h;
    int n;
    scanf("%d", &n);
    int arr[n];
    h = n - 1;
    int l = 0;
    for (i = 0; i <= n; i++)
    {
        arr[i] = rand();
    }
    printf("\nThe ID's of different files before sorting-\n");
    printArray(arr, n);
    start = clock();
    quickSort(arr, l, h);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    total = total * 1000;
    printf("\nThe ID's of different files after sorting:\n");
    printArray(arr, n);
    printf("\nTime Taken is %lf ms", total);
}
