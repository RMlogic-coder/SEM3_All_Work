#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        int a[n];

        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        int left = 0;
        int maxKeep = 2;

        for (int right = 2; right < n; right++)
        {
            while (left + 1 < right &&
                   a[left] + a[left + 1] <= a[right])
            {
                left++;
            }

            int size = right - left + 1;

            if (size > maxKeep)
                maxKeep = size;
        }

        printf("%d\n", n - maxKeep);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* findNode(int id)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->id);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

void insertAfter(int x, int y)
{
    struct Node *X = findNode(x);

    if (X == NULL)
        return;

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->id = y;
    newNode->prev = X;
    newNode->next = X->next;

    if (X->next != NULL)
        X->next->prev = newNode;
    else
        tail = newNode;

    X->next = newNode;
}

void deleteNode(int x)
{
    struct Node *X = findNode(x);

    if (X == NULL)
        return;

    if (X->prev != NULL)
        X->prev->next = X->next;
    else
        head = X->next;

    if (X->next != NULL)
        X->next->prev = X->prev;
    else
        tail = X->prev;

    free(X);
}

void moveNode(int x, int y)
{
    struct Node *X = findNode(x);
    struct Node *Y = findNode(y);

    if (X == NULL || Y == NULL || X == Y)
        return;

    /* Detach X */
    if (X->prev != NULL)
        X->prev->next = X->next;
    else
        head = X->next;

    if (X->next != NULL)
        X->next->prev = X->prev;
    else
        tail = X->prev;

    /* Insert X before Y */
    X->prev = Y->prev;
    X->next = Y;

    if (Y->prev != NULL)
        Y->prev->next = X;
    else
        head = X;

    Y->prev = X;
}

void swapNodes(int x, int y)
{
    struct Node *X = findNode(x);
    struct Node *Y = findNode(y);

    if (X == NULL || Y == NULL || X == Y)
        return;

    /* X immediately before Y */
    if (X->next == Y)
    {
        struct Node *XP = X->prev;
        struct Node *YN = Y->next;

        if (XP != NULL)
            XP->next = Y;
        else
            head = Y;

        if (YN != NULL)
            YN->prev = X;
        else
            tail = X;

        Y->prev = XP;
        Y->next = X;
        X->prev = Y;
        X->next = YN;

        return;
    }

    /* Y immediately before X */
    if (Y->next == X)
    {
        swapNodes(y, x);
        return;
    }

    /* Non-adjacent nodes */
    struct Node *XP = X->prev;
    struct Node *XN = X->next;
    struct Node *YP = Y->prev;
    struct Node *YN = Y->next;

    if (XP != NULL)
        XP->next = Y;
    else
        head = Y;

    if (XN != NULL)
        XN->prev = Y;

    if (YP != NULL)
        YP->next = X;
    else
        head = X;

    if (YN != NULL)
        YN->prev = X;

    X->prev = YP;
    X->next = YN;
    Y->prev = XP;
    Y->next = XN;

    if (X->prev == NULL)
        head = X;

    if (Y->prev == NULL)
        head = Y;

    if (X->next == NULL)
        tail = X;

    if (Y->next == NULL)
        tail = Y;
}

void reverseSegment(int x, int y)
{
    struct Node *X = findNode(x);
    struct Node *Y = findNode(y);

    if (X == NULL || Y == NULL || X == Y)
        return;

    struct Node *start = NULL;
    struct Node *end = NULL;
    struct Node *temp = X;

    /* Check whether X comes before Y */
    while (temp != NULL)
    {
        if (temp == Y)
        {
            start = X;
            end = Y;
            break;
        }

        temp = temp->next;
    }

    /* Otherwise reverse Y to X */
    if (start == NULL)
    {
        start = Y;
        end = X;
    }

    struct Node *before = start->prev;
    struct Node *after = end->next;

    /* Reverse pointers */
    temp = start;

    while (temp != after)
    {
        struct Node *nextNode = temp->next;
        struct Node *swap = temp->prev;

        temp->prev = temp->next;
        temp->next = swap;

        temp = nextNode;
    }

    /* Connect left side */
    if (before != NULL)
        before->next = end;
    else
        head = end;

    /* Connect right side */
    if (after != NULL)
        after->prev = start;
    else
        tail = start;

    end->prev = before;
    start->next = after;
}

void freeTrain()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;
    tail = NULL;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);

        struct Node *newNode = malloc(sizeof(struct Node));

        newNode->id = id;
        newNode->prev = tail;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    int q;
    scanf("%d", &q);

    while (q--)
    {
        char command;
        int x, y;

        scanf(" %c", &command);

        if (command == 'I')
        {
            scanf("%d %d", &x, &y);
            insertAfter(x, y);
        }
        else if (command == 'D')
        {
            scanf("%d", &x);
            deleteNode(x);
        }
        else if (command == 'M')
        {
            scanf("%d %d", &x, &y);
            moveNode(x, y);
        }
        else if (command == 'S')
        {
            scanf("%d %d", &x, &y);
            swapNodes(x, y);
        }
        else if (command == 'R')
        {
            scanf("%d %d", &x, &y);
            reverseSegment(x, y);
        }

        display();
    }

    freeTrain();
    return 0;
}
