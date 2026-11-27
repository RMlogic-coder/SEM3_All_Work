
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
char ifSt[MAX][MAX];
char pfSt[MAX][MAX];

int topInfix = -1;
int tPf = -1;

void pushInfix(char str[])
{
    strcpy(ifSt[++topInfix], str);
}
void pushPrefix(char str[])
{
    strcpy(pfSt[++tPf], str);
}
int main()
{
    char postfix[] = "ABC*+DE/-";

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];
        if (ch >= 'A' && ch <= 'E')
        {
            char temp[2];
            temp[0] = ch;
            temp[1] = '\0';

            pushInfix(temp);
            pushPrefix(temp);
        }
        else
        {

            char rI[MAX], li[MAX];
            char newInfix[MAX];
            strcpy(rI, ifSt[topInfix--]);
            strcpy(li, ifSt[topInfix--]);

            sprintf(newInfix, "(%s%c%s)",
                    li, ch, rI);
            pushInfix(newInfix);
            char rightPrefix[MAX], leftPrefix[MAX];
            char newPrefix[MAX];
            strcpy(rightPrefix, pfSt[tPf--]);
            strcpy(leftPrefix, pfSt[tPf--]);

            sprintf(newPrefix, "%c%s%s",
                    ch, leftPrefix, rightPrefix);

            pushPrefix(newPrefix);
        }
    }
    printf("Infix: %s\n", ifSt[topInfix]);
    printf("Prefix: %s\n", pfSt[tPf]);

    return 0;
}
