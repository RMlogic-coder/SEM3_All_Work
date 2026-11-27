
#include <stdio.h>
#include <stdbool.h>
void display(char *arr)
{

    int i = 0;
    while (arr[i] != '\0')
    {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        char s[10005];
        char stack[10005];
        int last[26] = {0};
        bool isVisited[26] = {false};

        scanf("%d", &n);
        scanf("%s", s);

        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;

        int top = -1;

        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';

            if (isVisited[index])
                continue;

            while (top >= 0 &&
                   stack[top] > s[i] &&
                   last[stack[top] - 'a'] > i)
            {
                isVisited[stack[top] - 'a'] = false;
                top--;
            }

            stack[++top] = s[i];
            isVisited[index] = true;
        }

        stack[top + 1] = '\0';

        display(stack);
    }

    return 0;
}
