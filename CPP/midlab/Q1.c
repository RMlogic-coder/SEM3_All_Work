#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        int l = 0;
        int max = 2;

        for (int r = 2; r < n; r++)
        {
            if (l + 1 < r && arr[l] + arr[l + 1] <= arr[r])
            {
                l++;
            }
            int size = r - l + 1;
            if (size > max)
            {
                max = size;
            }
        }
        printf("Min Replacement = %d\n", (n - max));
    }

    return 0;
}