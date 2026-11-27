#include <stdio.h>
#include <stdlib.h>
int search(int *arr, int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}
int seachSpace(int *arr, int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] > target && arr[i] < target && i != n - 1)
            return i + 1;
        else if (arr[0] > target)
        {
            return 0;
        }
        else if (i == n - 1)
            return n;
    }
    return -1;
}

void cancelseat(int *arr, int index, int n)
{
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr = realloc(arr, (n - 1) * sizeof(int));
}
void insertSeat(int *arr, int index, int n, int seat)
{
    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = seat;
}
void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter Size\n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // int isSorted = -1;
    // // bubble sort

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             int temp = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = temp;
    //         }
    //     }
    // }

    printarr(arr, n);

    // Cancel the Seat, ie Deletion from index;
    int cancel;
    printf("\nEnter seat for canceling");
    scanf("%d", &cancel);
    int index = search(arr, cancel, n);
    cancelseat(arr, index, n);
    n = n - 1;
    printf("\nAfter Cancellation");
    printarr(arr, n);

    // Emergency seat
    int insert;
    printf("\nEnter emergency seat");
    scanf("%d", &insert);
    index = seachSpace(arr, insert, n);
    insertSeat(arr, index, n, insert);
    n = n + 1;
    printf("\nAfter Insertion");
    printarr(arr, n);

    // Search;
    int seat;
    printf("\nEnter seat to search");
    scanf("%d", &seat);
    index = search(arr, seat, n);
    if (index == -1)
    {
        printf("\nSeat %d is not found", seat);
    }
    else
        printf("\nSeat %d found at position %d", seat, index + 1);

    return 0;
}