#include<stdio.h>
#include<stdlib.h>
struct graph
{
    long long index;
    long long num;
};
int coprime( long long n , long long m )
{
	if( n == 0 || m == 0 )
		return 0 ;

	if( n < 0 )
		n = - n ;
	if( m < 0 )
		m = - m ;
	while( 1 )
		if( n > m )
			n -= m ;
		else if ( n < m )
			m -= n ;
		else
			break ;
    if(n==1)
	 return 1 ;
	else
     return 0;
}
int main()
{
    long long tr,hi=0;
    long long n,prime,x,count1;
    struct graph a[52];
    struct graph b[52];
    scanf("%lld",&tr);
   while(hi<tr)
    {
        x=0;
        scanf("%lld",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[j].num);
            a[j].index=0;
        }
        int primes[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
        for(int k=0;k<n-1;k++)
        {
            prime=0;
                for(int l=k+1;l<n;l++)
                {
                    if(coprime(a[k].num,a[l].num))
                    {
                        //printf("hello\n");
                        prime++;
                        a[l].index=1;
                    }
                }
                if(a[k].index==0)
            {
                if(prime==0)
                {
                  b[x].num=a[k].num;
                b[x].index=k;
                x++;
                }
            }
        }
        if(a[n-1].index!=1)
        {
            b[x].num=a[n-1].num;
                b[x].index=n-1;
                x++;
        }
        if(x!=0)
        {
         for(int y=0;y<15;y++)
         {
            //printf("%d\n",b[y].num);
            count1=0;
            for(int z=0;z<x;z++)
            {
                if((b[z].num%primes[y])==0)
                {
                    count1++;
                }
            }
             if(count1==0)
                {
                    a[b[0].index].num=primes[y];
                    printf("1\n");
                    for(int q=0;q<n;q++)
                    printf("%d ",a[q].num);
                    printf("\n");
                    goto c;
                }
         }
        }
        else
        {
            printf("0\n");
            for(int j=0;j<n;j++)
            printf("%d ",a[j].num);
            printf("\n");

        }
        c:
           hi++;
    }
    return 0;
}
