#include<stdio.h>
#include<math.h>
void binary(int temp,int n,int *a)
{
    int j=0;
    int k;
    k=pow(2,(n-1));
    int rem;
    for(int i=0;i<(n-1);i++)
    {
        rem=temp%2;
        temp=temp/2;
        a[j++]=rem;
    }
}

main()
{
    int n,i;
    printf("\n Enter the number:");
    scanf("%d",&n);
    int rem;
    int temp;
    int k;
    int a[100];
    int b[100];
    int sum=0;
    k=pow(2,(n-1));
    printf("\n Enter the array");
    for(int i=0;i<n;i++)
    scanf("%d",&b[i]);
    for(int i=0;i<k;i++)
    {
        binary(i,n,a);
        for(int j=0;j<n-1;j++)
        {
            switch(a[j])
            {
            case 1:
            sum=sum*b[j];
             break;
            case 0:
            sum+=b[j];
             break;
            }
        }
    }
    printf("\n Sum=%d",sum);
}
    //for(temp=0;temp<k;temp++)
    //{
