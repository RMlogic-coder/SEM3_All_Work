#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void display(struct Node *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("%d,", head->data);
        head = head->next;
    }
}

struct Node *rev(struct Node *head)
{
    struct Node *temp = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in original list
        current = current->prev;
    }

    // temp points to the old previous node
    if (temp != NULL)
        head = temp->prev;

    return head;
}
int main()
{
    struct Node *head = (struct Node *)(malloc(sizeof(struct Node)));
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;
    struct Node *second = (struct Node *)(malloc(sizeof(struct Node)));
    second->data = 20;
    head->next = second;
    second->prev = head;

    display(head);

    head = rev(head);
    display(head);

    return 0;
}