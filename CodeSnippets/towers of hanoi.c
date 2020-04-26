#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void toh(int n,char from,char to,char aux)
{
    if(n==1)
        Sleep(1);
    toh(n-1,from,aux,to);
     Sleep(1);
    toh(n-1,aux,to,from);

}
int main()
{
	int n=3;
	char a='A',b='B',c='C';
    start = clock();

		toh(a);

    end = clock();

    double time;

    time = end - start;
    time = (time / CLOCKS_PER_SEC) / 1000;

    printf("Time taken is %g seconds",time);

    return 0;
}

