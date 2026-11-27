#include <stdio.h>
#include <stdlib.h>
// int *selection(int *arr)
// {
//     int *ar = arr;
//     // int n = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }
//     return ar;
// }

int *bubble(int *arr)
{
    int *ar = arr;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return ar;
}

int *insert(int *arr, int pos, int data, int n)
{
    int *ar = arr;

    arr = realloc(arr, (n + 1) * sizeof(int));
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = data;
    return ar;
}

// int *delete(int *arr, int pos)
// {
// }
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    // Sort:
    int n;
    scanf("Enter size%d", &n);
    int *a = malloc(n * sizeof(int));

    // a = {34, 5, 83, 56, 23, 311, 45, 32, 12, 43};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // bubble sort

    int *arr = insert(a, 2, 69, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d,", a[i]);
    }

    return 0;
}