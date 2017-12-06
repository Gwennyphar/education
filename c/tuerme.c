#include <stdio.h>

void hanoi (int, int, int);

int main ( void )
{
	hanoi(5 ,1 ,2);
	return 0;
}

void hanoi ( int n , int p1 , int p2 )
{
	int parkplatz ;
	if (n>1)
	{
		parkplatz = 6 - p1 - p2 ;
		hanoi (n -1 , p1 , parkplatz );
	}
	printf ("1 Scheibe von %d nach  %d \n ", p1, p2 );
	if ( n >1) hanoi (n -1 , parkplatz , p2 );
}
