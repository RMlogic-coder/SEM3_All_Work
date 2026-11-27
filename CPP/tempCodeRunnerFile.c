#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void push(struct node *top, int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    if (top == NULL)
    {
        top = newNode;
    }
    newNode->next = top;
    top = newNode;
}
void display(struct node *top)
{
    while (top->next != NULL)
    {
        printf("%d, ", top->data);
    }
}
int main()
{
    struct node *top = NULL;

    // Push Operation
    push(top, 50);
    display(top);
    return 0;
}