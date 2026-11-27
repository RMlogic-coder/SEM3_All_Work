#include <stdio.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void count(int *c)
{
    *c = *c + 1;
}
int partition(int *arr, int low, int high, int *c)
{

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            count(c);
            swap(arr, i, j);
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void quickSort(int *arr, int low, int high, int *c)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, c);
        quickSort(arr, low, pivotIndex - 1, c);
        quickSort(arr, pivotIndex + 1, high, c);
    }
}
int main()
{

    // int arr[] = {8, 4, 2, 1};
    int c = 0;
    int n;
    printf("Enter N");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // printf("Working");
    quickSort(arr, 0, n - 1, &c);

    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\nPair = %d\n", c);
    return 0;
}