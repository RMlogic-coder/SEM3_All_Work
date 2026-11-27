#include <stdio.h>
#include <stdlib.h>
void display(int *arr, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
}

int *insert(int *arr, int pos, int data, int n)
{
    int i = 0;
    int *arr2 = (int *)(malloc((n + 1) * sizeof(int)));
    for (i = n + 1; i > pos; i--)
    {
        arr2[i] = arr[i - 1];
    }
    arr2[i] = data;
    for (i = pos - 1; i >= 0; i--)
    {
        arr2[i] = arr[i];
    }
    display(arr2, n + 1);
    return arr2;
}

int main()
{
    int *arr = (int *)(malloc(5 * sizeof(int)));
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 4;
    }
    display(arr, 5);
    arr = insert(arr, 2, 14, 5);
    arr = insert(arr, 0, 24, 6);
    arr = insert(arr, 7, 140, 7);
    return 0;
}