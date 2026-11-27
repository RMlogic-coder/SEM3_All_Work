
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack for storing expressions
char infixStack[MAX][MAX];
char prefixStack[MAX][MAX];

int topInfix = -1;
int topPrefix = -1;

// Stack for evaluating values
long long evalStack[MAX];
int topEval = -1;

// Push into infix stack
void pushInfix(char str[])
{
    strcpy(infixStack[++topInfix], str);
}

// Push into prefix stack
void pushPrefix(char str[])
{
    strcpy(prefixStack[++topPrefix], str);
}

// Push into evaluation stack
void pushEval(long long value)
{
    evalStack[++topEval] = value;
}

long long popEval()
{
    return evalStack[topEval--];
}

int main()
{

    int A, B, C, D, E;

    scanf("%d %d %d %d %d",
          &A, &B, &C, &D, &E);

    int values[5] = {A, B, C, D, E};

    char postfix[] = "ABC*+DE/-";

    for (int i = 0; postfix[i] != '\0'; i++)
    {

        char ch = postfix[i];

        // If operand
        if (ch >= 'A' && ch <= 'E')
        {

            char temp[2];
            temp[0] = ch;
            temp[1] = '\0';

            pushInfix(temp);
            pushPrefix(temp);

            pushEval(values[ch - 'A']);
        }

        // If operator
        else
        {

            // Get right and left infix expressions
            char rightInfix[MAX], leftInfix[MAX];
            char newInfix[MAX];

            strcpy(rightInfix, infixStack[topInfix--]);
            strcpy(leftInfix, infixStack[topInfix--]);

            sprintf(newInfix, "(%s%c%s)",
                    leftInfix, ch, rightInfix);

            pushInfix(newInfix);

            // Get right and left prefix expressions
            char rightPrefix[MAX], leftPrefix[MAX];
            char newPrefix[MAX];

            strcpy(rightPrefix, prefixStack[topPrefix--]);
            strcpy(leftPrefix, prefixStack[topPrefix--]);

            sprintf(newPrefix, "%c%s%s",
                    ch, leftPrefix, rightPrefix);

            pushPrefix(newPrefix);

            // Evaluate postfix expression
            long long b = popEval();
            long long a = popEval();

            long long result = 0;

            switch (ch)
            {

            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                result = a / b;
                break;
            }

            pushEval(result);
        }
    }

    printf("Infix: %s\n", infixStack[topInfix]);
    printf("Prefix: %s\n", prefixStack[topPrefix]);
    printf("Result: %lld\n", evalStack[topEval]);

    return 0;
}
