#include <stdio.h>
#include <conio.h>
int gcd( int n , int m )
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
	int a , b ;
	//clrscr();

	printf( "Enter two integers\n" ) ;
	scanf( "%d" , &a ) ;
	scanf( "%d" , &b ) ;

	if(gcd(a,b))
	{
		printf("The numbers are co primes");
	}
	else
	{
		printf("The numbers are not co primes");
	}
	return 0 ;
}
