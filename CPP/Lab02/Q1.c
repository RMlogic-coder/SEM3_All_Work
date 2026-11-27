#include <stdio.h>

int *search(int *arr, int n, int k)
{
    int l = 0;
    int r = n - 1;
    int idx[] = {-1, -1, -1};
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > k)
        {
            r = mid - 1;
        }
        if (arr[mid] < k)
        {
            l = mid + 1;
        }
        if (arr[mid] == k)
        {
            int freq = mid;
            while (arr[mid + 1] == k)
            {
                mid++;
            }
            while (arr[freq - 1] == k)
            {
                freq--;
            }
            // printf("S %d, E %d", freq, mid);
            idx[0] = freq;
            idx[1] = mid;
            return idx;
        }
    }
    idx[2] = l;
    return idx;
}

int main()
{
    printf("\nEnter n \n");
    int n;
    scanf("%d", &n);
    printf("\nEnter Elements \n");
    int arr[n];
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arr[j]);
    }
    printf("\nEnter Target \n");
    int k;
    scanf("%d", &k);

    int *index = search(arr, n, k);

    int ind[3] = {-1, -1, -1};
    for (int i = 0; i < 3; i++)
    {
        ind[i] = index[i];
    }

    // printf("\nIndex %d,%d,%d", ind[0], ind[1], ind[2]);
    if (ind[0] == -1)
    {
        printf("\nOccurrence: Not Found");
        printf("\nFirst Index %d", ind[0]);
        printf("\n Second Index %d", ind[1]);
        printf("\n Freq %d", 0);
        printf("\n Insert  Position %d", ind[2]);
        if (ind[2] == 0)
        {

            printf("\n Previous Score Nost Available");
        }
        else
            printf("\n Previous Score %d", arr[ind[2] - 1]);
        if (ind[2] == n)
        {

            printf("\n Next Score Nost Available");
        }

        else
            printf("\n Next Score %d", arr[ind[2]]);
    }
    if (ind[0] != -1)
    {
        printf("\n Occurrence: Found");
        printf("\n First Index %d", ind[0]);
        printf("\n Second Index %d", ind[1]);
        printf("\n Freq %d", ind[1] - ind[0] + 1);
        printf("\n Previous Score %d", arr[ind[0] - 1]);
        printf("\n Next Score %d", arr[ind[1] + 1]);
    }

    return 0;
}