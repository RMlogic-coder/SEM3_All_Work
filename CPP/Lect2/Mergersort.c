#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int l, int mid, int h)
{
    int b[h - l + 1];
    int i = l, j = mid + 1, n = h - l + 1, k = 0;
    while (i <= mid && j <= h)
    {
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
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
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
void mergesort(int *arr, int l, int h)
{
    int mid = (l + h) / 2;
    if (l < h)
    {
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main()
{

    return 0;
}
