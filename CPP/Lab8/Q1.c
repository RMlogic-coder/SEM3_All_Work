#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
int isEmpty()
{
    return top == -1;
}
int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
void itopost(char infix[], char postfix[], int r)
{
    top = -1;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (ch >= 'A' && ch <= 'H')
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (!isEmpty())
                pop();
        }
        else
        {
            while (!isEmpty() && stack[top] != '(')
            {

                int p1 = precedence(stack[top]);
                int p2 = precedence(ch);

                if (p1 > p2 ||
                    (!r && p1 == p2))
                {

                    postfix[j++] = pop();
                }
                else
                {
                    break;
                }
            }
            push(ch);
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void itopre(char infix[], char prefix[])
{
    char rev[MAX], temp[MAX];
    int len = strlen(infix);
    for (int i = 0; i < len; i++)
    {
        rev[i] = infix[len - 1 - i];
    }
    rev[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }
    itopost(rev, temp, 1);
    len = strlen(temp);
    for (int i = 0; i < len; i++)
    {
        prefix[i] = temp[len - 1 - i];
    }
    prefix[len] = '\0';
}
int main()
{
    char infix[] = "((A+B)*(C-D)+(E*F))/(G+H)";
    char postfix[MAX];
    char prefix[MAX];
    itopost(infix, postfix, 0);
    itopre(infix, prefix);
    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);
    return 0;
}
