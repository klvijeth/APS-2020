#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int sum=0;

char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
//    printf("\npushing %c\n",x);
}

char pop()
{
//    printf("\nPoping %c\n",stack[top]);
    if(top == -1)
        return -1;
    else
        return stack[top--];
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
int post_eval(char *exp)
{
        char *e;
        int n1,n2,n3,num;
        e = exp;
        while(*e != '\0')
        {
                if(isdigit(*e))
                {
                        num = *e - 48;
                        push(num);
                }
                else
                {
                        n1 = pop();
                        n2 = pop();
                        switch(*e)
                        {
                                case '+':
                                {
                                        n3 = n1 + n2;
                                break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                        }
                        push(n3);
                }
                e++;
        }
        return pop();
}
void in_topost(char *exp)
{
    char *e, x,u=0;
    int i=0;
    char a[100];
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            a[i++]=*e;
        else
        {
            while(priority(stack[top]) >= priority(*e))
                a[i++]=pop();
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        a[i++]=pop();
    }
    a[i]='\0';
    sum=sum+post_eval(a);
}

void binary(int temp,int n,int *a)
{
    int j=0,x;
    x=n-1;
    int k;
    k=pow(2,x);
    int rem;
    for(int i=0;i<x;i++)
    {
        rem=temp%2;
        temp=temp/2;
        a[j++]=rem;
    }
}

int main()
{
    int i=0,x=0,y,u=1,n=3,z=0,q=1,v;
    //scanf("%d",&n);
    int p;
    int k;
    int a[100];
    char b[100];
    //printf("%d",n);
    k=pow(2,(n-1));
      while(z<(2*n-1))
    {
        scanf("%c",&b[z]);
        z=z+1;
    }
    while(q<(2*n-2))
    {
        b[q]='.';
        q=q+2;
    }
    b[2*n-1]='\0';
    for(int i=0;i<k;i++)
    {
        u=1;
        binary(i,n,a);
        y=0;
        for(y=0;y<(n-1);y++)
        {
            if(a[y]==0)
            {
                b[u]='+';
        }
            else
            {
                b[u]='*';
            }
            u=u+2;
        }
        in_topost(b);
    }
    printf("%d",sum);
}
    //for(temp=0;temp<k;temp++)
    //{
