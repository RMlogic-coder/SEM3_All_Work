#include <stdio.h>
#include <stdlib.h>
struct dllNode
{
    int data;
    struct dllNode *next;
    struct dllNode *prev;
};
void display(struct dllNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void rotate(struct dllNode *head)
{
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        struct dllNode *head = NULL;
        struct dllNode *temp = NULL;
        int data;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);

            struct dllNode *newNode = malloc(sizeof(struct dllNode));
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;

            if (head == NULL)
                head = newNode;
            else
            {
                temp->next = newNode;
                newNode->prev = temp;
            }
            temp = newNode;
        }
        printf("\nBefore Rotation\n");
        display(head);

        int r;
        scanf("%d", &r);

        if (r > n)
        {
            r = r % n;
        }

        printf("\nAfter  Rotation\n");

        temp = head;
        for (int i = 0; i < r; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return 0;
        }

        temp->prev->next = NULL;
        temp->prev = NULL;
        struct dllNode *newHead = temp;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        display(newHead);
    }

    return 0;
}