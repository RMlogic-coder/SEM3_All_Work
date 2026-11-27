#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
}
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}
void heapsort(int *arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    printf("\nDiplaying Max heap \n");
    display(arr, n);
    printf("\n");
    printf("\nDiplaying After Iterations \n");
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        if (i == n - 1 || i == n - 2)
        {

            display(arr, n);
            printf("\n");
        }
    }
}

int main()
{
    printf("\nEnter n \n");
    int n;
    scanf("%d", &n);

    printf("\nEnter Elements \n");
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    heapsort(arr2, n);
    printf("\nSorted Arr: ");
    display(arr2, n);

    return 0;
}
