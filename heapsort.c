
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

void heapify(int h[], int n)
{
    int i, j, n1, k, heap, v;
    n1 = n;
    heap = 0;
    for (i = n1 / 2; i >= 1; i--)
    {
        k = i;
        v = h[k];
        heap = 0;
        while (!(heap) && (2 * k) <= n1)
        {
            j = 2 * k;
            if (j <= n1)
                if (h[j] < h[j + 1])
                    j = j + 1;

            if (v >= h[j])
                heap = 1;

            else
            {
                h[k] = h[j];
                k = j;
            }
            h[k] = v;
        }
    }
}

void main()
{
    int n, t, size, i;
    int h[50];
    double total_time;
    clock_t start, end;
    printf("How many Numbers you want to enter in your array: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int r;
        r = rand();
        h[i] = r;
    }
    printf("Before sorting\n");
    print_array(h, n);

    start = clock();

    heapify(h, n);
    printf("\nElements Heapified : ");
    print_array(h, n);

    for (i = n; i >= 1; i--)
    {

        t = h[1];
        h[1] = h[i];
        h[i] = t;
        size = i - 1;
        heapify(h, size);
    }
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("After sorting\n");
    print_array(h, n);
    printf("\nTotal time taken is %lf", total_time);
}