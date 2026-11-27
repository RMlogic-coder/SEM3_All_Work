#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int waiting = 0;
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
// struct node *enqueue(struct node *front, struct node **rear, int data)
// {
//     struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
//     if (newNode == NULL)
//     {
//         printf("Malloc Error\n");
//         return front;
//     }
//     newNode->data = data;
//     newNode->next = NULL;

//     if (front == NULL)
//     {
//         front = newNode;
//         *rear = newNode;
//     }
//     else
//     {
//         (*rear)->next = newNode;
//         *rear = newNode;
//     }
//     return front;
// }
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
    // printf("\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
        waiting++;
    }

    // printf("NULL");
}

int main()
{
    int id = 1;
    int served = 0;
    int wait = 0;
    struct node *FV = NULL;
    struct node *RV = NULL;
    struct node *FR = NULL;
    struct node *FS = NULL;
    struct node *RR = NULL;
    struct node *RS = NULL;
    int t = 0;
    while (true)
    {
        int c;
        scanf("%d", &c);
        switch (c)
        {
        case 1:

            scanf("%d", &t);
            if (t == 1)
            {

                FR = enqueue(FR, &RR, id++);
            }
            else if (t == 2)
            {
                FV = enqueue(FV, &RV, id++);
            }
            else if (t == 3)
            {
                FS = enqueue(FS, &RS, id++);
            }
            else
                printf("Wrong input");
            printf("Customer Id: %d Added \n", id - 1);
            break;
        case 2:

            if (FV != NULL)
            {
                printf("Served : %d\n", dequeue(&FV));
                served++;
                waiting--;
                break;
            }
            if (served >= 2)
            {
                if (FS != NULL)
                {
                    printf("Served : %d\n", dequeue(&FS));
                    served++;
                    waiting--;
                    break;
                }
            }
            if (FR != NULL)
            {
                printf("Served : %d\n", dequeue(&FR));
                served++;
                waiting--;
                break;
            }

            break;
        case 3:
            printf("\nSenior Waiting Queue:\t");
            display(FS);
            printf("\nRegular :\t");
            display(FR);
            printf("\nVIP :\t");
            display(FV);
            printf("\nWaiting : %d", waiting);

            break;

        case 4:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}
