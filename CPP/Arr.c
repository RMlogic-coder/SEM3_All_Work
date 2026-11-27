#include <stdio.h>
int main()
{
    int arr[5] = {10, 3, 5, 1, -1};
    int pos = 3;
    int a = 13;
    for (int i = 5; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = a;

    for (int i = 0; i < 6; i++)
    {
        printf("%d,", arr[i]);
    }

    int *posa = &arr[1];
    // int *posb = &arr[-2];

    printf("%d", *posa);
    // printf("%d", arr[-2]);

    return 0;
}