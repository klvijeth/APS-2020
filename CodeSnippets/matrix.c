#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 200
#define iters 100
void matrix(int first[SIZE][SIZE],int second[SIZE][SIZE])
{
    int c,d,k,sum;
    int multiply[SIZE][SIZE];

for (c = 0; c < SIZE; c++) {
      for (d = 0; d < SIZE; d++) {
        for (k = 0; k < SIZE; k++) {
          sum = sum + (first[c][k]*second[k][d]);
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }
    }
int main()
{
	long long int a[SIZE][SIZE],b[SIZE][SIZE],i,pos,t,j;
	clock_t start,end;

	for(i = 0; i < SIZE; i++)
    	for(j= 0; j< SIZE; j++)
    	a[i][j] = rand() % 1000;

    for(i = 0; i < SIZE; i++)
    	for(j= 0; j< SIZE; j++)
    	b[i][j] = rand() % 1000;

	t = rand() % 1000;

    start = clock();

    for(i = 0; i < 1000; i++)
		matrix(a,b);

    end = clock();

    double time;

    time = end - start;
    time = (time / CLOCKS_PER_SEC) / 1000;

    printf("Time taken is %g seconds",time);

    return 0;
}

