
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertBeginning(struct node *head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = data;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct node *last = head;

    while (last->next != head)
        last = last->next;

    newNode->next = head;
    last->next = newNode;

    return newNode;
}

struct node *insertEnd(struct node *head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = data;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct node *temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main(void)
{
    struct node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    display(head);

    head = insertBeginning(head, 5);
    display(head);

    return 0;
}
