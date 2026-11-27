#include <stdio.h>
#include <stdlib.h>
struct DLLnode
{
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
};
struct DLLnode *insert(struct DLLnode *head, int pos, int data)
{

    struct DLLnode *temp = head;
    struct DLLnode *newNode;
    newNode = (struct DLLnode *)(malloc(sizeof(struct DLLnode)));

    newNode->data = data;

    if (pos == 0)
    {
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
            head->prev = newNode;

        return newNode;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        head = head->next;
    }
    newNode->next = head->next;
    newNode->prev = head;
    head->next = newNode;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;

    return temp;
}

int length(struct DLLnode *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// struct DLLnode *delete(struct DLLnode *head, int pos)
// {
//     struct DLLnode *temp;
//     struct DLLnode *trackhead = head;
//     if (pos == 0)
//     {
//         temp = head;
//         head = head->next;
//         free(temp);
//         return head;
//     }
//     for (int i = 0; i < pos; i++)
//     {
//         head = head->next;
//     }
//     temp = head;
//     head = head->next->next;
//     head->prev = head->prev->prev;
//     free(temp);
//     return trackhead;
// }

struct DLLnode *delete(struct DLLnode *head, int pos)
{
    if (head == NULL)
        return NULL;
    if (pos == 0)
    {
        struct DLLnode *temp = head;

        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    struct DLLnode *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        if (temp->next == NULL)
            return head;

        temp = temp->next;
    }
    struct DLLnode *toDelete = temp->next;

    if (toDelete == NULL)
        return head;

    temp->next = toDelete->next;

    if (toDelete->next != NULL)
        toDelete->next->prev = temp;
    free(toDelete);

    return head;
}

void display(struct DLLnode *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("%d,", head->data);
        head = head->next;
    }
}

int main()
{
    struct DLLnode *head;
    head = (struct DLLnode *)(malloc(sizeof(struct DLLnode)));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;
    struct DLLnode *second;
    second = (struct DLLnode *)(malloc(sizeof(struct DLLnode)));
    head->next = second;
    second->prev = head;
    second->data = 20;

    head = insert(head, 2, 30);
    // head = insert(head, 49, 3);

    display(head);

    return 0;
}