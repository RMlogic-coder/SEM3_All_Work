#include <stdio.h>
#include <stdlib.h>
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
    int isSorted = -1;
    // bubble sort

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted += 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    if (isSorted != -1)
    {
        printf("\nArray was not in decreasing order initially.");
    }
    else
        printf("\nArray was already in decreasing order.");

    return 0;
}