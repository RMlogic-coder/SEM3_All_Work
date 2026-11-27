#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node **top, int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = NULL;
    if (*top == NULL)
    {
        *top = newNode;
        return *top;
    }
    newNode->next = *top;
    *top = newNode;
    return *top;
};
int pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Empty Stack");
        return -1;
    }
    struct node *temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

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
int dequeue(struct node **front)
{
    if (front == NULL)
    {
        printf("Empty Queue");
        return -1;
    }
    int data = (*front)->data;
    *front = (*front)->next;
    return data;
}
void display(struct node *head)
{
    printf("\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct node *SP = NULL;
    struct node *front = NULL;
    struct node *rear = NULL;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d ", &data);
        SP = push(&SP, data);
    }
    display(SP);
    printf("\nPopped :\n");
    for (int i = 0; i < n; i++)
    {
        int data = pop(&SP);
        printf("%d ,", data);

        front = enqueue(front, &rear, data);
        // display(front);
    }
    // Dequeue
    struct node *newQF = NULL;
    struct node *newQR = NULL;
    for (int i = 0; i < n; i++)
    {
        int data = dequeue(&front);
        printf("%d ,", data);
        if (data % 2 == 0)
        {
            SP = push(&SP, data);
        }
        else
            newQF = enqueue(newQF, &newQR, data);

        // display(front);
    }
    printf("\n New Stack\n");
    display(SP);
    printf("\nnewQueue\n");
    display(newQF);

    return 0;
}