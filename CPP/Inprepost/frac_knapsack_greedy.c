#include <stdio.h>
#include <stdlib.h>
struct item
{
    int weight;
    int profit;
    float ratio;
};
int compare(const void *a, const void *b)
{
    struct item *x = (struct item *)a;
    struct item *y = (struct item *)b;

    if (x->ratio < y->ratio)
        return 1;
    if (x->ratio > y->ratio)
        return -1;
    return 0;
}
void display(struct item items[], int n)
{
    for (int i = 0; i < 3; i++)
    {
        printf("weight: %d\n", items[i].weight);
        printf("profit: %d\n", items[i].profit);
        // items[i].ratio = items[i].profit / items[i].weight;
        printf("ratio: %.2f\n", items[i].ratio);
        printf("----------------\n");
    }
    return;
}
int knapsack(struct item items[], int n, int capacity)
{
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            break;
        }
        else if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            profit += items[i].profit;
        }
        else
        {
            profit += items[i].ratio * capacity;
            capacity = 0;
        }
    }
    return profit;
}
int main()
{
    struct item items[] = {{3, 20, 0}, {4, 24, 0}, {5, 55, 0}};

    for (int i = 0; i < 3; i++)
    {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }
    display(items, 3);

    qsort(items, 3, sizeof(struct item), compare);
    printf("\n\n");
    display(items, 3);
    printf("\n\n Total Profit : %d", knapsack(items, 3, 10));
    return 0;
}