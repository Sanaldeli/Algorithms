#include <stdio.h>
#include <stdlib.h>

// Finding the maximum value of an array using Divide & Conquer algorithm

int findMax(int arr[], int min, int max)
{
    int middle = (min + max) / 2;
    int maxLower, maxHigher;

    if (min >= max)
        return min;

    maxLower = findMax(arr, min, middle);
    maxHigher = findMax(arr, middle + 1, max);

    return arr[maxLower] > arr[maxHigher] ? maxLower : maxHigher;
}

int main()
{
    int arr[] = {20, 12, 3, 102, 6, 14, 30, 5, 2, 7, 8, 6, 101, 22, 25, 90};
    int max;
    int size = sizeof(arr) / sizeof(arr[0]) - 1;

    max = findMax(arr, 0, size);
    printf("Max value of the array is: %d", arr[max]);

    return 0;
}
