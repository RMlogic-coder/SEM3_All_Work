#include <stdio.h>
int c(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j] && i < j)
            {
                count++;
            }
        }
    }
    return count;
}
void merge(int *arr, int l, int mid, int h, int *count)
{
    int b[h - l + 1];
    int i = l, j = mid + 1, n = h - l + 1, k = 0;
    while (i <= mid && j <= h)
    {
        if (arr[i] > arr[j] && i < j)
        {

            *count = *count + 1;
        }

        *count = *count + 1;
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
            // *count = *count + 1;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
        // *count = *count + 1;
    }
    while (j <= h)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    for (int x = 0; x < n; x++)
    {
        arr[l + x] = b[x];
    }
}
void mergesort(int *arr, int l, int h, int *count)
{
    int mid = (l + h) / 2;
    if (l < h)
    {
        mergesort(arr, l, mid, count);
        mergesort(arr, mid + 1, h, count);
        merge(arr, l, mid, h, count);
    }
}
int main()
{
    int n;
    scanf("%d\n", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count = c(arr, n);
    int af;
    mergesort(arr, 0, n - 1, &af);
    for (int x = 0; x < n; x++)
    {
        printf("%d,", arr[x]);
    }
    printf("\n Total Inverions = %d", count);
    return 0;
}