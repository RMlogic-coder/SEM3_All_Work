#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *enqueue(struct node *front, struct node **rear, int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    if (newNode == NULL)
    {
        printf("Malloc Error\n");
        return front;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    return front;
}
void display(struct node *top)
{
    while (top != NULL)
    {
        printf("%d, ", top->data);
        top = top->next;
    }
}

struct node *dequeue(struct node *front,
                     struct node **rear)
{
    if (front == NULL)
    {
        printf("Empty Queue\n");
        return NULL;
    }

    struct node *temp = front;

    printf("Removed: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
    {
        *rear = NULL;
    }

    free(temp);

    return front;
}

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    front = enqueue(front, &rear, 10);
    front = enqueue(front, &rear, 20);
    front = enqueue(front, &rear, 3210);
    front = dequeue(front, &rear);
    display(front);
    return 0;
}