#include <stdio.h>
int top = -1;
int n = 5;
int isFul(int *arr)
{
    if (top == n - 1)
        return 1;
    else
        return 0;
}
int isEmpty(int *arr)
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int *arr, int element)
{
    if (isFul(arr))
    {
        printf("Stack is Already Full");
    }
    else
    {
        printf("Pushed Sucessfully");
        arr[top++] = element;
    }
}
int pop(int *arr)
{
    if (isEmpty(arr))
    {
        printf("Empty Stack");
    }
    else
    {
        top--;
        return arr[top];
    }
}
int peek(int *arr)
{
    return arr[top - 1];
}

int main()
{
    int arr[5];
    push(arr, 65);
    push(arr, 45);
    push(arr, 654);
    push(arr, 675);
    printf("\nPeek %d", peek(arr));
    printf("\nPop %d", pop(arr));
    printf("\nPop %d", pop(arr));
    return 0;
}