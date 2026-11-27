#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int length(struct node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

struct node *Insert(int data, struct node *head, int pos)
{

    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }
    struct node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp == NULL)
        {

            return head;
        }

        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void delete(struct node *head, int pos)
{
    struct node *temp1;
    if (pos == 0)
    {
        temp1 = head;
        head = head->next;
        free(temp1);
    }

    for (int i = 0; i < pos - 1; i++)
    {
        head = head->next;
    }
    temp1 = head;
    head = head->next;
    free(temp1);
}

void display(struct node *head)
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
    struct node *head = (struct node *)(malloc(sizeof(struct node)));
    head->data = 10;
    head->next = NULL;
    struct node *second = (struct node *)(malloc(sizeof(struct node)));
    struct node *third = (struct node *)(malloc(sizeof(struct node)));
    struct node *fourth = (struct node *)(malloc(sizeof(struct node)));

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    struct node *temp = head;

    for (int i = 5; head != NULL; i++)
    {
        head->data = i;
        head = head->next;
    }

    display(temp);
    struct node *temp1 = temp;

    int len = length(temp1);
    printf("\nLength :%d", len);

    // Insert at Start

    struct node *newHead = (struct node *)(malloc(sizeof(struct node *)));

    newHead->data = 1000;
    newHead->next = temp1;

    head = newHead;
    temp1 = newHead;
    display(newHead);

    // Insert at any position
    head = Insert(10, newHead, 2);
    display(head);

    // Insert at Last Pos
    // insertLast(newHead, 23);
    len = length(newHead);
    display(newHead);
    Insert(12, newHead, len);
    display(newHead);

    // Delete From start;
    temp1 = newHead;
    newHead = newHead->next;
    free(temp1);
    display(newHead);

    delete(newHead, 0);
    display(newHead);

    //

    return 0;
}