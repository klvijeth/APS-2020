#include<stdlib.h>
#include<stdio.h>
void merge(long long int a[], long long int l, long long int m, long long int r)
{
    int i, j, k;
    int x = m - l + 1;
    int y =  r - m;
    int L[x], R[y];
    for (i = 0; i < x; i++)
        L[i] = a[l + i];
    for (j = 0; j < y; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < x && j < y)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < x)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < y)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(long long int a[], long long int l, long long int h)
{
    if (l < h)
    {
        int m = l+(h-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, h);
        merge(a, l, m, h);
    }
}
int main()
{
    long long int n,k,z,v,y,t;
    scanf("%lld",&t);
    for(long long int j=0;j<t;j++)
    {
        scanf("%lld",&n);
        scanf("%lld",&k);
        long long int a[n];
        for(long long int i=0;i<n;i++)
        {
            scanf("%lld",&y);
            a[i]=(-1*y);
        }
        mergeSort(a, 0, n - 1);
        v=a[k-1];
        z=k;
        while(a[z]==v && z<n)
        {
           z++;
        }
        printf("%lld\n",z);
    }
    return 0;
}
