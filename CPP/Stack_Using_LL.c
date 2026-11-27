#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *top, int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return top;
    }
    newNode->data = data;
    if (top == NULL)
    {
        top = newNode;
        newNode->next = NULL;
        return top;
    }
    newNode->next = top;
    top = newNode;
    return top;
}
void display(struct node *top)
{
    while (top != NULL)
    {
        printf("%d, ", top->data);
        top = top->next;
    }
}
struct node *pop(struct node *top)
{
    if (top == NULL)
    {
        return top;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int peek(struct node *top)
{
    if (top == NULL)
    {
        return -1;
    }
    return top->data;
}
int main()
{
    struct node *top = NULL;

    // Push Operation
    top = push(top, 50);
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 550);

    display(top);

    top = pop(top);
    printf("\n");
    display(top);

    printf("\n%d", peek(top));
    return 0;
}