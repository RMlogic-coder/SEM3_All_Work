#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
};

bool check(struct node *head)
{
    if (head == NULL)
    {
        return true;
    }

    struct node *slow = head;
    struct node *fast = head;
    bool flag = false;
    while (fast != NULL || slow != NULL)
    {
        if (slow == fast)
        {
            flag = true;
            return flag;
        }
        else
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return flag;
}
struct node *Insert(struct node **head, int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return *head;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *newNode = Insert(&head, 5);
    newNode = Insert(&head, 2);
    newNode = Insert(&head, 7);
    newNode->next = head;
    // display(head);

    if (check(head))
    {
        printf("True");
    }
    else
        printf("False");

    return 0;
}