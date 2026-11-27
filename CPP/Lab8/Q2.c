#include <stdio.h>
int s[10] = {-1};
int si = 0;
int max(int a, int b)
{
    if (a > b)
    {
        printf("A: %d\n", a);
        return a;
    }
    else
    {
        printf("B: %d\n", b);
        return b;
    }
}
struct player
{
    char name[10];
    int cost;
    int score;
};
int knapsack(int W, struct player p[], int n)
{

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {

            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            else if (p[i - 1].cost <= w)
            {

                dp[i][w] = max(p[i - 1].score + dp[i - 1][w - p[i - 1].cost], dp[i - 1][w]);
                s[si++] = i - 1;
            }

            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    int cost[n];
    int score[n];
    char name[n][50];
    struct player p[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].cost, &p[i].score);
        // name[i] = (char)(i + 65);
    }

    printf("Maximum Score = %d", knapsack(c, p, n));
    printf("Total cost = %d", c);
    printf("Total Score = %d", knapsack(c, p, n));

    // for (int i = 0; i < 10; i++)
    // {
    //     if (s[i] == -1)
    //     {
    //         continue;
    //     }
    //     else
    //     {

    //         printf("%d\t", s[i]);
    //         printf("%s\t", p[s[i]].name);
    //         s[i] = -1;
    //     }
    // }

    return 0;
}
