#include<stdio.h>
#include<math.h>
int prime(long long int n)
{
    long long int i,flag=0;
    for(i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(n==2)
    {
        return 1;
    }
    if(flag==0)
        return 1;
    else
        return 0;

}
int main()
{
    long long int n,y,x,i;
    long long int num[55];
    long long int a=1,b=1,c,sum=0;
    scanf("%lld",&n);
    scanf("%lld",&x);
    scanf("%lld",&y);
    if(y>n)
        return 0;
    num[0]=0;
    num[1]=1;
    num[2]=1;
        for(i=3;i<55;i++)
        {
            c=a+b;
            a=b;
            b=c;
            num[i]=c;
        }
        for(i=0;i<=50;i++)
        {
            if(prime(num[i]))
                sum=sum+num[i];
        }
        printf("%lld\n",sum);
    return 0;

}
