#include <stdio.h>
#include <stdbool.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int k = 0; k < t; k++)
    {
        int n;
        char s[100];

        scanf("%d", &n);
        scanf("%s", s);

        if (s[0] != s[n - 1])
        {
            printf("yes\n");
            continue;
        }

        bool pos = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[0] != s[i] && s[i + 1] != s[n - 1])
            {
                pos = true;
                break;
            }
        }

        if (pos)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
