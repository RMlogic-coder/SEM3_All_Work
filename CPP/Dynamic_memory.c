#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr = malloc(6 * sizeof(int));
    int *arr2 = arr;
    for (int i = 0; i < 6; i++)
    {
        arr[i] = i;
    }

    arr = realloc(arr, 7 * sizeof(int));

    int pos = 3;
    int a[] = {10, 20, 30, 40};

    int l1 = sizeof(arr) / sizeof(arr[0]);
    int length = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 7; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = a;

    for (int i = 0; i < 7; i++)
    {
        printf("%d,", arr2[i]);
    }

    return 0;
}