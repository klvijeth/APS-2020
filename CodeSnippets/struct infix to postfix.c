#include<stdio.h>
struct stack
{
int top;
char st[20];
};
typedef struct stack STACK;
STACK s;

void push(char x)
{
    s.st[++s.top] = x;
//    printf("\npushing %c\n",x);
}

char pop()
{
//    printf("\nPoping %c\n",stack[top]);
    if(s.top == -1)
        return -1;
    else
        return s.st[s.top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

main()
{
    s.top=-1;
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(s.st[s.top]) >= priority(*e))
                {
                    printf("%c",pop());
                }
            push(*e);
        }
        e++;
    }
    while(s.top != -1)
    {
        printf("%c",pop());
    }
}
