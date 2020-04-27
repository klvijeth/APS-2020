#include<stdio.h>
#define MAX 10000
long long ch[MAX+1][MAX+1];
long long ncr(long long n,long long r)
{
	if(ch[n][r]==-1)
	ch[n][r] = ncr(n-1,r)+ncr(n-1,r-1);
	return ch[n][r];
}
long long get_ncr(long long n,long long r)
{
	long long i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			ch[i][j]=-1;
		}
	}

	for(i=1;i<=n;i++)
	{
		ch[i][0]=1;
		ch[i][i]=1;
	}
	return ncr(n,r);
}
int main()
{
    long long t,n,i,j,x,sum;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        x=1;
        sum=0;
        scanf("%lld",&n);
        long long a[n];
        for(j=0;j<n;j++)
            scanf("%lld",&a[j]);
        while(x<=n)
        {
            sum=sum+get_ncr(n,x);
            x+=2;
        }
        printf("%lld\n",sum);
    }
}
