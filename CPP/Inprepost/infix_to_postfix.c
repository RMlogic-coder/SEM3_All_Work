
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Character stack
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

char peek()
{
    return stack[top];
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

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[],
                    int reversed)
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

            while (!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (!isEmpty())
                pop();
        }

        else
        {
            while (!isEmpty() && peek() != '(')
            {

                int p1 = precedence(peek());
                int p2 = precedence(ch);

                if (p1 > p2 ||
                    (!reversed && p1 == p2))
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

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[])
{

    char rev[MAX], temp[MAX];

    int len = strlen(infix);

    // Reverse infix
    for (int i = 0; i < len; i++)
    {
        rev[i] = infix[len - 1 - i];
    }
    rev[len] = '\0';

    // Swap brackets
    for (int i = 0; i < len; i++)
    {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }

    // Convert reversed expression to postfix
    infixToPostfix(rev, temp, 1);

    // Reverse postfix to get prefix
    len = strlen(temp);

    for (int i = 0; i < len; i++)
    {
        prefix[i] = temp[len - 1 - i];
    }

    prefix[len] = '\0';
}

// Integer stack for evaluation
long long evalStack[MAX];
int evalTop = -1;

void evalPush(long long value)
{
    evalStack[++evalTop] = value;
}

long long evalPop()
{
    return evalStack[evalTop--];
}

// Evaluate Postfix

int main()
{

    int A, B, C, D, E, F, G, H;

    scanf("%d %d %d %d %d %d %d %d",
          &A, &B, &C, &D, &E, &F, &G, &H);

    int values[8] = {A, B, C, D, E, F, G, H};

    char infix[] = "((A+B)*(C-D)+(E*F))/(G+H)";

    char postfix[MAX];
    char prefix[MAX];

    infixToPostfix(infix, postfix, 0);

    infixToPrefix(infix, prefix);

    long long totalExpense =
        evaluatePostfix(postfix, values);

    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);
    printf("Total Trip Expense: %lld\n", totalExpense);

    return 0;
}
