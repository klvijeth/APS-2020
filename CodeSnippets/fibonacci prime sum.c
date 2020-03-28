#include<stdio.h>
#include<math.h>
int prime(long int n)
{
    long int i,flag=0;
    for(i=2;i<sqrt(n);i++)
    {
        if((n%i)==0)
        {
            flag==1;
            break;
        }
    }
    if(flag==0)
        return 1;
    else
        return 0;

}
int main()
{
    int n;
    long int a=1,b=1,c,sum=0;
    scanf("%d",&n);
    if(n<4)
        printf("0\n");
    else
    {
        for(int i=0;i<(n-4);i++)
        {s
            c=a+b;
            a=b;
            b=c;
            if(prime(c))
                sum+=c;
        }
        printf("%ld\n",sum);
    }
    return 0;

}
