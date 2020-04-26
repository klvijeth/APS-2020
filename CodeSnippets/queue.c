#include<stdio.h>
int main()
{
    long long t,n,m,l,k,i,j,u,x,v,w,count,min,count1,count2,vv,vj,vij,p;
    int flag;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        flag=0;
        x=0;
        u=0;
        j=0;
        scanf("%lld",&n);
        scanf("%lld",&m);
        scanf("%lld",&k);
        scanf("%lld",&l);
        long long a[n+12],b[n+12];
        while(j<n)
        {
            scanf("%lld",&a[j]);
            j++;
        }
        if((2*l)<k)
        {
         p=k/l;
         p=p*l;
        }
        else
            p=k;
        while((u*l)<k)
        {
            count=0;
            count1=0;
            count2=0;
            x=u*l;
            vv=k;
            for(v=0;v<n;v++)
            {
                if(a[v]<x)
                    count++;
                if(a[v]==x)
                    count1++;
                if(a[v]<=((u+1)*l) && a[v]>x )
                   {
                     vj=a[v]-x;
                     count2++;
                   }
                if(vj<vv)
                {
                    vv=vj;
                }
                if(a[v]>=p)
                    flag=1;
            }
            if(count1==0 && count2!=0)
            {
                if(count==0 && u>=m)
                    b[u]=l-vv;
                else
                {
                 if(u<m)
                    b[u]=((m-u)+count+1)*l;
                else
                    b[u]=(count+1-(u-m))*l;
                b[u]=b[u]-vv;
                }
            }
            else
                {
                    if(count==0 && u>=m)
                    b[u]=0;
                else
                {
                 if(u<m)
                        b[u]=((m-u)+count+1)*l;
                    else
                        b[u]=(count+1-(u-m))*l;
                }
                }
            u++;
        }
        if(flag==0 && p<=k)
        {
            b[u-1]-=(k-p);
        }
        min=b[0];
        vij=0;
        for(w=1;w<u;w++)
        {
            if(b[w]<min)
                {
                 min=b[w];
                 vij=w;
                }
        }
        printf("%lld\n",min);
    }
    return 0;
}
