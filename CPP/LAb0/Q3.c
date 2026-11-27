#include <stdio.h>
void nearest(int *arr, int target, int n, int i)
{

    if ((arr[i + 1] - target) >= (target - arr[i - 1]) && (target < arr[n - 1] && arr[0] < target))
    {
        printf("p1");
        printf("Nearest available seat: %d, %d", arr[i - 1], i - 1);
    }
    else if (arr[0] > target)
    {
        printf("p2");
        printf("Nearest available seat: %d", arr[0]);
    }
    else if (arr[n] < target)
    {
        printf("p3");
        printf("Nearest available seat: %d", arr[n - 1]);
    }
    else
    {

        printf("p4");
        printf("Nearest available seat: %d, %d", arr[i + 1], i + 1);
    }
}
void binary_search(int *arr, int target, int n)
{
    int left = 0, right = n - 1;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            printf("Seat %d is available at %d", target, mid + 1);
            return;
        }
        else if (arr[mid] > target)
            right = mid - 1;
        else if (arr[mid] < target)
            left = mid + 1;
    }
    printf("\nMid : %d", mid);
    printf("\nSeat %d is not available.", target);
    nearest(arr, target, n, mid);
    return;
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
    int n = 5;
    int arr[5] = {10, 14, 18, 22, 26};
    printf("Available seats :\t");
    printarr(arr, n);

    int request;
    printf("\nEnter Request 1 \t");
    scanf("%d", &request);
    binary_search(arr, request, n);

    printf("\nEnter Request 2 \t");
    scanf("%d", &request);
    binary_search(arr, request, n);
    return 0;
}