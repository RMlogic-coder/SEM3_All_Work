#include <stdio.h>
#include <stdlib.h>

int top = -1;
void push(int *arr, int data)
{
    if (top == 99)
    {
        printf("Stack is Full");
        return;
    }
    else
    {
        arr[top++] = data;
    }
}
int pop(int *arr)
{
    if (top == -1)
    {
        printf("Stack is Already Empty");
        return -1;
    }
    else
        return arr[top--];
}

int peek(int *arr)
{
    int data = arr[top - 1];
    return data;
}

void display(int *arr)
{
    int runs = 0;
    int boundary_events = 0;
    int Wickets = 0;
    for (int i = 0; i <= top; i++)
    {
        if (arr[i] >= 4)
        {
            runs += arr[i];
            boundary_events++;
        }
        if (arr[i] == 0)
        {
            Wickets += 1;
        }
        runs += arr[i];
    }

    printf("runs %d\nBoundary %d\n Wickets %d\n", runs, boundary_events, Wickets);
}
int main()
{
    int *arr = (int *)(malloc(100 * sizeof(int)));
    char event_name[8][26] = {{"SINGLE"}, {"DOUBLE"}, {"Triple"}, {"Four"}, {"Six"}, {"No_Ball"}, {"Wide"}, {"Wicket"}};
    // printf("%s\n", events[0]);
    int series[100];
    int k = 0;
    // Menu
    while (1)
    {

        printf("Menu\n");
        printf("1. Add event\n");
        printf("2. UNDO\n");
        printf("3. TOP\n");
        printf("4. DISPLAY\n");
        printf("5. SCORE\n");
        printf("6. EXIT\n");

        printf("PLEASE ENTER CHOICE\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Event Menu\n");
            printf("1. Single\n");
            printf("2. Double\n");
            printf("3. Triple\n");
            printf("4. Four\n");
            printf("5. Six\n");
            printf("6. No_Ball\n");
            printf("7. Wide\n");
            printf("8. Wicket\n");

            int event;
            printf("Enter Event\n");
            scanf("%d", &event);
            series[k] = event;
            k++;
            switch (event)
            {
            case 1:
                push(arr, 1);
                break;
            case 2:
                push(arr, 2);
                break;
            case 3:
                push(arr, 3);
                break;
            case 4:
                push(arr, 4);
                break;
            case 5:
                push(arr, 6);
                break;
            case 6:
                break;
            case 7:
                push(arr, 1);
                break;
            case 8:
                push(arr, 0);
                break;
            default:
                break;
            }
            break;
        case 2:
            pop(arr);
            break;
        case 3:
            printf("\n%d", peek(arr));
            break;
        case 4:
            for (int i = 0; i < k; i++)
            {
                printf("%s\n", event_name[series[i] - 1]);
            }
            break;
        case 5:
            display(arr);
            break;
        case 6:
            break;

        default:
            break;
        }
    }
    return 0;
}