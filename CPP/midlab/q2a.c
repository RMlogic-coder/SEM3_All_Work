#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *oddeve(struct node *head)
{
    struct node *odd = head;
    struct node *evenhead = head->next;
    struct node *eve = head->next;

    while (eve != NULL && eve->next != NULL)
    {
        odd->next = eve->next;
        odd = odd->next;

        eve->next = odd->next;
        eve = eve->next;
    }
    odd->next = evenhead;

    return head;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        struct node *head = NULL;
        struct node *temp = NULL;
        int data;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);

            struct node *newNode = malloc(sizeof(struct node));
            newNode->data = data;
            newNode->next = NULL;

            if (head == NULL)
                head = newNode;
            else
                temp->next = newNode;

            temp = newNode;
        }
        display(head);
        head = oddeve(head);
        printf("\n");
        display(head);
    }

    return 0;
}
