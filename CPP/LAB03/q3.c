#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DLLnode
{
    int stID;
    char name[20];
    struct DLLnode *next;
    struct DLLnode *prev;
};

int len(struct DLLnode *head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}
struct DLLnode *insert(struct DLLnode *head, int id, int pos, char name[20])
{
    struct DLLnode *temp = head;
    struct DLLnode *newNode = (struct DLLnode *)(malloc(sizeof(struct DLLnode)));
    newNode->stID = id;
    strcpy(newNode->name, name);

    if (pos == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return newNode;
    }

    for (int i = 0; i < pos; i++)
    {
        head = head->next;
    }
    newNode->next = head->next;
    head->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = head;
    return temp;
}
struct DLLnode *insertEnd(struct DLLnode *head, int id, char name[20])
{
    struct DLLnode *temp = head;
    struct DLLnode *newNode = (struct DLLnode *)(malloc(sizeof(struct DLLnode)));
    newNode->stID = id;
    strcpy(newNode->name, name);
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    newNode->prev = head;
    newNode->next = NULL;
    return temp;
}
struct DLLnode *delete(struct DLLnode *head, int pos)
{
    struct DLLnode *temp = head;
    if (pos == 0)
    {

        head = head->next;
        free(temp);
        return head;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        head = head->next;
    }
    temp = head->next;
    head->next = head->next->next;
    head->prev = head->prev->prev;
    free(temp);
    return head;
}
void DisplayF(struct DLLnode *head)
{

    while (head != NULL)
    {
        printf("\n%d,\t%s", head->stID, head->name);
        head = head->next;
    }
}

void DisplayB(struct DLLnode *head)
{

    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    while (head != NULL)
    {
        printf("\n%d,\t%s", head->stID, head->name);
        head = head->prev;
    }
}

int main()
{
    struct DLLnode *head = (struct DLLnode *)(malloc(sizeof(struct DLLnode)));

    head->next = NULL;
    head->prev = NULL;
    while (1)
    {
        printf("\nMenu\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Pos\n");
        printf("4. Display Forward\n");
        printf("5. Display Backward\n");
        printf("6. EXIT\n");
        printf("Enter Choice\n");
        int ch;
        int l;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter ID\n");
            int id;
            scanf("%d", &id);
            char name[20];
            printf("Enter Name\n");
            scanf("%s", name);
            head = insert(head, id, 0, name);
            DisplayF(head);
            break;
        case 2:
            l = len(head);
            printf("Enter ID\n");
            // int id;
            scanf("%d", &id);
            // char name[20];
            printf("Enter Name\n");
            scanf("%s", name);
            head = insertEnd(head, id, name);

            DisplayF(head);
            break;
        case 3:
            printf("Enter ID\n");
            // int id;
            scanf("%d", &id);
            // char name[20];
            printf("Enter Name\n");
            scanf("%s", name);
            printf("Enter Pos\n");
            int pos;
            scanf("%d", &pos);
            if (pos > len(head))
            {
                printf("Invalid Pos");
                break;
            }

            head = insert(head, id, pos, name);
            DisplayF(head);
            break;
        case 4:
            DisplayF(head);
            break;
        case 5:
            DisplayB(head);
            break;

        default:
            break;
        }
    }

    return 0;
}