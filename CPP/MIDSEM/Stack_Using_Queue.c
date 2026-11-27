#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = 0;
int size = 0;

void enqueue(int data)
{
    if (size == MAX)
    {
        printf("Queue is full\n");
        return;
    }

    queue[rear] = data;
    rear = (rear + 1) % MAX;
    size++;
}

int dequeue()
{
    if (size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue[front];

    front = (front + 1) % MAX;
    size--;

    return data;
}

void push(int data)
{
    int n = size;

    enqueue(data);

    for (int i = 0; i < n; i++)
    {
        enqueue(dequeue());
    }
}

int pop()
{
    if (size == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return dequeue();
}

int peek()
{
    if (size == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return queue[front];
}

void display()
{
    if (size == 0)
    {
        printf("Stack is empty\n");
        return;
    }

    int index = front;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    push(1045);
    push(230);
    push(320);
    display();

    printf("Stack: ");
    display();

    printf("Popped: %d\n", pop());

    printf("Stack: ");
    display();

    printf("Top: %d\n", peek());

    return 0;
}