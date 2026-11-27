#include <stdio.h>
int s1[50];
int s2[50];
int t1 = -1;
int t2 = -1;

void pushs1(int data)
{
    if (t1 >= 4)
    {
        printf("Stack Full\n");
        return;
    }
    s1[++t1] = data;
}
void pushs2(int data)
{
    if (t2 >= 4)
    {
        printf("Stack Full\n");
        return;
    }
    s2[++t2] = data;
}
int pops1()
{
    if (t1 >= 0)
    {
        return s1[t1--];
    }
    else
    {
        printf("Empty Stack");
        return -1;
    }
}
int pops2()
{
    if (t2 >= 0)
    {
        return s2[t2--];
    }
    else
    {
        printf("Empty Stack");
        return -1;
    }
}

void enqueue(int data)
{
    if (t1 < 0)
    {
        pushs1(data);
    }
    else
    {
        while (t1 >= 0)
        {
            pushs2(pops1());
        }
        pushs1(data);
        while (t2 >= 0)
        {
            pushs1(pops2());
        }
    }
}
int dequeue()
{
    return pops1();
}

void display()
{
    printf("\n");
    for (int i = 0; i <= t1; i++)
    {
        printf("%d ", s1[i]);
    }
}

int main()
{
    enqueue(29);
    enqueue(29);
    enqueue(56);
    enqueue(576);
    enqueue(5);
    enqueue(59);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}