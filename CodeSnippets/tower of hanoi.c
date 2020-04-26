#include <stdio.h>
#include <stdlib.h>

void towers(int, char, char, char);

int main()
{
    int n;
    printf("Enter the number of Disks to be moved\n");
    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');
    return 0;
}

void towers(int n, char from, char to, char aux)
{
    if( n==1)
    {
        printf("Move disk 1 from %c to %c\n",from, to);
        return;
    }
    towers(n-1,from,aux,to);
    printf("Move disk %d from %c to %c\n",n,from, to);
    towers(n-1,aux,to,from);

}     // Move top n-1 disks from A to B using C as auxiliary     towers(n-1, from, aux, to);

    // Move remaining disk from A to C     printf("Move disk %d from %c to %c\n", n, from, to);

    // Move n-1 disks from B to C using A as auxiliary     towers(n-1, aux, to, from); }





