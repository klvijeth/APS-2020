#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 100000
#define ITERS 10000
void linear_search(int n,long long a[])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(a[i]==n)
            return;
    }
}
int main()
{
    int i;
    clock_t start,end;
    double t;
    long long a[SIZE];
    for(i=0;i<SIZE;i++)
    {
        a[i]= rand() % 1000;

    }
    start=clock();

    for(i=0;i<1000;i++)
        linear_search(a[SIZE-1],a);

    end=clock();
    t=(end-start);
    t=(t/CLOCKS_PER_SEC)/ITERS;

    printf("time taken is %g ",t);
    return 0;
}
