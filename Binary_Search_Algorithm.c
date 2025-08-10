#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    clock_t start, end;
    double cpu_time_used;

    int test_sizes[] = {1, 5, 10, 100, 1000};
    int i, j;

    printf("Binary Search Performance Analysis (Best, Worst, Average Cases)\n");
    printf("================================================================\n");

    for (i = 0; i < 5; i++)
    {
        int n = test_sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));

        for (j = 0; j < n; j++)
        {
            arr[j] = j * 2;
        }
        int k = arr[n / 2];
        start = clock();
        binarySearch(arr, n, k);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Array Size: %d | Best Case: %d | Time: %lf sec\n", n, k, cpu_time_used);

        k = -1;
        start = clock();
        binarySearch(arr, n, k);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Array Size: %d | Worst Case: %d | Time: %lf sec\n", n, k, cpu_time_used);

        k = arr[0];
        start = clock();
        binarySearch(arr, n, k);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Array Size: %d | Average Case: %d | Time: %lf sec\n", n, k, cpu_time_used);

        printf("----------------------------------------------------------------\n");

        free(arr);
    }
    return 0;
}